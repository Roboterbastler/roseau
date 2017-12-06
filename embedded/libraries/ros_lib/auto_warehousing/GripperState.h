#ifndef _ROS_auto_warehousing_GripperState_h
#define _ROS_auto_warehousing_GripperState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

  class GripperState : public ros::Msg
  {
    public:
      typedef bool _loaded_type;
      _loaded_type loaded;
      typedef auto_warehousing::Package _package_type;
      _package_type package;

    GripperState():
      loaded(0),
      package()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_loaded;
      u_loaded.real = this->loaded;
      *(outbuffer + offset + 0) = (u_loaded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loaded);
      offset += this->package.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_loaded;
      u_loaded.base = 0;
      u_loaded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loaded = u_loaded.real;
      offset += sizeof(this->loaded);
      offset += this->package.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/GripperState"; };
    const char * getMD5(){ return "b937d7d47f113e6408c1ccaabb941455"; };

  };

}
#endif