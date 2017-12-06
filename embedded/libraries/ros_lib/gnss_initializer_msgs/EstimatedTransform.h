#ifndef _ROS_gnss_initializer_msgs_EstimatedTransform_h
#define _ROS_gnss_initializer_msgs_EstimatedTransform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/TransformStamped.h"

namespace gnss_initializer_msgs
{

  class EstimatedTransform : public ros::Msg
  {
    public:
      typedef geometry_msgs::TransformStamped _transform_type;
      _transform_type transform;
      typedef const char* _utm_zone_type;
      _utm_zone_type utm_zone;

    EstimatedTransform():
      transform(),
      utm_zone("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->transform.serialize(outbuffer + offset);
      uint32_t length_utm_zone = strlen(this->utm_zone);
      varToArr(outbuffer + offset, length_utm_zone);
      offset += 4;
      memcpy(outbuffer + offset, this->utm_zone, length_utm_zone);
      offset += length_utm_zone;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->transform.deserialize(inbuffer + offset);
      uint32_t length_utm_zone;
      arrToVar(length_utm_zone, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_utm_zone; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_utm_zone-1]=0;
      this->utm_zone = (char *)(inbuffer + offset-1);
      offset += length_utm_zone;
     return offset;
    }

    const char * getType(){ return "gnss_initializer_msgs/EstimatedTransform"; };
    const char * getMD5(){ return "11b037556c50b9155641773cdbec8f00"; };

  };

}
#endif