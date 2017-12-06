#ifndef _ROS_SERVICE_SetPackage_h
#define _ROS_SERVICE_SetPackage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

static const char SETPACKAGE[] = "auto_warehousing/SetPackage";

  class SetPackageRequest : public ros::Msg
  {
    public:
      typedef uint32_t _trayId_type;
      _trayId_type trayId;
      typedef auto_warehousing::Package _pkg_type;
      _pkg_type pkg;

    SetPackageRequest():
      trayId(0),
      pkg()
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
      offset += this->pkg.serialize(outbuffer + offset);
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
      offset += this->pkg.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETPACKAGE; };
    const char * getMD5(){ return "2bf9725e18218d881c4e6def49493469"; };

  };

  class SetPackageResponse : public ros::Msg
  {
    public:

    SetPackageResponse()
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

    const char * getType(){ return SETPACKAGE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPackage {
    public:
    typedef SetPackageRequest Request;
    typedef SetPackageResponse Response;
  };

}
#endif
