#ifndef _ROS_SERVICE_RegisterAgent_h
#define _ROS_SERVICE_RegisterAgent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"

namespace auto_warehousing
{

static const char REGISTERAGENT[] = "auto_warehousing/RegisterAgent";

  class RegisterAgentRequest : public ros::Msg
  {
    public:
      typedef const char* _agent_id_type;
      _agent_id_type agent_id;
      typedef auto_warehousing::RobotConfiguration _robot_configuration_type;
      _robot_configuration_type robot_configuration;

    RegisterAgentRequest():
      agent_id(""),
      robot_configuration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_agent_id = strlen(this->agent_id);
      varToArr(outbuffer + offset, length_agent_id);
      offset += 4;
      memcpy(outbuffer + offset, this->agent_id, length_agent_id);
      offset += length_agent_id;
      offset += this->robot_configuration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_agent_id;
      arrToVar(length_agent_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_agent_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_agent_id-1]=0;
      this->agent_id = (char *)(inbuffer + offset-1);
      offset += length_agent_id;
      offset += this->robot_configuration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return REGISTERAGENT; };
    const char * getMD5(){ return "6d235eee01600da7f0ee97677901a2ce"; };

  };

  class RegisterAgentResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    RegisterAgentResponse():
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

    const char * getType(){ return REGISTERAGENT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class RegisterAgent {
    public:
    typedef RegisterAgentRequest Request;
    typedef RegisterAgentResponse Response;
  };

}
#endif
