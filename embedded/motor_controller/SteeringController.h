#include <ros.h>
#include <std_msgs/Int8.h>

namespace steering {
  
void init(ros::NodeHandle &nh);

void setSteeringCb(const std_msgs::Int8& msg);

}

