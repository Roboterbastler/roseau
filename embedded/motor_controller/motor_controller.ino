#include <ArduinoHardware.h>
#include <ros.h>
#include <roseau_msgs/MotorSetPoint.h>
#include <roseau_msgs/WheelOdometry.h>

#include "MotorController.h"
#include "SteeringController.h"

#define ODOM_PUB_TIME_MS 100

static ros::NodeHandle nh;

static roseau_msgs::WheelOdometry wo;
static ros::Publisher odomPub("wheel_ticks", &wo);

// Put longer messages in flash
const static char mc_init_msg[] PROGMEM = "Motor controller initialized.";
const static char sc_init_msg[] PROGMEM = "Steering controller initialized.";

static void receiveMotorSetPoint(const roseau_msgs::MotorSetPoint &msg) {
  motor::setVelocity(msg.set_point);
}

static void getWheelOdom() {
  wo.left_wheel = motor::getLeftOdom();
  wo.right_wheel = motor::getRightOdom();
}

void setup() {
  // setup ROS
  nh.initNode();

  // initialize motor controller
  motor::init();

  nh.loginfo(mc_init_msg);

  // initialize steering controller
  //steering::init(nh);

  //nh.loginfo(sc_init_msg);

  nh.advertise(odomPub);

  while(!nh.connected()) {
    nh.spinOnce();
  }
}

void loop() {
  static unsigned long lastOdomSampleTime = 0;
  
  // put your main code here, to run repeatedly:
  motor::update();

  // throttle odom publishing
  unsigned long now = millis();
  if(now - lastOdomSampleTime > ODOM_PUB_TIME_MS) {
    getWheelOdom();
    odomPub.publish(&wo);
    lastOdomSampleTime = now;
  }
  
  nh.spinOnce();
}
