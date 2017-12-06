#ifndef _ROS_SERVICE_GetPackageConfigurations_h
#define _ROS_SERVICE_GetPackageConfigurations_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/PackageConfiguration.h"

namespace auto_warehousing
{

static const char GETPACKAGECONFIGURATIONS[] = "auto_warehousing/GetPackageConfigurations";

  class GetPackageConfigurationsRequest : public ros::Msg
  {
    public:

    GetPackageConfigurationsRequest()
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

    const char * getType(){ return GETPACKAGECONFIGURATIONS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetPackageConfigurationsResponse : public ros::Msg
  {
    public:
      uint32_t configs_length;
      typedef auto_warehousing::PackageConfiguration _configs_type;
      _configs_type st_configs;
      _configs_type * configs;

    GetPackageConfigurationsResponse():
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
        this->configs = (auto_warehousing::PackageConfiguration*)realloc(this->configs, configs_lengthT * sizeof(auto_warehousing::PackageConfiguration));
      configs_length = configs_lengthT;
      for( uint32_t i = 0; i < configs_length; i++){
      offset += this->st_configs.deserialize(inbuffer + offset);
        memcpy( &(this->configs[i]), &(this->st_configs), sizeof(auto_warehousing::PackageConfiguration));
      }
     return offset;
    }

    const char * getType(){ return GETPACKAGECONFIGURATIONS; };
    const char * getMD5(){ return "6c79e4d48272b30033eb439274215257"; };

  };

  class GetPackageConfigurations {
    public:
    typedef GetPackageConfigurationsRequest Request;
    typedef GetPackageConfigurationsResponse Response;
  };

}
#endif
