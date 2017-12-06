#ifndef _ROS_auto_warehousing_Tray_h
#define _ROS_auto_warehousing_Tray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

  class Tray : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _type_type;
      _type_type type;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _orientation_type;
      _orientation_type orientation;
      typedef float _max_load_type;
      _max_load_type max_load;
      typedef uint32_t _package_type_type;
      _package_type_type package_type;

    Tray():
      id(0),
      type(""),
      x(0),
      y(0),
      orientation(0),
      max_load(0),
      package_type(0)
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
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_orientation;
      u_orientation.real = this->orientation;
      *(outbuffer + offset + 0) = (u_orientation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation);
      union {
        float real;
        uint32_t base;
      } u_max_load;
      u_max_load.real = this->max_load;
      *(outbuffer + offset + 0) = (u_max_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_load.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_load.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_load.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_load);
      *(outbuffer + offset + 0) = (this->package_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->package_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->package_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->package_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->package_type);
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
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_orientation;
      u_orientation.base = 0;
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orientation = u_orientation.real;
      offset += sizeof(this->orientation);
      union {
        float real;
        uint32_t base;
      } u_max_load;
      u_max_load.base = 0;
      u_max_load.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_load.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_load.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_load.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_load = u_max_load.real;
      offset += sizeof(this->max_load);
      this->package_type =  ((uint32_t) (*(inbuffer + offset)));
      this->package_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->package_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->package_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->package_type);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/Tray"; };
    const char * getMD5(){ return "4ebddf5eeb28c15170ac6457775fa846"; };

  };

}
#endif