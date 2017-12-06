#ifndef _ROS_auto_warehousing_PackagePool_h
#define _ROS_auto_warehousing_PackagePool_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace auto_warehousing
{

  class PackagePool : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point32 _drop_location_type;
      _drop_location_type drop_location;
      geometry_msgs::Point32 stacking_area[2];

    PackagePool():
      drop_location(),
      stacking_area()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->drop_location.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->stacking_area[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->drop_location.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->stacking_area[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "auto_warehousing/PackagePool"; };
    const char * getMD5(){ return "bcef3bd1883fdc3a8214f645cc30ecaa"; };

  };

}
#endif