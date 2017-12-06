#ifndef _ROS_roseau_msgs_WheelOdometry_h
#define _ROS_roseau_msgs_WheelOdometry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roseau_msgs
{

  class WheelOdometry : public ros::Msg
  {
    public:
      typedef uint16_t _left_wheel_type;
      _left_wheel_type left_wheel;
      typedef uint16_t _right_wheel_type;
      _right_wheel_type right_wheel;

    WheelOdometry():
      left_wheel(0),
      right_wheel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->left_wheel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_wheel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_wheel);
      *(outbuffer + offset + 0) = (this->right_wheel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_wheel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_wheel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->left_wheel =  ((uint16_t) (*(inbuffer + offset)));
      this->left_wheel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->left_wheel);
      this->right_wheel =  ((uint16_t) (*(inbuffer + offset)));
      this->right_wheel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_wheel);
     return offset;
    }

    const char * getType(){ return "roseau_msgs/WheelOdometry"; };
    const char * getMD5(){ return "65259a2770331d45044cd18e1cd728e3"; };

  };

}
#endif