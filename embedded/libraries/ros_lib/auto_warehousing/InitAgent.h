#ifndef _ROS_SERVICE_InitAgent_h
#define _ROS_SERVICE_InitAgent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/WarehouseConfiguration.h"
#include "auto_warehousing/RobotConfiguration.h"

namespace auto_warehousing
{

static const char INITAGENT[] = "auto_warehousing/InitAgent";

  class InitAgentRequest : public ros::Msg
  {
    public:
      typedef auto_warehousing::WarehouseConfiguration _warehouse_configuration_type;
      _warehouse_configuration_type warehouse_configuration;
      typedef auto_warehousing::RobotConfiguration _robot_configuration_type;
      _robot_configuration_type robot_configuration;

    InitAgentRequest():
      warehouse_configuration(),
      robot_configuration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->warehouse_configuration.serialize(outbuffer + offset);
      offset += this->robot_configuration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->warehouse_configuration.deserialize(inbuffer + offset);
      offset += this->robot_configuration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INITAGENT; };
    const char * getMD5(){ return "616ec6ee0bb1d8936be91a8b38bee87b"; };

  };

  class InitAgentResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    InitAgentResponse():
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

    const char * getType(){ return INITAGENT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class InitAgent {
    public:
    typedef InitAgentRequest Request;
    typedef InitAgentResponse Response;
  };

}
#endif
