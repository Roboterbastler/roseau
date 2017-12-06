#ifndef _ROS_SERVICE_GetLocalPath_h
#define _ROS_SERVICE_GetLocalPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/RobotConfiguration.h"
#include "geometry_msgs/Point.h"

namespace auto_warehousing
{

static const char GETLOCALPATH[] = "auto_warehousing/GetLocalPath";

  class GetLocalPathRequest : public ros::Msg
  {
    public:
      typedef const char* _agent_id_type;
      _agent_id_type agent_id;
      uint32_t robots_path_length;
      typedef geometry_msgs::Point _robots_path_type;
      _robots_path_type st_robots_path;
      _robots_path_type * robots_path;
      typedef auto_warehousing::RobotConfiguration _robot_config_type;
      _robot_config_type robot_config;
      typedef geometry_msgs::Point _next_position_type;
      _next_position_type next_position;
      typedef geometry_msgs::Point _goal_position_type;
      _goal_position_type goal_position;
      typedef geometry_msgs::Point _robot_position_type;
      _robot_position_type robot_position;
      uint32_t obstacles_length;
      typedef geometry_msgs::Point _obstacles_type;
      _obstacles_type st_obstacles;
      _obstacles_type * obstacles;

    GetLocalPathRequest():
      agent_id(""),
      robots_path_length(0), robots_path(NULL),
      robot_config(),
      next_position(),
      goal_position(),
      robot_position(),
      obstacles_length(0), obstacles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_agent_id = strlen(this->agent_id);
      varToArr(outbuffer + offset, length_agent_id);
      offset += 4;
      memcpy(outbuffer + offset, this->agent_id, length_agent_id);
      offset += length_agent_id;
      *(outbuffer + offset + 0) = (this->robots_path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robots_path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robots_path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robots_path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robots_path_length);
      for( uint32_t i = 0; i < robots_path_length; i++){
      offset += this->robots_path[i].serialize(outbuffer + offset);
      }
      offset += this->robot_config.serialize(outbuffer + offset);
      offset += this->next_position.serialize(outbuffer + offset);
      offset += this->goal_position.serialize(outbuffer + offset);
      offset += this->robot_position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->obstacles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obstacles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obstacles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obstacles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacles_length);
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->obstacles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_agent_id;
      arrToVar(length_agent_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_agent_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_agent_id-1]=0;
      this->agent_id = (char *)(inbuffer + offset-1);
      offset += length_agent_id;
      uint32_t robots_path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robots_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robots_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robots_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robots_path_length);
      if(robots_path_lengthT > robots_path_length)
        this->robots_path = (geometry_msgs::Point*)realloc(this->robots_path, robots_path_lengthT * sizeof(geometry_msgs::Point));
      robots_path_length = robots_path_lengthT;
      for( uint32_t i = 0; i < robots_path_length; i++){
      offset += this->st_robots_path.deserialize(inbuffer + offset);
        memcpy( &(this->robots_path[i]), &(this->st_robots_path), sizeof(geometry_msgs::Point));
      }
      offset += this->robot_config.deserialize(inbuffer + offset);
      offset += this->next_position.deserialize(inbuffer + offset);
      offset += this->goal_position.deserialize(inbuffer + offset);
      offset += this->robot_position.deserialize(inbuffer + offset);
      uint32_t obstacles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      obstacles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->obstacles_length);
      if(obstacles_lengthT > obstacles_length)
        this->obstacles = (geometry_msgs::Point*)realloc(this->obstacles, obstacles_lengthT * sizeof(geometry_msgs::Point));
      obstacles_length = obstacles_lengthT;
      for( uint32_t i = 0; i < obstacles_length; i++){
      offset += this->st_obstacles.deserialize(inbuffer + offset);
        memcpy( &(this->obstacles[i]), &(this->st_obstacles), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return GETLOCALPATH; };
    const char * getMD5(){ return "db492bb913446481ce8c861eb7241b44"; };

  };

  class GetLocalPathResponse : public ros::Msg
  {
    public:
      uint32_t path_length;
      typedef geometry_msgs::Point _path_type;
      _path_type st_path;
      _path_type * path;
      typedef float _length_type;
      _length_type length;

    GetLocalPathResponse():
      path_length(0), path(NULL),
      length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->path_length);
      if(path_lengthT > path_length)
        this->path = (geometry_msgs::Point*)realloc(this->path, path_lengthT * sizeof(geometry_msgs::Point));
      path_length = path_lengthT;
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(geometry_msgs::Point));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->length));
     return offset;
    }

    const char * getType(){ return GETLOCALPATH; };
    const char * getMD5(){ return "05f2a111bf2586d56e616a7872fdb2c3"; };

  };

  class GetLocalPath {
    public:
    typedef GetLocalPathRequest Request;
    typedef GetLocalPathResponse Response;
  };

}
#endif
