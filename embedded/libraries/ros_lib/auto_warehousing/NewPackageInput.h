#ifndef _ROS_SERVICE_NewPackageInput_h
#define _ROS_SERVICE_NewPackageInput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

static const char NEWPACKAGEINPUT[] = "auto_warehousing/NewPackageInput";

  class NewPackageInputRequest : public ros::Msg
  {
    public:
      typedef uint32_t _input_tray_id_type;
      _input_tray_id_type input_tray_id;
      typedef auto_warehousing::Package _package_type;
      _package_type package;

    NewPackageInputRequest():
      input_tray_id(0),
      package()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->input_tray_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->input_tray_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->input_tray_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->input_tray_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_tray_id);
      offset += this->package.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->input_tray_id =  ((uint32_t) (*(inbuffer + offset)));
      this->input_tray_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->input_tray_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->input_tray_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->input_tray_id);
      offset += this->package.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return NEWPACKAGEINPUT; };
    const char * getMD5(){ return "df45f852bccb44331749ba7d917473e4"; };

  };

  class NewPackageInputResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    NewPackageInputResponse():
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

    const char * getType(){ return NEWPACKAGEINPUT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class NewPackageInput {
    public:
    typedef NewPackageInputRequest Request;
    typedef NewPackageInputResponse Response;
  };

}
#endif
