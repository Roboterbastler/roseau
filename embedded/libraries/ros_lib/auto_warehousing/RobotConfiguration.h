#ifndef _ROS_auto_warehousing_RobotConfiguration_h
#define _ROS_auto_warehousing_RobotConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

  class RobotConfiguration : public ros::Msg
  {
    public:
      typedef const char* _type_name_type;
      _type_name_type type_name;
      typedef float _charging_rate_type;
      _charging_rate_type charging_rate;
      typedef float _discharging_rate_type;
      _discharging_rate_type discharging_rate;
      typedef float _min_linear_vel_type;
      _min_linear_vel_type min_linear_vel;
      typedef float _max_linear_vel_type;
      _max_linear_vel_type max_linear_vel;
      typedef float _max_angular_vel_type;
      _max_angular_vel_type max_angular_vel;
      typedef float _radius_type;
      _radius_type radius;
      typedef float _max_load_type;
      _max_load_type max_load;

    RobotConfiguration():
      type_name(""),
      charging_rate(0),
      discharging_rate(0),
      min_linear_vel(0),
      max_linear_vel(0),
      max_angular_vel(0),
      radius(0),
      max_load(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type_name = strlen(this->type_name);
      varToArr(outbuffer + offset, length_type_name);
      offset += 4;
      memcpy(outbuffer + offset, this->type_name, length_type_name);
      offset += length_type_name;
      union {
        float real;
        uint32_t base;
      } u_charging_rate;
      u_charging_rate.real = this->charging_rate;
      *(outbuffer + offset + 0) = (u_charging_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charging_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charging_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charging_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charging_rate);
      union {
        float real;
        uint32_t base;
      } u_discharging_rate;
      u_discharging_rate.real = this->discharging_rate;
      *(outbuffer + offset + 0) = (u_discharging_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharging_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharging_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharging_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->discharging_rate);
      union {
        float real;
        uint32_t base;
      } u_min_linear_vel;
      u_min_linear_vel.real = this->min_linear_vel;
      *(outbuffer + offset + 0) = (u_min_linear_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_linear_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_linear_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_linear_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_linear_vel;
      u_max_linear_vel.real = this->max_linear_vel;
      *(outbuffer + offset + 0) = (u_max_linear_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_linear_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_linear_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_linear_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_angular_vel;
      u_max_angular_vel.real = this->max_angular_vel;
      *(outbuffer + offset + 0) = (u_max_angular_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_angular_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_angular_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_angular_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_angular_vel);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.real = this->radius;
      *(outbuffer + offset + 0) = (u_radius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type_name;
      arrToVar(length_type_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type_name-1]=0;
      this->type_name = (char *)(inbuffer + offset-1);
      offset += length_type_name;
      union {
        float real;
        uint32_t base;
      } u_charging_rate;
      u_charging_rate.base = 0;
      u_charging_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charging_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charging_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charging_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charging_rate = u_charging_rate.real;
      offset += sizeof(this->charging_rate);
      union {
        float real;
        uint32_t base;
      } u_discharging_rate;
      u_discharging_rate.base = 0;
      u_discharging_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharging_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharging_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharging_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->discharging_rate = u_discharging_rate.real;
      offset += sizeof(this->discharging_rate);
      union {
        float real;
        uint32_t base;
      } u_min_linear_vel;
      u_min_linear_vel.base = 0;
      u_min_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_linear_vel = u_min_linear_vel.real;
      offset += sizeof(this->min_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_linear_vel;
      u_max_linear_vel.base = 0;
      u_max_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_linear_vel = u_max_linear_vel.real;
      offset += sizeof(this->max_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_angular_vel;
      u_max_angular_vel.base = 0;
      u_max_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_angular_vel = u_max_angular_vel.real;
      offset += sizeof(this->max_angular_vel);
      union {
        float real;
        uint32_t base;
      } u_radius;
      u_radius.base = 0;
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius = u_radius.real;
      offset += sizeof(this->radius);
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
     return offset;
    }

    const char * getType(){ return "auto_warehousing/RobotConfiguration"; };
    const char * getMD5(){ return "a088bac167b7075ab4169c49586042e9"; };

  };

}
#endif