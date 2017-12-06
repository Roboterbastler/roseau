#ifndef _ROS_SERVICE_LoadMap_h
#define _ROS_SERVICE_LoadMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace ethzasl_icp_mapper
{

static const char LOADMAP[] = "ethzasl_icp_mapper/LoadMap";

  class LoadMapRequest : public ros::Msg
  {
    public:
      typedef std_msgs::String _filename_type;
      _filename_type filename;

    LoadMapRequest():
      filename()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->filename.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->filename.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return LOADMAP; };
    const char * getMD5(){ return "716e25f9d9dc76ceba197f93cbf05dc7"; };

  };

  class LoadMapResponse : public ros::Msg
  {
    public:

    LoadMapResponse()
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

    const char * getType(){ return LOADMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class LoadMap {
    public:
    typedef LoadMapRequest Request;
    typedef LoadMapResponse Response;
  };

}
#endif
