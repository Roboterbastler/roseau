#ifndef _ROS_auto_warehousing_RobotHeartbeat_h
#define _ROS_auto_warehousing_RobotHeartbeat_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

  class RobotHeartbeat : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef bool _idle_type;
      _idle_type idle;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef float _orientation_type;
      _orientation_type orientation;
      typedef float _battery_level_type;
      _battery_level_type battery_level;

    RobotHeartbeat():
      id(""),
      idle(0),
      position(),
      orientation(0),
      battery_level(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        bool real;
        uint8_t base;
      } u_idle;
      u_idle.real = this->idle;
      *(outbuffer + offset + 0) = (u_idle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->idle);
      offset += this->position.serialize(outbuffer + offset);
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
      } u_battery_level;
      u_battery_level.real = this->battery_level;
      *(outbuffer + offset + 0) = (u_battery_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_level);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        bool real;
        uint8_t base;
      } u_idle;
      u_idle.base = 0;
      u_idle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->idle = u_idle.real;
      offset += sizeof(this->idle);
      offset += this->position.deserialize(inbuffer + offset);
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
      } u_battery_level;
      u_battery_level.base = 0;
      u_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_level = u_battery_level.real;
      offset += sizeof(this->battery_level);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/RobotHeartbeat"; };
    const char * getMD5(){ return "ef842cd67db738b825bf6658ba45728d"; };

  };

}
#endif