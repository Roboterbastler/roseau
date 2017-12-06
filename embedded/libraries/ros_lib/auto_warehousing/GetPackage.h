#ifndef _ROS_SERVICE_GetPackage_h
#define _ROS_SERVICE_GetPackage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

static const char GETPACKAGE[] = "auto_warehousing/GetPackage";

  class GetPackageRequest : public ros::Msg
  {
    public:
      typedef uint32_t _trayId_type;
      _trayId_type trayId;

    GetPackageRequest():
      trayId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trayId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trayId >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trayId >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trayId >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trayId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->trayId =  ((uint32_t) (*(inbuffer + offset)));
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trayId);
     return offset;
    }

    const char * getType(){ return GETPACKAGE; };
    const char * getMD5(){ return "1f5323c6390f45b7203b662400a202be"; };

  };

  class GetPackageResponse : public ros::Msg
  {
    public:
      typedef auto_warehousing::Package _pkg_type;
      _pkg_type pkg;

    GetPackageResponse():
      pkg()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pkg.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pkg.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETPACKAGE; };
    const char * getMD5(){ return "964ad4c4a68ecf41ce5ed223a2a4d2cc"; };

  };

  class GetPackage {
    public:
    typedef GetPackageRequest Request;
    typedef GetPackageResponse Response;
  };

}
#endif
