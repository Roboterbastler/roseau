#include <MotorController.h>

MotorController::MotorController(ros::NodeHandle &nh)
  : mNodeHandle_(nh),
    mDesiredMotorRpm_(0) {

	mSetPointPub_ = mNodeHandle_.advertise<std_msgs::Float64>("setpoint", 100);
	mStatePub_ = mNodeHandle_.advertise<std_msgs::Float64>("motor_rpm", 100);
	mControlEffortSub_ = mNodeHandle_.subscribe("control_effort", 100, &MotorController::controlEffortReceive, this);

	mBackboneReadClient_ = mNodeHandle_.serviceClient<backbone_bridge::BackboneRead>("backbone_read");
}

void MotorController::run() {
	// 10 Hz update rate
	ros::Rate r(10);

	while(ros::ok()) {
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
			ROS_ERROR_THROTTLE(2, "Backbone read service not found");
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

		r.sleep();
	}
}

void MotorController::controlEffortReceive(std_msgs::Float64 controlEffort) {
	// TODO
	// send to motor
}
