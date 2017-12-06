#ifndef _ROS_SERVICE_ChargingPathsRequest_h
#define _ROS_SERVICE_ChargingPathsRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"
#include "auto_warehousing/Tray.h"

namespace auto_warehousing
{

static const char CHARGINGPATHSREQUEST[] = "auto_warehousing/ChargingPathsRequest";

  class ChargingPathsRequestRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _posStart_type;
      _posStart_type posStart;
      typedef geometry_msgs::Point _posGoal_type;
      _posGoal_type posGoal;
      typedef auto_warehousing::RobotConfiguration _robot_type;
      _robot_type robot;
      uint32_t chargingStations_length;
      typedef auto_warehousing::Tray _chargingStations_type;
      _chargingStations_type st_chargingStations;
      _chargingStations_type * chargingStations;

    ChargingPathsRequestRequest():
      posStart(),
      posGoal(),
      robot(),
      chargingStations_length(0), chargingStations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->posStart.serialize(outbuffer + offset);
      offset += this->posGoal.serialize(outbuffer + offset);
      offset += this->robot.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->chargingStations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->chargingStations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->chargingStations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->chargingStations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->chargingStations_length);
      for( uint32_t i = 0; i < chargingStations_length; i++){
      offset += this->chargingStations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->posStart.deserialize(inbuffer + offset);
      offset += this->posGoal.deserialize(inbuffer + offset);
      offset += this->robot.deserialize(inbuffer + offset);
      uint32_t chargingStations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      chargingStations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      chargingStations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      chargingStations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->chargingStations_length);
      if(chargingStations_lengthT > chargingStations_length)
        this->chargingStations = (auto_warehousing::Tray*)realloc(this->chargingStations, chargingStations_lengthT * sizeof(auto_warehousing::Tray));
      chargingStations_length = chargingStations_lengthT;
      for( uint32_t i = 0; i < chargingStations_length; i++){
      offset += this->st_chargingStations.deserialize(inbuffer + offset);
        memcpy( &(this->chargingStations[i]), &(this->st_chargingStations), sizeof(auto_warehousing::Tray));
      }
     return offset;
    }

    const char * getType(){ return CHARGINGPATHSREQUEST; };
    const char * getMD5(){ return "82259351e61ce28357a326b5997384cf"; };

  };

  class ChargingPathsRequestResponse : public ros::Msg
  {
    public:
      uint32_t pointsToChargingStation_length;
      typedef geometry_msgs::Point _pointsToChargingStation_type;
      _pointsToChargingStation_type st_pointsToChargingStation;
      _pointsToChargingStation_type * pointsToChargingStation;
      uint32_t pointsToGoal_length;
      typedef geometry_msgs::Point _pointsToGoal_type;
      _pointsToGoal_type st_pointsToGoal;
      _pointsToGoal_type * pointsToGoal;
      typedef uint32_t _chargingStationId_type;
      _chargingStationId_type chargingStationId;
      typedef float _length_type;
      _length_type length;

    ChargingPathsRequestResponse():
      pointsToChargingStation_length(0), pointsToChargingStation(NULL),
      pointsToGoal_length(0), pointsToGoal(NULL),
      chargingStationId(0),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pointsToChargingStation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToChargingStation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToChargingStation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToChargingStation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToChargingStation_length);
      for( uint32_t i = 0; i < pointsToChargingStation_length; i++){
      offset += this->pointsToChargingStation[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->pointsToGoal_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pointsToGoal_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pointsToGoal_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pointsToGoal_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pointsToGoal_length);
      for( uint32_t i = 0; i < pointsToGoal_length; i++){
      offset += this->pointsToGoal[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->chargingStationId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->chargingStationId >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->chargingStationId >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->chargingStationId >> (8 * 3)) & 0xFF;
      offset += sizeof(this->chargingStationId);
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t pointsToChargingStation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointsToChargingStation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointsToChargingStation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointsToChargingStation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointsToChargingStation_length);
      if(pointsToChargingStation_lengthT > pointsToChargingStation_length)
        this->pointsToChargingStation = (geometry_msgs::Point*)realloc(this->pointsToChargingStation, pointsToChargingStation_lengthT * sizeof(geometry_msgs::Point));
      pointsToChargingStation_length = pointsToChargingStation_lengthT;
      for( uint32_t i = 0; i < pointsToChargingStation_length; i++){
      offset += this->st_pointsToChargingStation.deserialize(inbuffer + offset);
        memcpy( &(this->pointsToChargingStation[i]), &(this->st_pointsToChargingStation), sizeof(geometry_msgs::Point));
      }
      uint32_t pointsToGoal_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pointsToGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pointsToGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pointsToGoal_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pointsToGoal_length);
      if(pointsToGoal_lengthT > pointsToGoal_length)
        this->pointsToGoal = (geometry_msgs::Point*)realloc(this->pointsToGoal, pointsToGoal_lengthT * sizeof(geometry_msgs::Point));
      pointsToGoal_length = pointsToGoal_lengthT;
      for( uint32_t i = 0; i < pointsToGoal_length; i++){
      offset += this->st_pointsToGoal.deserialize(inbuffer + offset);
        memcpy( &(this->pointsToGoal[i]), &(this->st_pointsToGoal), sizeof(geometry_msgs::Point));
      }
      this->chargingStationId =  ((uint32_t) (*(inbuffer + offset)));
      this->chargingStationId |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->chargingStationId |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->chargingStationId |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->chargingStationId);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return CHARGINGPATHSREQUEST; };
    const char * getMD5(){ return "4905242dfe75c0a9e0348292cdc3eb63"; };

  };

  class ChargingPathsRequest {
    public:
    typedef ChargingPathsRequestRequest Request;
    typedef ChargingPathsRequestResponse Response;
  };

}
#endif
