#ifndef _ROS_SERVICE_GetTrayState_h
#define _ROS_SERVICE_GetTrayState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "auto_warehousing/TrayState.h"

namespace auto_warehousing
{

static const char GETTRAYSTATE[] = "auto_warehousing/GetTrayState";

  class GetTrayStateRequest : public ros::Msg
  {
    public:
      typedef uint32_t _trayId_type;
      _trayId_type trayId;

    GetTrayStateRequest():
      trayId(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->trayId >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trayId >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trayId >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trayId >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trayId);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->trayId =  ((uint32_t) (*(inbuffer + offset)));
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trayId |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trayId);
     return offset;
    }

    const char * getType(){ return GETTRAYSTATE; };
    const char * getMD5(){ return "1f5323c6390f45b7203b662400a202be"; };

  };

  class GetTrayStateResponse : public ros::Msg
  {
    public:
      typedef auto_warehousing::TrayState _state_type;
      _state_type state;

    GetTrayStateResponse():
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

    const char * getType(){ return GETTRAYSTATE; };
    const char * getMD5(){ return "e8fc1740bf5eaf110ae8d47041b731e7"; };

  };

  class GetTrayState {
    public:
    typedef GetTrayStateRequest Request;
    typedef GetTrayStateResponse Response;
  };

}
#endif
