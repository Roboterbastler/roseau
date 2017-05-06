#include <ros/ros.h>

#include <MotorController.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "motor_controller");
  ros::NodeHandle n("~");

  MotorController mc(n);

  mc.run();
}
