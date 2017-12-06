#ifndef _ROS_SERVICE_GetTransform_h
#define _ROS_SERVICE_GetTransform_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "gnss_initializer_msgs/EstimatedTransform.h"

namespace gnss_initializer_msgs
{

static const char GETTRANSFORM[] = "gnss_initializer_msgs/GetTransform";

  class GetTransformRequest : public ros::Msg
  {
    public:

    GetTransformRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETTRANSFORM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetTransformResponse : public ros::Msg
  {
    public:
      typedef gnss_initializer_msgs::EstimatedTransform _transform_type;
      _transform_type transform;

    GetTransformResponse():
      transform()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->transform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->transform.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETTRANSFORM; };
    const char * getMD5(){ return "f0bb0db5d8c4e605ae2a9cc1ac7a3872"; };

  };

  class GetTransform {
    public:
    typedef GetTransformRequest Request;
    typedef GetTransformResponse Response;
  };

}
#endif
