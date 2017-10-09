#include "SteeringController.h"

#include <Servo.h>

namespace steering {

// The steering servo
Servo steering;

ros::Subscriber<std_msgs::Int8> steeringSubscriber("steering_angle", &setSteeringCb);
  
void init(ros::NodeHandle &nh) {
  // setup steering servo
  steering.attach(9);
  steering.write(100);

  nh.subscribe(steeringSubscriber);

  nh.loginfo("Steering controller initialized.");
}

void setSteeringCb(const std_msgs::Int8& msg) {
  steering.write(msg.data);
}

}

