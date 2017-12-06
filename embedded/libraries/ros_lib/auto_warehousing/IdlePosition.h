#ifndef _ROS_auto_warehousing_IdlePosition_h
#define _ROS_auto_warehousing_IdlePosition_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace auto_warehousing
{

  class IdlePosition : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef geometry_msgs::Pose2D _pose_type;
      _pose_type pose;

    IdlePosition():
      id(""),
      pose()
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
      offset += this->pose.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/IdlePosition"; };
    const char * getMD5(){ return "41501a2ca7f33857f2bd60720fb9d76a"; };

  };

}
#endif