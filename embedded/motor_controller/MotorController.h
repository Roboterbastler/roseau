#include <ros.h>

namespace motor {

void init(ros::NodeHandle &nh);

void update();

void setVelocity(double vel);

void getTicks(byte *left, byte *right, unsigned long *dur);
void left_encoder_cb();
void right_encoder_cb();

}

