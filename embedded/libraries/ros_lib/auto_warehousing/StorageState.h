#ifndef _ROS_auto_warehousing_StorageState_h
#define _ROS_auto_warehousing_StorageState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "auto_warehousing/TrayState.h"

namespace auto_warehousing
{

  class StorageState : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      uint32_t tray_states_length;
      typedef auto_warehousing::TrayState _tray_states_type;
      _tray_states_type st_tray_states;
      _tray_states_type * tray_states;

    StorageState():
      stamp(),
      tray_states_length(0), tray_states(NULL)
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
      *(outbuffer + offset + 0) = (this->tray_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tray_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tray_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tray_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tray_states_length);
      for( uint32_t i = 0; i < tray_states_length; i++){
      offset += this->tray_states[i].serialize(outbuffer + offset);
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
      uint32_t tray_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tray_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tray_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tray_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tray_states_length);
      if(tray_states_lengthT > tray_states_length)
        this->tray_states = (auto_warehousing::TrayState*)realloc(this->tray_states, tray_states_lengthT * sizeof(auto_warehousing::TrayState));
      tray_states_length = tray_states_lengthT;
      for( uint32_t i = 0; i < tray_states_length; i++){
      offset += this->st_tray_states.deserialize(inbuffer + offset);
        memcpy( &(this->tray_states[i]), &(this->st_tray_states), sizeof(auto_warehousing::TrayState));
      }
     return offset;
    }

    const char * getType(){ return "auto_warehousing/StorageState"; };
    const char * getMD5(){ return "f58a17d0041d1e3c68f904805f0526cc"; };

  };

}
#endif