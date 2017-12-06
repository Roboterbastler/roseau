#ifndef _ROS_SERVICE_GetFreeChargingStations_h
#define _ROS_SERVICE_GetFreeChargingStations_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Tray.h"

namespace auto_warehousing
{

static const char GETFREECHARGINGSTATIONS[] = "auto_warehousing/GetFreeChargingStations";

  class GetFreeChargingStationsRequest : public ros::Msg
  {
    public:

    GetFreeChargingStationsRequest()
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

    const char * getType(){ return GETFREECHARGINGSTATIONS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetFreeChargingStationsResponse : public ros::Msg
  {
    public:
      uint32_t charging_stations_length;
      typedef auto_warehousing::Tray _charging_stations_type;
      _charging_stations_type st_charging_stations;
      _charging_stations_type * charging_stations;

    GetFreeChargingStationsResponse():
      charging_stations_length(0), charging_stations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->charging_stations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charging_stations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->charging_stations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->charging_stations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charging_stations_length);
      for( uint32_t i = 0; i < charging_stations_length; i++){
      offset += this->charging_stations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t charging_stations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      charging_stations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      charging_stations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      charging_stations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->charging_stations_length);
      if(charging_stations_lengthT > charging_stations_length)
        this->charging_stations = (auto_warehousing::Tray*)realloc(this->charging_stations, charging_stations_lengthT * sizeof(auto_warehousing::Tray));
      charging_stations_length = charging_stations_lengthT;
      for( uint32_t i = 0; i < charging_stations_length; i++){
      offset += this->st_charging_stations.deserialize(inbuffer + offset);
        memcpy( &(this->charging_stations[i]), &(this->st_charging_stations), sizeof(auto_warehousing::Tray));
      }
     return offset;
    }

    const char * getType(){ return GETFREECHARGINGSTATIONS; };
    const char * getMD5(){ return "7fb2a4c1b47848e858cbbcedcada5418"; };

  };

  class GetFreeChargingStations {
    public:
    typedef GetFreeChargingStationsRequest Request;
    typedef GetFreeChargingStationsResponse Response;
  };

}
#endif
