#ifndef _ROS_SERVICE_inputRequest_h
#define _ROS_SERVICE_inputRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char INPUTREQUEST[] = "auto_warehousing/inputRequest";

  class inputRequestRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _posStart_type;
      _posStart_type posStart;
      uint32_t idTrays_length;
      typedef uint32_t _idTrays_type;
      _idTrays_type st_idTrays;
      _idTrays_type * idTrays;
      uint32_t idInput_length;
      typedef uint32_t _idInput_type;
      _idInput_type st_idInput;
      _idInput_type * idInput;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;

    inputRequestRequest():
      posStart(),
      idTrays_length(0), idTrays(NULL),
      idInput_length(0), idInput(NULL),
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
      *(outbuffer + offset + 0) = (this->idInput_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idInput_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idInput_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idInput_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idInput_length);
      for( uint32_t i = 0; i < idInput_length; i++){
      *(outbuffer + offset + 0) = (this->idInput[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idInput[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idInput[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idInput[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idInput[i]);
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
      uint32_t idInput_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      idInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      idInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      idInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->idInput_length);
      if(idInput_lengthT > idInput_length)
        this->idInput = (uint32_t*)realloc(this->idInput, idInput_lengthT * sizeof(uint32_t));
      idInput_length = idInput_lengthT;
      for( uint32_t i = 0; i < idInput_length; i++){
      this->st_idInput =  ((uint32_t) (*(inbuffer + offset)));
      this->st_idInput |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_idInput |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_idInput |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_idInput);
        memcpy( &(this->idInput[i]), &(this->st_idInput), sizeof(uint32_t));
      }
      offset += this->robot.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INPUTREQUEST; };
    const char * getMD5(){ return "c5f1c61abfa9f0ec5f04789dee1a21a0"; };

  };

  class inputRequestResponse : public ros::Msg
  {
    public:
      uint32_t pointsToInput_length;
      typedef geometry_msgs::Point _pointsToInput_type;
      _pointsToInput_type st_pointsToInput;
      _pointsToInput_type * pointsToInput;
      uint32_t pointsToTray_length;
      typedef geometry_msgs::Point _pointsToTray_type;
      _pointsToTray_type st_pointsToTray;
      _pointsToTray_type * pointsToTray;
      typedef uint32_t _idBest_type;
      _idBest_type idBest;
      typedef float _length_type;
      _length_type length;

    inputRequestResponse():
      pointsToInput_length(0), pointsToInput(NULL),
      pointsToTray_length(0), pointsToTray(NULL),
      idBest(0),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pointsToInput_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToInput_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToInput_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToInput_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToInput_length);
      for( uint32_t i = 0; i < pointsToInput_length; i++){
      offset += this->pointsToInput[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->pointsToTray_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToTray_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToTray_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToTray_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToTray_length);
      for( uint32_t i = 0; i < pointsToTray_length; i++){
      offset += this->pointsToTray[i].serialize(outbuffer + offset);
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
      uint32_t pointsToInput_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointsToInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointsToInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointsToInput_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointsToInput_length);
      if(pointsToInput_lengthT > pointsToInput_length)
        this->pointsToInput = (geometry_msgs::Point*)realloc(this->pointsToInput, pointsToInput_lengthT * sizeof(geometry_msgs::Point));
      pointsToInput_length = pointsToInput_lengthT;
      for( uint32_t i = 0; i < pointsToInput_length; i++){
      offset += this->st_pointsToInput.deserialize(inbuffer + offset);
        memcpy( &(this->pointsToInput[i]), &(this->st_pointsToInput), sizeof(geometry_msgs::Point));
      }
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
      this->idBest =  ((uint32_t) (*(inbuffer + offset)));
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->idBest |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->idBest);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return INPUTREQUEST; };
    const char * getMD5(){ return "21e8c1a09d55cb30253f5a72104c5cd6"; };

  };

  class inputRequest {
    public:
    typedef inputRequestRequest Request;
    typedef inputRequestResponse Response;
  };

}
#endif
