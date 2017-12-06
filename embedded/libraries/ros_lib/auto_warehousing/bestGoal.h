#ifndef _ROS_SERVICE_bestGoal_h
#define _ROS_SERVICE_bestGoal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char BESTGOAL[] = "auto_warehousing/bestGoal";

  class bestGoalRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _posStart_type;
      _posStart_type posStart;
      uint32_t idTargets_length;
      typedef uint32_t _idTargets_type;
      _idTargets_type st_idTargets;
      _idTargets_type * idTargets;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;

    bestGoalRequest():
      posStart(),
      idTargets_length(0), idTargets(NULL),
      robot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->posStart.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->idTargets_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idTargets_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idTargets_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idTargets_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idTargets_length);
      for( uint32_t i = 0; i < idTargets_length; i++){
      *(outbuffer + offset + 0) = (this->idTargets[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idTargets[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idTargets[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idTargets[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idTargets[i]);
      }
      offset += this->robot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->posStart.deserialize(inbuffer + offset);
      uint32_t idTargets_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      idTargets_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      idTargets_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      idTargets_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->idTargets_length);
      if(idTargets_lengthT > idTargets_length)
        this->idTargets = (uint32_t*)realloc(this->idTargets, idTargets_lengthT * sizeof(uint32_t));
      idTargets_length = idTargets_lengthT;
      for( uint32_t i = 0; i < idTargets_length; i++){
      this->st_idTargets =  ((uint32_t) (*(inbuffer + offset)));
      this->st_idTargets |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_idTargets |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_idTargets |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_idTargets);
        memcpy( &(this->idTargets[i]), &(this->st_idTargets), sizeof(uint32_t));
      }
      offset += this->robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return BESTGOAL; };
    const char * getMD5(){ return "ee056599c9a445b32625c6d835007721"; };

  };

  class bestGoalResponse : public ros::Msg
  {
    public:
      uint32_t resultPoints_length;
      typedef geometry_msgs::Point _resultPoints_type;
      _resultPoints_type st_resultPoints;
      _resultPoints_type * resultPoints;
      typedef uint32_t _idBestTray_type;
      _idBestTray_type idBestTray;
      typedef float _length_type;
      _length_type length;

    bestGoalResponse():
      resultPoints_length(0), resultPoints(NULL),
      idBestTray(0),
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
      *(outbuffer + offset + 0) = (this->idBestTray >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idBestTray >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idBestTray >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idBestTray >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idBestTray);
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
      this->idBestTray =  ((uint32_t) (*(inbuffer + offset)));
      this->idBestTray |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idBestTray |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->idBestTray |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->idBestTray);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return BESTGOAL; };
    const char * getMD5(){ return "ea589563e8b15fe16becce5d8d340f24"; };

  };

  class bestGoal {
    public:
    typedef bestGoalRequest Request;
    typedef bestGoalResponse Response;
  };

}
#endif
