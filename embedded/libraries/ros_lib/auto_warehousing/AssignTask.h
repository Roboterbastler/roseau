#ifndef _ROS_SERVICE_AssignTask_h
#define _ROS_SERVICE_AssignTask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

static const char ASSIGNTASK[] = "auto_warehousing/AssignTask";

  class AssignTaskRequest : public ros::Msg
  {
    public:
      typedef uint32_t _task_id_type;
      _task_id_type task_id;

    AssignTaskRequest():
      task_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->task_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->task_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->task_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->task_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->task_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->task_id =  ((uint32_t) (*(inbuffer + offset)));
      this->task_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->task_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->task_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->task_id);
     return offset;
    }

    const char * getType(){ return ASSIGNTASK; };
    const char * getMD5(){ return "01f8cf8853582efbb17391a60263fd03"; };

  };

  class AssignTaskResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    AssignTaskResponse():
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

    const char * getType(){ return ASSIGNTASK; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class AssignTask {
    public:
    typedef AssignTaskRequest Request;
    typedef AssignTaskResponse Response;
  };

}
#endif
