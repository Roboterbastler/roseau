#ifndef _ROS_SERVICE_ReserveChargingStation_h
#define _ROS_SERVICE_ReserveChargingStation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

static const char RESERVECHARGINGSTATION[] = "auto_warehousing/ReserveChargingStation";

  class ReserveChargingStationRequest : public ros::Msg
  {
    public:
      typedef uint32_t _charging_station_id_type;
      _charging_station_id_type charging_station_id;

    ReserveChargingStationRequest():
      charging_station_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->charging_station_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charging_station_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->charging_station_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->charging_station_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charging_station_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->charging_station_id =  ((uint32_t) (*(inbuffer + offset)));
      this->charging_station_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->charging_station_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->charging_station_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->charging_station_id);
     return offset;
    }

    const char * getType(){ return RESERVECHARGINGSTATION; };
    const char * getMD5(){ return "41410a323e12d14320b3b9a0be7226b3"; };

  };

  class ReserveChargingStationResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ReserveChargingStationResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return RESERVECHARGINGSTATION; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ReserveChargingStation {
    public:
    typedef ReserveChargingStationRequest Request;
    typedef ReserveChargingStationResponse Response;
  };

}
#endif
