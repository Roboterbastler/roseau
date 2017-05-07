#include <MotorController.h>

#include <backbone_bridge/BackboneRead.h>
#include <backbone_bridge/BackboneWrite.h>

MotorController::MotorController(ros::NodeHandle &nh)
  : mNodeHandle_(nh),
    mDesiredMotorRpm_(0),
	mCurrentDirection_(Direction::HALT),
	mCurrentMotorPower_(0) {

	mSetPointPub_ = mNodeHandle_.advertise<std_msgs::Float64>("setpoint", 100);
	mStatePub_ = mNodeHandle_.advertise<std_msgs::Float64>("motor_rpm", 100);
	mBackboneWritePub_ = mNodeHandle_.advertise<backbone_bridge::BackboneWrite>("backbone_write", 100);
	mControlEffortSub_ = mNodeHandle_.subscribe("control_effort", 100, &MotorController::controlEffortReceive, this);
	mDesiredMotorRpmSub_ = mNodeHandle_.subscribe("desired_motor_rpm", 100, &MotorController::desiredMotorRpmReceive, this);
	mBackboneReadClient_ = mNodeHandle_.serviceClient<backbone_bridge::BackboneRead>("backbone_read");

	mMotorControlLoopTimer_ = mNodeHandle_.createWallTimer(ros::WallDuration(0.1), &MotorController::run, this);
}

void MotorController::run(const ros::WallTimerEvent& event) {
	ros::service::waitForService("backbone_read");

	// publish desired motor RPM (set point)
	std_msgs::Float64 setPointMsg;
	setPointMsg.data = mDesiredMotorRpm_;
	mSetPointPub_.publish(setPointMsg);

	// compute current state
	// prepare service call
	backbone_bridge::BackboneRead srv;
	srv.request.address = MOTOR_CONTROLLER_DEVICE_ADDRESS;
	srv.request.data_start = MOTOR_CONTROLLER_RPM_DATA_START;
	srv.request.data_size = 4;

	if(!mBackboneReadClient_.exists()) {
		ROS_ERROR_THROTTLE(2, "Backbone read service not found: %s", mBackboneReadClient_.getService().c_str());
	}

	if(mBackboneReadClient_.call(srv)) {
		// get current wheel RPMs (rear wheels), stored in little-endian
		unsigned int left_wheel_rpm = srv.response.data.at(0) | (srv.response.data.at(1) << 8);
		unsigned int right_wheel_rpm = srv.response.data.at(2) | (srv.response.data.at(3) << 8);

		// differential gear, thus, motor RPM is mean of wheel RPMs
		double motorRpm = (left_wheel_rpm + right_wheel_rpm) / 2.0;

		// send state (current motor RPM) to pid
		std_msgs::Float64 motorRpmMsg;
		motorRpmMsg.data = motorRpm;
		mStatePub_.publish(motorRpmMsg);
	} else {
		ROS_ERROR_THROTTLE(2, "Reading wheel RPMs failed");
	}
}

void MotorController::controlEffortReceive(std_msgs::Float64 controlEffort) {
	// apply control effort to motor PWM value
	mCurrentMotorPower_ = mCurrentMotorPower_ + controlEffort.data;

	// limit power value
	if(mCurrentMotorPower_ < 0) {
		mCurrentMotorPower_ = 0;
	}
	if(mCurrentMotorPower_ > 31) {
		mCurrentMotorPower_ = 31;
	}

	ROS_INFO("Motor power: %f", mCurrentMotorPower_);

	// compute PWM value from power value
	unsigned int pwmValue = motorPowerToPwm(mCurrentMotorPower_, mCurrentDirection_);

	// send PWM value to motor
	sendMotorPwm(pwmValue);
}

void MotorController::desiredMotorRpmReceive(std_msgs::Float64 desiredRpm) {
	mDesiredMotorRpm_ = desiredRpm.data;
}

void MotorController::sendMotorPwm(unsigned int pwmValue) {
	backbone_bridge::BackboneWrite bw;
	bw.stamp = ros::Time::now();
	bw.address = MOTOR_CONTROLLER_DEVICE_ADDRESS;
	bw.data_index = MOTOR_CONTROLLER_ESC_PWM_DATA_START;

	// little endian byte order
	bw.data.push_back((uint8_t)(pwmValue & 0xff));
	bw.data.push_back((uint8_t)((pwmValue >> 8) & 0xff));

	mBackboneWritePub_.publish(bw);
}

unsigned int MotorController::motorPowerToPwm(double motorPower, Direction direction) {
	ROS_ASSERT(motorPower >= 0);
	ROS_ASSERT(motorPower <= 31);

	unsigned int pwmValue;

	switch(direction) {
	case Direction::FORWARDS:
		pwmValue = MOTOR_PWM_NEUTRAL - (unsigned int)motorPower;
		break;
	case Direction::BACKWARDS:
		pwmValue = MOTOR_PWM_NEUTRAL + (unsigned int)motorPower;
		break;
	case Direction::HALT:
	default:
		pwmValue = MOTOR_PWM_NEUTRAL;
	}

	ROS_ASSERT(pwmValue >= MOTOR_PWM_MIN);
	ROS_ASSERT(pwmValue <= MOTOR_PWM_MAX);

	return pwmValue;
}
