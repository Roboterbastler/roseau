#ifndef _ROS_SERVICE_GetBoundedMap_h
#define _ROS_SERVICE_GetBoundedMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Point.h"

namespace ethzasl_icp_mapper
{

static const char GETBOUNDEDMAP[] = "ethzasl_icp_mapper/GetBoundedMap";

  class GetBoundedMapRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _mapCenter_type;
      _mapCenter_type mapCenter;
      typedef geometry_msgs::Point _topRightCorner_type;
      _topRightCorner_type topRightCorner;
      typedef geometry_msgs::Point _bottomLeftCorner_type;
      _bottomLeftCorner_type bottomLeftCorner;

    GetBoundedMapRequest():
      mapCenter(),
      topRightCorner(),
      bottomLeftCorner()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->mapCenter.serialize(outbuffer + offset);
      offset += this->topRightCorner.serialize(outbuffer + offset);
      offset += this->bottomLeftCorner.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->mapCenter.deserialize(inbuffer + offset);
      offset += this->topRightCorner.deserialize(inbuffer + offset);
      offset += this->bottomLeftCorner.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETBOUNDEDMAP; };
    const char * getMD5(){ return "8cab119310bafad652e0154d699b10bf"; };

  };

  class GetBoundedMapResponse : public ros::Msg
  {
    public:
      typedef sensor_msgs::PointCloud2 _boundedMap_type;
      _boundedMap_type boundedMap;

    GetBoundedMapResponse():
      boundedMap()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->boundedMap.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->boundedMap.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETBOUNDEDMAP; };
    const char * getMD5(){ return "4c809f43088f16711ab4f6616e444088"; };

  };

  class GetBoundedMap {
    public:
    typedef GetBoundedMapRequest Request;
    typedef GetBoundedMapResponse Response;
  };

}
#endif
