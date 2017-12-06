#ifndef _ROS_SERVICE_localPath_h
#define _ROS_SERVICE_localPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char LOCALPATH[] = "auto_warehousing/localPath";

  class localPathRequest : public ros::Msg
  {
    public:
      typedef uint32_t _trayID_type;
      _trayID_type trayID;
      typedef geometry_msgs::Point _obstacleLeft_type;
      _obstacleLeft_type obstacleLeft;
      typedef geometry_msgs::Point _obstacleFront_type;
      _obstacleFront_type obstacleFront;
      typedef geometry_msgs::Point _obstacleRight_type;
      _obstacleRight_type obstacleRight;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;

    localPathRequest():
      trayID(0),
      obstacleLeft(),
      obstacleFront(),
      obstacleRight(),
      robot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trayID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trayID >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trayID >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trayID >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trayID);
      offset += this->obstacleLeft.serialize(outbuffer + offset);
      offset += this->obstacleFront.serialize(outbuffer + offset);
      offset += this->obstacleRight.serialize(outbuffer + offset);
      offset += this->robot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->trayID =  ((uint32_t) (*(inbuffer + offset)));
      this->trayID |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trayID |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trayID |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trayID);
      offset += this->obstacleLeft.deserialize(inbuffer + offset);
      offset += this->obstacleFront.deserialize(inbuffer + offset);
      offset += this->obstacleRight.deserialize(inbuffer + offset);
      offset += this->robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return LOCALPATH; };
    const char * getMD5(){ return "e5f4d3c20e760d513e9ea62b4893ebf3"; };

  };

  class localPathResponse : public ros::Msg
  {
    public:
      uint32_t pointsToTray_length;
      typedef geometry_msgs::Point _pointsToTray_type;
      _pointsToTray_type st_pointsToTray;
      _pointsToTray_type * pointsToTray;
      typedef float _length_type;
      _length_type length;

    localPathResponse():
      pointsToTray_length(0), pointsToTray(NULL),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pointsToTray_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToTray_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToTray_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToTray_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToTray_length);
      for( uint32_t i = 0; i < pointsToTray_length; i++){
      offset += this->pointsToTray[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pointsToTray_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointsToTray_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointsToTray_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointsToTray_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointsToTray_length);
      if(pointsToTray_lengthT > pointsToTray_length)
        this->pointsToTray = (geometry_msgs::Point*)realloc(this->pointsToTray, pointsToTray_lengthT * sizeof(geometry_msgs::Point));
      pointsToTray_length = pointsToTray_lengthT;
      for( uint32_t i = 0; i < pointsToTray_length; i++){
      offset += this->st_pointsToTray.deserialize(inbuffer + offset);
        memcpy( &(this->pointsToTray[i]), &(this->st_pointsToTray), sizeof(geometry_msgs::Point));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return LOCALPATH; };
    const char * getMD5(){ return "41cfb9067b920543e28a8a54fc1f616f"; };

  };

  class localPath {
    public:
    typedef localPathRequest Request;
    typedef localPathResponse Response;
  };

}
#endif
