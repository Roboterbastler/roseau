#ifndef _ROS_SERVICE_InitChargingManagement_h
#define _ROS_SERVICE_InitChargingManagement_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/WarehouseConfiguration.h"

namespace auto_warehousing
{

static const char INITCHARGINGMANAGEMENT[] = "auto_warehousing/InitChargingManagement";

  class InitChargingManagementRequest : public ros::Msg
  {
    public:
      typedef auto_warehousing::WarehouseConfiguration _warehouse_configuration_type;
      _warehouse_configuration_type warehouse_configuration;

    InitChargingManagementRequest():
      warehouse_configuration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->warehouse_configuration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->warehouse_configuration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INITCHARGINGMANAGEMENT; };
    const char * getMD5(){ return "8e7a6b6ded628f457b11b476368a8509"; };

  };

  class InitChargingManagementResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    InitChargingManagementResponse():
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

    const char * getType(){ return INITCHARGINGMANAGEMENT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class InitChargingManagement {
    public:
    typedef InitChargingManagementRequest Request;
    typedef InitChargingManagementResponse Response;
  };

}
#endif
