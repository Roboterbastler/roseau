#ifndef _ROS_SERVICE_MatchClouds_h
#define _ROS_SERVICE_MatchClouds_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Transform.h"

namespace ethzasl_icp_mapper
{

static const char MATCHCLOUDS[] = "ethzasl_icp_mapper/MatchClouds";

  class MatchCloudsRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _reference_type;
      _reference_type reference;
      typedef sensor_msgs::PointCloud2 _readings_type;
      _readings_type readings;

    MatchCloudsRequest():
      reference(),
      readings()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->reference.serialize(outbuffer + offset);
      offset += this->readings.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->reference.deserialize(inbuffer + offset);
      offset += this->readings.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MATCHCLOUDS; };
    const char * getMD5(){ return "7c0945df9b4e88c1f6f45d0b43009748"; };

  };

  class MatchCloudsResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _transform_type;
      _transform_type transform;

    MatchCloudsResponse():
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

    const char * getType(){ return MATCHCLOUDS; };
    const char * getMD5(){ return "c2d1de03cf5b052350d875b7cfbc84a5"; };

  };

  class MatchClouds {
    public:
    typedef MatchCloudsRequest Request;
    typedef MatchCloudsResponse Response;
  };

}
#endif
