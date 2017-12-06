#ifndef _ROS_auto_warehousing_TaskState_h
#define _ROS_auto_warehousing_TaskState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ros/duration.h"
#include "auto_warehousing/Package.h"

namespace auto_warehousing
{

  class TaskState : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _status_type;
      _status_type status;
      typedef ros::Time _requestCreateTime_type;
      _requestCreateTime_type requestCreateTime;
      typedef ros::Time _runTime_type;
      _runTime_type runTime;
      typedef ros::Time _loadTime_type;
      _loadTime_type loadTime;
      typedef ros::Time _unloadTime_type;
      _unloadTime_type unloadTime;
      typedef ros::Duration _estimatedDuration_type;
      _estimatedDuration_type estimatedDuration;
      typedef const char* _robot_type;
      _robot_type robot;
      typedef auto_warehousing::Package _package_type;
      _package_type package;
      typedef uint32_t _sourceTray_type;
      _sourceTray_type sourceTray;
      typedef uint32_t _targetTray_type;
      _targetTray_type targetTray;

    TaskState():
      id(0),
      status(""),
      requestCreateTime(),
      runTime(),
      loadTime(),
      unloadTime(),
      estimatedDuration(),
      robot(""),
      package(),
      sourceTray(0),
      targetTray(0)
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
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      *(outbuffer + offset + 0) = (this->requestCreateTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->requestCreateTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->requestCreateTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->requestCreateTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requestCreateTime.sec);
      *(outbuffer + offset + 0) = (this->requestCreateTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->requestCreateTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->requestCreateTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->requestCreateTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->requestCreateTime.nsec);
      *(outbuffer + offset + 0) = (this->runTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->runTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->runTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->runTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->runTime.sec);
      *(outbuffer + offset + 0) = (this->runTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->runTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->runTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->runTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->runTime.nsec);
      *(outbuffer + offset + 0) = (this->loadTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loadTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loadTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loadTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loadTime.sec);
      *(outbuffer + offset + 0) = (this->loadTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loadTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loadTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loadTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loadTime.nsec);
      *(outbuffer + offset + 0) = (this->unloadTime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->unloadTime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->unloadTime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->unloadTime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->unloadTime.sec);
      *(outbuffer + offset + 0) = (this->unloadTime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->unloadTime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->unloadTime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->unloadTime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->unloadTime.nsec);
      *(outbuffer + offset + 0) = (this->estimatedDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimatedDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimatedDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimatedDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimatedDuration.sec);
      *(outbuffer + offset + 0) = (this->estimatedDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimatedDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->estimatedDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->estimatedDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimatedDuration.nsec);
      uint32_t length_robot = strlen(this->robot);
      varToArr(outbuffer + offset, length_robot);
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      offset += this->package.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sourceTray >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sourceTray >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sourceTray >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sourceTray >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sourceTray);
      *(outbuffer + offset + 0) = (this->targetTray >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->targetTray >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->targetTray >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->targetTray >> (8 * 3)) & 0xFF;
      offset += sizeof(this->targetTray);
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
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
      this->requestCreateTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->requestCreateTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->requestCreateTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->requestCreateTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->requestCreateTime.sec);
      this->requestCreateTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->requestCreateTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->requestCreateTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->requestCreateTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->requestCreateTime.nsec);
      this->runTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->runTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->runTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->runTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->runTime.sec);
      this->runTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->runTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->runTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->runTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->runTime.nsec);
      this->loadTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->loadTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loadTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->loadTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->loadTime.sec);
      this->loadTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->loadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->loadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->loadTime.nsec);
      this->unloadTime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->unloadTime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->unloadTime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->unloadTime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->unloadTime.sec);
      this->unloadTime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->unloadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->unloadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->unloadTime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->unloadTime.nsec);
      this->estimatedDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimatedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimatedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimatedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimatedDuration.sec);
      this->estimatedDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->estimatedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->estimatedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->estimatedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->estimatedDuration.nsec);
      uint32_t length_robot;
      arrToVar(length_robot, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
      offset += this->package.deserialize(inbuffer + offset);
      this->sourceTray =  ((uint32_t) (*(inbuffer + offset)));
      this->sourceTray |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sourceTray |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sourceTray |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sourceTray);
      this->targetTray =  ((uint32_t) (*(inbuffer + offset)));
      this->targetTray |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->targetTray |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->targetTray |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->targetTray);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/TaskState"; };
    const char * getMD5(){ return "b2297c0e49c8c648ed6360e170926b8d"; };

  };

}
#endif