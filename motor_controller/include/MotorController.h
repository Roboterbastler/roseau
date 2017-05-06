#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <backbone_bridge/BackboneRead.h>

#define MOTOR_CONTROLLER_DEVICE_ADDRESS 0x10;
#define MOTOR_CONTROLLER_RPM_DATA_START 8

class MotorController {
public:
  MotorController(ros::NodeHandle &nh);

  void run();

protected:
  void controlEffortReceive(std_msgs::Float64 controlEffort);
  bool sendMotorPwm();

protected:
  /**
   * Node handle
   */
  ros::NodeHandle &mNodeHandle_;

  /**
   * Current desired motor speed
   */
  double mDesiredMotorRpm_;

  /**
   * Publishes the set point (desired RPM) to the PID controller.
   */
  ros::Publisher mSetPointPub_;

  /**
   * Publishes the state (current motor RPM) to the PID controller.
   */
  ros::Publisher mStatePub_;

  /**
   * Subscribes to the PID controller to get control effort.
   */
  ros::Subscriber mControlEffortSub_;

  /**
   * Reads via the backbone bus.
   */
  ros::ServiceClient mBackboneReadClient_;
};

#endif
