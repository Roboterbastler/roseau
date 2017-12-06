#ifndef _ROS_auto_warehousing_TrayState_h
#define _ROS_auto_warehousing_TrayState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

  class TrayState : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef bool _occupied_type;
      _occupied_type occupied;
      typedef bool _available_type;
      _available_type available;
      typedef auto_warehousing::Package _package_type;
      _package_type package;

    TrayState():
      id(0),
      occupied(0),
      available(0),
      package()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        bool real;
        uint8_t base;
      } u_occupied;
      u_occupied.real = this->occupied;
      *(outbuffer + offset + 0) = (u_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->occupied);
      union {
        bool real;
        uint8_t base;
      } u_available;
      u_available.real = this->available;
      *(outbuffer + offset + 0) = (u_available.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->available);
      offset += this->package.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      union {
        bool real;
        uint8_t base;
      } u_occupied;
      u_occupied.base = 0;
      u_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->occupied = u_occupied.real;
      offset += sizeof(this->occupied);
      union {
        bool real;
        uint8_t base;
      } u_available;
      u_available.base = 0;
      u_available.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->available = u_available.real;
      offset += sizeof(this->available);
      offset += this->package.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/TrayState"; };
    const char * getMD5(){ return "643c502f6bd6aed46ad54aaea2358f46"; };

  };

}
#endif