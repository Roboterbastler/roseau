#ifndef _ROS_SERVICE_outputRequest_h
#define _ROS_SERVICE_outputRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char OUTPUTREQUEST[] = "auto_warehousing/outputRequest";

  class outputRequestRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _posStart_type;
      _posStart_type posStart;
      uint32_t idTrays_length;
      typedef uint32_t _idTrays_type;
      _idTrays_type st_idTrays;
      _idTrays_type * idTrays;
      uint32_t idGoal_length;
      typedef uint32_t _idGoal_type;
      _idGoal_type st_idGoal;
      _idGoal_type * idGoal;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;

    outputRequestRequest():
      posStart(),
      idTrays_length(0), idTrays(NULL),
      idGoal_length(0), idGoal(NULL),
      robot()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->posStart.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->idTrays_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idTrays_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idTrays_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idTrays_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idTrays_length);
      for( uint32_t i = 0; i < idTrays_length; i++){
      *(outbuffer + offset + 0) = (this->idTrays[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idTrays[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idTrays[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idTrays[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idTrays[i]);
      }
      *(outbuffer + offset + 0) = (this->idGoal_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idGoal_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idGoal_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idGoal_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idGoal_length);
      for( uint32_t i = 0; i < idGoal_length; i++){
      *(outbuffer + offset + 0) = (this->idGoal[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idGoal[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idGoal[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idGoal[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idGoal[i]);
      }
      offset += this->robot.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->posStart.deserialize(inbuffer + offset);
      uint32_t idTrays_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      idTrays_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      idTrays_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      idTrays_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->idTrays_length);
      if(idTrays_lengthT > idTrays_length)
        this->idTrays = (uint32_t*)realloc(this->idTrays, idTrays_lengthT * sizeof(uint32_t));
      idTrays_length = idTrays_lengthT;
      for( uint32_t i = 0; i < idTrays_length; i++){
      this->st_idTrays =  ((uint32_t) (*(inbuffer + offset)));
      this->st_idTrays |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_idTrays |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_idTrays |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_idTrays);
        memcpy( &(this->idTrays[i]), &(this->st_idTrays), sizeof(uint32_t));
      }
      uint32_t idGoal_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      idGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      idGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      idGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->idGoal_length);
      if(idGoal_lengthT > idGoal_length)
        this->idGoal = (uint32_t*)realloc(this->idGoal, idGoal_lengthT * sizeof(uint32_t));
      idGoal_length = idGoal_lengthT;
      for( uint32_t i = 0; i < idGoal_length; i++){
      this->st_idGoal =  ((uint32_t) (*(inbuffer + offset)));
      this->st_idGoal |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_idGoal |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_idGoal |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_idGoal);
        memcpy( &(this->idGoal[i]), &(this->st_idGoal), sizeof(uint32_t));
      }
      offset += this->robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OUTPUTREQUEST; };
    const char * getMD5(){ return "99ea894e2e112745524c8f106fe9556a"; };

  };

  class outputRequestResponse : public ros::Msg
  {
    public:
      uint32_t pointsToTray_length;
      typedef geometry_msgs::Point _pointsToTray_type;
      _pointsToTray_type st_pointsToTray;
      _pointsToTray_type * pointsToTray;
      uint32_t pointsToOutput_length;
      typedef geometry_msgs::Point _pointsToOutput_type;
      _pointsToOutput_type st_pointsToOutput;
      _pointsToOutput_type * pointsToOutput;
      typedef uint32_t _idBest_type;
      _idBest_type idBest;
      typedef float _length_type;
      _length_type length;

    outputRequestResponse():
      pointsToTray_length(0), pointsToTray(NULL),
      pointsToOutput_length(0), pointsToOutput(NULL),
      idBest(0),
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
      *(outbuffer + offset + 0) = (this->pointsToOutput_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToOutput_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToOutput_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToOutput_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToOutput_length);
      for( uint32_t i = 0; i < pointsToOutput_length; i++){
      offset += this->pointsToOutput[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->idBest >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idBest >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idBest >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idBest >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idBest);
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
      uint32_t pointsToOutput_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointsToOutput_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointsToOutput_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointsToOutput_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointsToOutput_length);
      if(pointsToOutput_lengthT > pointsToOutput_length)
        this->pointsToOutput = (geometry_msgs::Point*)realloc(this->pointsToOutput, pointsToOutput_lengthT * sizeof(geometry_msgs::Point));
      pointsToOutput_length = pointsToOutput_lengthT;
      for( uint32_t i = 0; i < pointsToOutput_length; i++){
      offset += this->st_pointsToOutput.deserialize(inbuffer + offset);
        memcpy( &(this->pointsToOutput[i]), &(this->st_pointsToOutput), sizeof(geometry_msgs::Point));
      }
      this->idBest =  ((uint32_t) (*(inbuffer + offset)));
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->idBest);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return OUTPUTREQUEST; };
    const char * getMD5(){ return "a02a86b1edfdc92f7484204d045d30c6"; };

  };

  class outputRequest {
    public:
    typedef outputRequestRequest Request;
    typedef outputRequestResponse Response;
  };

}
#endif
