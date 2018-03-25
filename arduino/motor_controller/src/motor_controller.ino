#include <ArduinoHardware.h>
#include <ros.h>
#include <std_msgs/Float64.h>

#include "EscMotorController.hpp"

#define PUB_TIME_MS 100

using namespace motor_controller;

static ros::NodeHandle nh;

// Put longer messages in flash
const static char mc_init_msg[] PROGMEM = "Motor controller initialized.";

static void receiveMotorSetPoint(const std_msgs::Float64& msg) {
  EscMotorController::instance().setPoint(msg.data);
}

static ros::Subscriber<std_msgs::Float64> motorSetPointSub("motor_controller/set_point", &receiveMotorSetPoint);
static std_msgs::Float64 currentRpm;
static ros::Publisher rpmPub("motor_controller/rpm", &currentRpm);

void setup() {
  // setup ROS node
  nh.initNode();

  // initialize motor controller
  EscMotorController::instance();
  currentRpm.data = 0.0;
  nh.advertise(rpmPub);
  nh.subscribe(motorSetPointSub);

  nh.loginfo(mc_init_msg);

  while(!nh.connected()) {
    nh.spinOnce();
  }
}

void loop() {
  static unsigned long lastPubTime = 0;
  
  // put your main code here, to run repeatedly:
  EscMotorController::instance().update();

  unsigned long now = millis();
  if(now - lastPubTime > PUB_TIME_MS) {
    lastPubTime = now;

    currentRpm.data = EscMotorController::instance().getRpm();
    rpmPub.publish(&currentRpm);
  }
  
  nh.spinOnce();
}
