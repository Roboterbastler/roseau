#include <ArduinoHardware.h>
#include <ros.h>

#include "MotorController.h"
#include "SteeringController.h"

ros::NodeHandle nh;

void setup() {
  // setup ROS
  nh.initNode();

  // initialize motor controller
  motor::init(nh);

  // initialize steering controller
  steering::init(nh);

  while(!nh.connected()) {
    nh.spinOnce();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  motor::update();
  nh.spinOnce();
}
