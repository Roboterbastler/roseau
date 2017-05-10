#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>

#define MOTOR_CONTROLLER_DEVICE_ADDRESS 16
#define MOTOR_CONTROLLER_RPM_DATA_START 8
#define MOTOR_CONTROLLER_ESC_PWM_DATA_START 0
#define MOTOR_CONTROLLER_STEERING_PWM_DATA_START 2

#define MOTOR_PWM_NEUTRAL 94
#define MOTOR_PWM_MIN 63
#define MOTOR_PWM_MAX 125

class MotorController {
public:
  MotorController(ros::NodeHandle &nh);

protected:
  void run(const ros::WallTimerEvent& event);
  void controlEffortReceive(std_msgs::Float64 controlEffort);
  void desiredMotorRpmReceive(std_msgs::Float64 desiredRpm);
  void sendMotorPwm(unsigned int pwmValue);

protected:
  /**
   * Node handle
   */
  ros::NodeHandle &mNodeHandle_;

  /**
   * Calls the motor control loop.
   */
  ros::WallTimer mMotorControlLoopTimer_;

  /**
   * Current desired motor speed
   */
  double mDesiredMotorRpm_;

  /**
   * The desired direction.
   */
  enum class Direction {
	  FORWARDS,
	  BACKWARDS,
	  HALT
  } mCurrentDirection_;

  /**
   * The current motor power value in the range 0...31 independent of the direction.
   * A value of 31 means 100% power.
   */
  double mCurrentMotorPower_;

  /**
   * Publishes the set point (desired RPM) to the PID controller.
   */
  ros::Publisher mSetPointPub_;

  /**
   * Publishes the state (current motor RPM) to the PID controller.
   */
  ros::Publisher mStatePub_;

  /**
 * Publishes the wheel RPMs.
 */
ros::Publisher mWheelRpmPub_;

  /**
   * Publishes the motor PWM value to the backbone bus.
   */
  ros::Publisher mBackboneWritePub_;

  /**
   * Subscribes to the PID controller to get control effort.
   */
  ros::Subscriber mControlEffortSub_;

  /**
   * Receives motor RPM commands.
   */
  ros::Subscriber mDesiredMotorRpmSub_;

  /**
   * Reads via the backbone bus.
   */
  ros::ServiceClient mBackboneReadClient_;

protected:
  static unsigned int motorPowerToPwm(double motorPower, Direction direction);
};

#endif
