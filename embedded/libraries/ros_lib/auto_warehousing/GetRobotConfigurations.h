#ifndef _ROS_SERVICE_GetRobotConfigurations_h
#define _ROS_SERVICE_GetRobotConfigurations_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"

namespace auto_warehousing
{

static const char GETROBOTCONFIGURATIONS[] = "auto_warehousing/GetRobotConfigurations";

  class GetRobotConfigurationsRequest : public ros::Msg
  {
    public:

    GetRobotConfigurationsRequest()
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

    const char * getType(){ return GETROBOTCONFIGURATIONS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRobotConfigurationsResponse : public ros::Msg
  {
    public:
      uint32_t configs_length;
      typedef auto_warehousing::RobotConfiguration _configs_type;
      _configs_type st_configs;
      _configs_type * configs;

    GetRobotConfigurationsResponse():
      configs_length(0), configs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->configs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->configs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->configs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->configs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->configs_length);
      for( uint32_t i = 0; i < configs_length; i++){
      offset += this->configs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t configs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      configs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      configs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      configs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->configs_length);
      if(configs_lengthT > configs_length)
        this->configs = (auto_warehousing::RobotConfiguration*)realloc(this->configs, configs_lengthT * sizeof(auto_warehousing::RobotConfiguration));
      configs_length = configs_lengthT;
      for( uint32_t i = 0; i < configs_length; i++){
      offset += this->st_configs.deserialize(inbuffer + offset);
        memcpy( &(this->configs[i]), &(this->st_configs), sizeof(auto_warehousing::RobotConfiguration));
      }
     return offset;
    }

    const char * getType(){ return GETROBOTCONFIGURATIONS; };
    const char * getMD5(){ return "4af00ad841eaed229126db0b4270d254"; };

  };

  class GetRobotConfigurations {
    public:
    typedef GetRobotConfigurationsRequest Request;
    typedef GetRobotConfigurationsResponse Response;
  };

}
#endif
