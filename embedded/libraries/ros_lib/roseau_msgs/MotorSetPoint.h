#ifndef _ROS_roseau_msgs_MotorSetPoint_h
#define _ROS_roseau_msgs_MotorSetPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roseau_msgs
{

  class MotorSetPoint : public ros::Msg
  {
    public:
      typedef float _set_point_type;
      _set_point_type set_point;

    MotorSetPoint():
      set_point(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->set_point);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->set_point));
     return offset;
    }

    const char * getType(){ return "roseau_msgs/MotorSetPoint"; };
    const char * getMD5(){ return "d028aa3c5a4d17f88258ecdcc12644ee"; };

  };

}
#endif