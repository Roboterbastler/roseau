#ifndef _ROS_SERVICE_NewPackageOutput_h
#define _ROS_SERVICE_NewPackageOutput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

static const char NEWPACKAGEOUTPUT[] = "auto_warehousing/NewPackageOutput";

  class NewPackageOutputRequest : public ros::Msg
  {
    public:
      typedef uint32_t _output_tray_id_type;
      _output_tray_id_type output_tray_id;
      typedef auto_warehousing::Package _package_type;
      _package_type package;

    NewPackageOutputRequest():
      output_tray_id(0),
      package()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->output_tray_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->output_tray_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->output_tray_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->output_tray_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->output_tray_id);
      offset += this->package.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->output_tray_id =  ((uint32_t) (*(inbuffer + offset)));
      this->output_tray_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->output_tray_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->output_tray_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->output_tray_id);
      offset += this->package.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return NEWPACKAGEOUTPUT; };
    const char * getMD5(){ return "a125f676032abd5b27a2760fddee356c"; };

  };

  class NewPackageOutputResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    NewPackageOutputResponse():
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

    const char * getType(){ return NEWPACKAGEOUTPUT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class NewPackageOutput {
    public:
    typedef NewPackageOutputRequest Request;
    typedef NewPackageOutputResponse Response;
  };

}
#endif
