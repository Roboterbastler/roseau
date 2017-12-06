#ifndef _ROS_auto_warehousing_TaskPlannerState_h
#define _ROS_auto_warehousing_TaskPlannerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "auto_warehousing/RequestStatus.h"
#include "auto_warehousing/TaskState.h"

namespace auto_warehousing
{

  class TaskPlannerState : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint32_t _registered_robots_type;
      _registered_robots_type registered_robots;
      uint32_t requests_length;
      typedef auto_warehousing::RequestStatus _requests_type;
      _requests_type st_requests;
      _requests_type * requests;
      uint32_t tasks_length;
      typedef auto_warehousing::TaskState _tasks_type;
      _tasks_type st_tasks;
      _tasks_type * tasks;

    TaskPlannerState():
      stamp(),
      registered_robots(0),
      requests_length(0), requests(NULL),
      tasks_length(0), tasks(NULL)
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
      *(outbuffer + offset + 0) = (this->registered_robots >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->registered_robots >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->registered_robots >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->registered_robots >> (8 * 3)) & 0xFF;
      offset += sizeof(this->registered_robots);
      *(outbuffer + offset + 0) = (this->requests_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->requests_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->requests_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->requests_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requests_length);
      for( uint32_t i = 0; i < requests_length; i++){
      offset += this->requests[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->tasks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tasks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tasks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tasks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tasks_length);
      for( uint32_t i = 0; i < tasks_length; i++){
      offset += this->tasks[i].serialize(outbuffer + offset);
      }
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
      this->registered_robots =  ((uint32_t) (*(inbuffer + offset)));
      this->registered_robots |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->registered_robots |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->registered_robots |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->registered_robots);
      uint32_t requests_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      requests_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->requests_length);
      if(requests_lengthT > requests_length)
        this->requests = (auto_warehousing::RequestStatus*)realloc(this->requests, requests_lengthT * sizeof(auto_warehousing::RequestStatus));
      requests_length = requests_lengthT;
      for( uint32_t i = 0; i < requests_length; i++){
      offset += this->st_requests.deserialize(inbuffer + offset);
        memcpy( &(this->requests[i]), &(this->st_requests), sizeof(auto_warehousing::RequestStatus));
      }
      uint32_t tasks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tasks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tasks_length);
      if(tasks_lengthT > tasks_length)
        this->tasks = (auto_warehousing::TaskState*)realloc(this->tasks, tasks_lengthT * sizeof(auto_warehousing::TaskState));
      tasks_length = tasks_lengthT;
      for( uint32_t i = 0; i < tasks_length; i++){
      offset += this->st_tasks.deserialize(inbuffer + offset);
        memcpy( &(this->tasks[i]), &(this->st_tasks), sizeof(auto_warehousing::TaskState));
      }
     return offset;
    }

    const char * getType(){ return "auto_warehousing/TaskPlannerState"; };
    const char * getMD5(){ return "d68409037940351182a0a455e9df6526"; };

  };

}
#endif