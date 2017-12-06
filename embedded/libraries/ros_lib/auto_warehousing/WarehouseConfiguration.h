#ifndef _ROS_auto_warehousing_WarehouseConfiguration_h
#define _ROS_auto_warehousing_WarehouseConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/Tray.h"
#include "auto_warehousing/TrayGeometry.h"
#include "nav_msgs/OccupancyGrid.h"
#include "auto_warehousing/PackagePool.h"
#include "auto_warehousing/Robot.h"
#include "auto_warehousing/IdlePosition.h"

namespace auto_warehousing
{

  class WarehouseConfiguration : public ros::Msg
  {
    public:
      typedef float _width_type;
      _width_type width;
      typedef float _height_type;
      _height_type height;
      uint32_t trays_length;
      typedef auto_warehousing::Tray _trays_type;
      _trays_type st_trays;
      _trays_type * trays;
      typedef auto_warehousing::TrayGeometry _tray_geometry_type;
      _tray_geometry_type tray_geometry;
      typedef nav_msgs::OccupancyGrid _occupancy_map_type;
      _occupancy_map_type occupancy_map;
      typedef auto_warehousing::PackagePool _package_pool_type;
      _package_pool_type package_pool;
      uint32_t robots_length;
      typedef auto_warehousing::Robot _robots_type;
      _robots_type st_robots;
      _robots_type * robots;
      uint32_t idle_positions_length;
      typedef auto_warehousing::IdlePosition _idle_positions_type;
      _idle_positions_type st_idle_positions;
      _idle_positions_type * idle_positions;

    WarehouseConfiguration():
      width(0),
      height(0),
      trays_length(0), trays(NULL),
      tray_geometry(),
      occupancy_map(),
      package_pool(),
      robots_length(0), robots(NULL),
      idle_positions_length(0), idle_positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->trays_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trays_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trays_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trays_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trays_length);
      for( uint32_t i = 0; i < trays_length; i++){
      offset += this->trays[i].serialize(outbuffer + offset);
      }
      offset += this->tray_geometry.serialize(outbuffer + offset);
      offset += this->occupancy_map.serialize(outbuffer + offset);
      offset += this->package_pool.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->robots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robots_length);
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->robots[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->idle_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->idle_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->idle_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->idle_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idle_positions_length);
      for( uint32_t i = 0; i < idle_positions_length; i++){
      offset += this->idle_positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      uint32_t trays_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trays_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trays_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trays_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trays_length);
      if(trays_lengthT > trays_length)
        this->trays = (auto_warehousing::Tray*)realloc(this->trays, trays_lengthT * sizeof(auto_warehousing::Tray));
      trays_length = trays_lengthT;
      for( uint32_t i = 0; i < trays_length; i++){
      offset += this->st_trays.deserialize(inbuffer + offset);
        memcpy( &(this->trays[i]), &(this->st_trays), sizeof(auto_warehousing::Tray));
      }
      offset += this->tray_geometry.deserialize(inbuffer + offset);
      offset += this->occupancy_map.deserialize(inbuffer + offset);
      offset += this->package_pool.deserialize(inbuffer + offset);
      uint32_t robots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robots_length);
      if(robots_lengthT > robots_length)
        this->robots = (auto_warehousing::Robot*)realloc(this->robots, robots_lengthT * sizeof(auto_warehousing::Robot));
      robots_length = robots_lengthT;
      for( uint32_t i = 0; i < robots_length; i++){
      offset += this->st_robots.deserialize(inbuffer + offset);
        memcpy( &(this->robots[i]), &(this->st_robots), sizeof(auto_warehousing::Robot));
      }
      uint32_t idle_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      idle_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      idle_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      idle_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->idle_positions_length);
      if(idle_positions_lengthT > idle_positions_length)
        this->idle_positions = (auto_warehousing::IdlePosition*)realloc(this->idle_positions, idle_positions_lengthT * sizeof(auto_warehousing::IdlePosition));
      idle_positions_length = idle_positions_lengthT;
      for( uint32_t i = 0; i < idle_positions_length; i++){
      offset += this->st_idle_positions.deserialize(inbuffer + offset);
        memcpy( &(this->idle_positions[i]), &(this->st_idle_positions), sizeof(auto_warehousing::IdlePosition));
      }
     return offset;
    }

    const char * getType(){ return "auto_warehousing/WarehouseConfiguration"; };
    const char * getMD5(){ return "7a9a966e76f230d9d76139a4d65bf5e1"; };

  };

}
#endif