#ifndef _ROS_SERVICE_GetStorageState_h
#define _ROS_SERVICE_GetStorageState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/StorageState.h"

namespace auto_warehousing
{

static const char GETSTORAGESTATE[] = "auto_warehousing/GetStorageState";

  class GetStorageStateRequest : public ros::Msg
  {
    public:

    GetStorageStateRequest()
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

    const char * getType(){ return GETSTORAGESTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetStorageStateResponse : public ros::Msg
  {
    public:
      typedef auto_warehousing::StorageState _state_type;
      _state_type state;

    GetStorageStateResponse():
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETSTORAGESTATE; };
    const char * getMD5(){ return "8daf70e0db11146ef116dfad6f35d7dc"; };

  };

  class GetStorageState {
    public:
    typedef GetStorageStateRequest Request;
    typedef GetStorageStateResponse Response;
  };

}
#endif
