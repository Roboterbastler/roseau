#ifndef _ROS_SERVICE_shortestPath_h
#define _ROS_SERVICE_shortestPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char SHORTESTPATH[] = "auto_warehousing/shortestPath";

  class shortestPathRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _p1_type;
      _p1_type p1;
      typedef geometry_msgs::Point _p2_type;
      _p2_type p2;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;

    shortestPathRequest():
      p1(),
      p2(),
      robot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->p1.serialize(outbuffer + offset);
      offset += this->p2.serialize(outbuffer + offset);
      offset += this->robot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->p1.deserialize(inbuffer + offset);
      offset += this->p2.deserialize(inbuffer + offset);
      offset += this->robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SHORTESTPATH; };
    const char * getMD5(){ return "ad6fc6ebd965daba53bb6f3b9525c157"; };

  };

  class shortestPathResponse : public ros::Msg
  {
    public:
      uint32_t resultPoints_length;
      typedef geometry_msgs::Point _resultPoints_type;
      _resultPoints_type st_resultPoints;
      _resultPoints_type * resultPoints;
      typedef float _length_type;
      _length_type length;

    shortestPathResponse():
      resultPoints_length(0), resultPoints(NULL),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->resultPoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->resultPoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->resultPoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->resultPoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resultPoints_length);
      for( uint32_t i = 0; i < resultPoints_length; i++){
      offset += this->resultPoints[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t resultPoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      resultPoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      resultPoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      resultPoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->resultPoints_length);
      if(resultPoints_lengthT > resultPoints_length)
        this->resultPoints = (geometry_msgs::Point*)realloc(this->resultPoints, resultPoints_lengthT * sizeof(geometry_msgs::Point));
      resultPoints_length = resultPoints_lengthT;
      for( uint32_t i = 0; i < resultPoints_length; i++){
      offset += this->st_resultPoints.deserialize(inbuffer + offset);
        memcpy( &(this->resultPoints[i]), &(this->st_resultPoints), sizeof(geometry_msgs::Point));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return SHORTESTPATH; };
    const char * getMD5(){ return "adb0f22f75a0a613240ae609a5826559"; };

  };

  class shortestPath {
    public:
    typedef shortestPathRequest Request;
    typedef shortestPathResponse Response;
  };

}
#endif
