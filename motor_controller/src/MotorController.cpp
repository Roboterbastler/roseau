#include <MotorController.h>

#include <backbone_bridge/BackboneRead.h>
#include <backbone_bridge/BackboneWrite.h>
#include <motor_controller/WheelRpm.h>

MotorController::MotorController(ros::NodeHandle &nh)
  : mNodeHandle_(nh),
    mDesiredMotorRpm_(0),
	mCurrentDirection_(Direction::HALT),
	mCurrentMotorPower_(0) {

	mSetPointPub_ = mNodeHandle_.advertise<std_msgs::Float64>("setpoint", 100);
	mStatePub_ = mNodeHandle_.advertise<std_msgs::Float64>("motor_rpm", 100);
	mBackboneWritePub_ = mNodeHandle_.advertise<backbone_bridge::BackboneWrite>("backbone_write", 100);
	mWheelRpmPub_ = mNodeHandle_.advertise<motor_controller::WheelRpm>("wheel_rpm", 100);
	mDesiredMotorRpmPub_ = mNodeHandle_.advertise<std_msgs::Float64>("desired_motor_rpm", 100);
	mControlEffortSub_ = mNodeHandle_.subscribe("control_effort", 100, &MotorController::controlEffortReceive, this);
	mDesiredMotorVelSub_ = mNodeHandle_.subscribe("desired_velocity", 100, &MotorController::desiredVelocityReceive, this);
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

		// publish wheel rpms
		motor_controller::WheelRpm wheelRpm;
		wheelRpm.left_wheel = left_wheel_rpm;
		wheelRpm.right_wheel = right_wheel_rpm;
		wheelRpm.stamp = ros::Time::now();

		// differential gear, thus, motor RPM is mean of wheel RPMs
		double motorRpm = (left_wheel_rpm + right_wheel_rpm) / 2.0;

		// send state (current motor RPM) to pid
		std_msgs::Float64 motorRpmMsg;
		if(mCurrentDirection_ == Direction::BACKWARDS) {
			motorRpmMsg.data = -motorRpm;
		} else {
			motorRpmMsg.data = motorRpm;
		}

		mStatePub_.publish(motorRpmMsg);
	} else {
		ROS_ERROR_THROTTLE(2, "Reading wheel RPMs failed");
	}
}

void MotorController::controlEffortReceive(std_msgs::Float64 controlEffort) {
	// apply control effort to motor PWM value
	if(mCurrentDirection_ == Direction::FORWARDS) {
		mCurrentMotorPower_ += controlEffort.data;
	} else if(mCurrentDirection_ == Direction::BACKWARDS) {
		mCurrentMotorPower_ -= controlEffort.data;
	}

	// limit power value
	if(mCurrentMotorPower_ < -31) {
		mCurrentMotorPower_ = -31;
	}
	if(mCurrentMotorPower_ > 31) {
		mCurrentMotorPower_ = 31;
	}

	ROS_DEBUG("Motor power: %f", mCurrentMotorPower_ * 100. / 31.);

	// compute PWM value from power value
	unsigned int pwmValue = motorPowerToPwm(mCurrentMotorPower_, mCurrentDirection_);

	// send PWM value to motor
	sendMotorPwm(pwmValue);
}

void MotorController::desiredVelocityReceive(geometry_msgs::Twist desiredVelocity) {


	// first, handle linear velocity (only possible in x direction)
	double desiredRpm = 60. * desiredVelocity.linear.x * 1000. / WHEEL_CIRCUMFERENCE_MM;
	mDesiredMotorRpm_ = desiredRpm;

	// publish desired rpm to pid controller
	std_msgs::Float64 msg;

	if(desiredVelocity.linear.x > 0) {
		mCurrentDirection_ = Direction::FORWARDS;
		msg.data = desiredRpm;
	} else if(desiredVelocity.linear.x < 0) {
		mCurrentDirection_ = Direction::BACKWARDS;
		msg.data = -desiredRpm;
	} else {
		mCurrentDirection_ = Direction::HALT;
		msg.data = desiredRpm;
	}

	mDesiredMotorRpmPub_.publish(msg);

	// angular velocity TODO
	// compute steering angle from desired angular an linear speed
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
	ROS_ASSERT(motorPower >= -31);
	ROS_ASSERT(motorPower <= 31);

	unsigned int pwmValue;

	if(direction == Direction::HALT) {
		pwmValue = MOTOR_PWM_NEUTRAL;
	} else {
		pwmValue = MOTOR_PWM_NEUTRAL + motorPower;
	}

	ROS_ASSERT(pwmValue >= MOTOR_PWM_MIN);
	ROS_ASSERT(pwmValue <= MOTOR_PWM_MAX);

	return pwmValue;
}
