#ifndef _ROS_auto_warehousing_TraySensor_h
#define _ROS_auto_warehousing_TraySensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace auto_warehousing
{

  class TraySensor : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint32_t _tray_id_type;
      _tray_id_type tray_id;
      typedef bool _occupied_type;
      _occupied_type occupied;
      typedef const char* _package_type;
      _package_type package;

    TraySensor():
      stamp(),
      tray_id(0),
      occupied(0),
      package("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      *(outbuffer + offset + 0) = (this->tray_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tray_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tray_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tray_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tray_id);
      union {
        bool real;
        uint8_t base;
      } u_occupied;
      u_occupied.real = this->occupied;
      *(outbuffer + offset + 0) = (u_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->occupied);
      uint32_t length_package = strlen(this->package);
      varToArr(outbuffer + offset, length_package);
      offset += 4;
      memcpy(outbuffer + offset, this->package, length_package);
      offset += length_package;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      this->tray_id =  ((uint32_t) (*(inbuffer + offset)));
      this->tray_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tray_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tray_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tray_id);
      union {
        bool real;
        uint8_t base;
      } u_occupied;
      u_occupied.base = 0;
      u_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->occupied = u_occupied.real;
      offset += sizeof(this->occupied);
      uint32_t length_package;
      arrToVar(length_package, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_package; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_package-1]=0;
      this->package = (char *)(inbuffer + offset-1);
      offset += length_package;
     return offset;
    }

    const char * getType(){ return "auto_warehousing/TraySensor"; };
    const char * getMD5(){ return "725e9e6d6f2ca4eb3fe26342aa2d5180"; };

  };

}
#endif