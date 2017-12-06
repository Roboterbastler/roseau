#ifndef _ROS_SERVICE_InitPackageGenerator_h
#define _ROS_SERVICE_InitPackageGenerator_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/PackageConfiguration.h"
#include "auto_warehousing/WarehouseConfiguration.h"

namespace auto_warehousing
{

static const char INITPACKAGEGENERATOR[] = "auto_warehousing/InitPackageGenerator";

  class InitPackageGeneratorRequest : public ros::Msg
  {
    public:
      typedef auto_warehousing::WarehouseConfiguration _warehouse_configuration_type;
      _warehouse_configuration_type warehouse_configuration;
      uint32_t package_configurations_length;
      typedef auto_warehousing::PackageConfiguration _package_configurations_type;
      _package_configurations_type st_package_configurations;
      _package_configurations_type * package_configurations;

    InitPackageGeneratorRequest():
      warehouse_configuration(),
      package_configurations_length(0), package_configurations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->warehouse_configuration.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->package_configurations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->package_configurations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->package_configurations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->package_configurations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->package_configurations_length);
      for( uint32_t i = 0; i < package_configurations_length; i++){
      offset += this->package_configurations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->warehouse_configuration.deserialize(inbuffer + offset);
      uint32_t package_configurations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      package_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      package_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      package_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->package_configurations_length);
      if(package_configurations_lengthT > package_configurations_length)
        this->package_configurations = (auto_warehousing::PackageConfiguration*)realloc(this->package_configurations, package_configurations_lengthT * sizeof(auto_warehousing::PackageConfiguration));
      package_configurations_length = package_configurations_lengthT;
      for( uint32_t i = 0; i < package_configurations_length; i++){
      offset += this->st_package_configurations.deserialize(inbuffer + offset);
        memcpy( &(this->package_configurations[i]), &(this->st_package_configurations), sizeof(auto_warehousing::PackageConfiguration));
      }
     return offset;
    }

    const char * getType(){ return INITPACKAGEGENERATOR; };
    const char * getMD5(){ return "5a55cac834b00525e8b72ae394675bd1"; };

  };

  class InitPackageGeneratorResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    InitPackageGeneratorResponse():
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

    const char * getType(){ return INITPACKAGEGENERATOR; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class InitPackageGenerator {
    public:
    typedef InitPackageGeneratorRequest Request;
    typedef InitPackageGeneratorResponse Response;
  };

}
#endif
