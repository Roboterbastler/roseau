#ifndef _ROS_SERVICE_GetWarehouseConfig_h
#define _ROS_SERVICE_GetWarehouseConfig_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/WarehouseConfiguration.h"

namespace auto_warehousing
{

static const char GETWAREHOUSECONFIG[] = "auto_warehousing/GetWarehouseConfig";

  class GetWarehouseConfigRequest : public ros::Msg
  {
    public:

    GetWarehouseConfigRequest()
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

    const char * getType(){ return GETWAREHOUSECONFIG; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetWarehouseConfigResponse : public ros::Msg
  {
    public:
      typedef auto_warehousing::WarehouseConfiguration _warehouse_configuration_type;
      _warehouse_configuration_type warehouse_configuration;

    GetWarehouseConfigResponse():
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

    const char * getType(){ return GETWAREHOUSECONFIG; };
    const char * getMD5(){ return "8e7a6b6ded628f457b11b476368a8509"; };

  };

  class GetWarehouseConfig {
    public:
    typedef GetWarehouseConfigRequest Request;
    typedef GetWarehouseConfigResponse Response;
  };

}
#endif
