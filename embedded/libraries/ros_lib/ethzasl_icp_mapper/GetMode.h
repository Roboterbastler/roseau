#ifndef _ROS_SERVICE_GetMode_h
#define _ROS_SERVICE_GetMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ethzasl_icp_mapper
{

static const char GETMODE[] = "ethzasl_icp_mapper/GetMode";

  class GetModeRequest : public ros::Msg
  {
    public:
      typedef bool _localize_type;
      _localize_type localize;
      typedef bool _map_type;
      _map_type map;
      typedef bool _applyChange_type;
      _applyChange_type applyChange;

    GetModeRequest():
      localize(0),
      map(0),
      applyChange(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_localize;
      u_localize.real = this->localize;
      *(outbuffer + offset + 0) = (u_localize.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->localize);
      union {
        bool real;
        uint8_t base;
      } u_map;
      u_map.real = this->map;
      *(outbuffer + offset + 0) = (u_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->map);
      union {
        bool real;
        uint8_t base;
      } u_applyChange;
      u_applyChange.real = this->applyChange;
      *(outbuffer + offset + 0) = (u_applyChange.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->applyChange);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_localize;
      u_localize.base = 0;
      u_localize.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->localize = u_localize.real;
      offset += sizeof(this->localize);
      union {
        bool real;
        uint8_t base;
      } u_map;
      u_map.base = 0;
      u_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->map = u_map.real;
      offset += sizeof(this->map);
      union {
        bool real;
        uint8_t base;
      } u_applyChange;
      u_applyChange.base = 0;
      u_applyChange.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->applyChange = u_applyChange.real;
      offset += sizeof(this->applyChange);
     return offset;
    }

    const char * getType(){ return GETMODE; };
    const char * getMD5(){ return "70da9f49c8aff1c1eadda36f4cb53efb"; };

  };

  class GetModeResponse : public ros::Msg
  {
    public:
      typedef bool _localize_type;
      _localize_type localize;
      typedef bool _map_type;
      _map_type map;

    GetModeResponse():
      localize(0),
      map(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_localize;
      u_localize.real = this->localize;
      *(outbuffer + offset + 0) = (u_localize.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->localize);
      union {
        bool real;
        uint8_t base;
      } u_map;
      u_map.real = this->map;
      *(outbuffer + offset + 0) = (u_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->map);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_localize;
      u_localize.base = 0;
      u_localize.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->localize = u_localize.real;
      offset += sizeof(this->localize);
      union {
        bool real;
        uint8_t base;
      } u_map;
      u_map.base = 0;
      u_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->map = u_map.real;
      offset += sizeof(this->map);
     return offset;
    }

    const char * getType(){ return GETMODE; };
    const char * getMD5(){ return "34feb3c27737328fa52508eefd06d5a5"; };

  };

  class GetMode {
    public:
    typedef GetModeRequest Request;
    typedef GetModeResponse Response;
  };

}
#endif
