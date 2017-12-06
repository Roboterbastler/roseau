#ifndef _ROS_SERVICE_initRoadmapPlanner_h
#define _ROS_SERVICE_initRoadmapPlanner_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/WarehouseConfiguration.h"
#include "auto_warehousing/RobotConfiguration.h"

namespace auto_warehousing
{

static const char INITROADMAPPLANNER[] = "auto_warehousing/initRoadmapPlanner";

  class initRoadmapPlannerRequest : public ros::Msg
  {
    public:
      typedef auto_warehousing::WarehouseConfiguration _warehouse_configuration_type;
      _warehouse_configuration_type warehouse_configuration;
      uint32_t robot_configurations_length;
      typedef auto_warehousing::RobotConfiguration _robot_configurations_type;
      _robot_configurations_type st_robot_configurations;
      _robot_configurations_type * robot_configurations;

    initRoadmapPlannerRequest():
      warehouse_configuration(),
      robot_configurations_length(0), robot_configurations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->warehouse_configuration.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->robot_configurations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robot_configurations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robot_configurations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robot_configurations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_configurations_length);
      for( uint32_t i = 0; i < robot_configurations_length; i++){
      offset += this->robot_configurations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->warehouse_configuration.deserialize(inbuffer + offset);
      uint32_t robot_configurations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robot_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robot_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robot_configurations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robot_configurations_length);
      if(robot_configurations_lengthT > robot_configurations_length)
        this->robot_configurations = (auto_warehousing::RobotConfiguration*)realloc(this->robot_configurations, robot_configurations_lengthT * sizeof(auto_warehousing::RobotConfiguration));
      robot_configurations_length = robot_configurations_lengthT;
      for( uint32_t i = 0; i < robot_configurations_length; i++){
      offset += this->st_robot_configurations.deserialize(inbuffer + offset);
        memcpy( &(this->robot_configurations[i]), &(this->st_robot_configurations), sizeof(auto_warehousing::RobotConfiguration));
      }
     return offset;
    }

    const char * getType(){ return INITROADMAPPLANNER; };
    const char * getMD5(){ return "1106688161591f99dbe7d9e6d8807407"; };

  };

  class initRoadmapPlannerResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    initRoadmapPlannerResponse():
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

    const char * getType(){ return INITROADMAPPLANNER; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class initRoadmapPlanner {
    public:
    typedef initRoadmapPlannerRequest Request;
    typedef initRoadmapPlannerResponse Response;
  };

}
#endif
