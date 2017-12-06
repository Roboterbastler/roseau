#ifndef _ROS_SERVICE_CorrectPose_h
#define _ROS_SERVICE_CorrectPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Odometry.h"

namespace ethzasl_icp_mapper
{

static const char CORRECTPOSE[] = "ethzasl_icp_mapper/CorrectPose";

  class CorrectPoseRequest : public ros::Msg
  {
    public:
      typedef nav_msgs::Odometry _odom_type;
      _odom_type odom;

    CorrectPoseRequest():
      odom()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->odom.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->odom.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CORRECTPOSE; };
    const char * getMD5(){ return "75d9701e058ed9a7608ba3dbc16b5b7e"; };

  };

  class CorrectPoseResponse : public ros::Msg
  {
    public:

    CorrectPoseResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return CORRECTPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class CorrectPose {
    public:
    typedef CorrectPoseRequest Request;
    typedef CorrectPoseResponse Response;
  };

}
#endif
