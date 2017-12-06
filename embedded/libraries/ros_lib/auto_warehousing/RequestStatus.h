#ifndef _ROS_auto_warehousing_RequestStatus_h
#define _ROS_auto_warehousing_RequestStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "auto_warehousing/PackageConfiguration.h"

namespace auto_warehousing
{

  class RequestStatus : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _type_type;
      _type_type type;
      typedef auto_warehousing::PackageConfiguration _pkg_config_type;
      _pkg_config_type pkg_config;
      typedef ros::Time _create_time_type;
      _create_time_type create_time;
      typedef const char* _status_type;
      _status_type status;

    RequestStatus():
      stamp(),
      id(0),
      type(""),
      pkg_config(),
      create_time(),
      status("")
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
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += this->pkg_config.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->create_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->create_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->create_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->create_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->create_time.sec);
      *(outbuffer + offset + 0) = (this->create_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->create_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->create_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->create_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->create_time.nsec);
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
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
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += this->pkg_config.deserialize(inbuffer + offset);
      this->create_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->create_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->create_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->create_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->create_time.sec);
      this->create_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->create_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->create_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->create_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->create_time.nsec);
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    const char * getType(){ return "auto_warehousing/RequestStatus"; };
    const char * getMD5(){ return "bc3a3dfca62979fa9ca3cdbb8d695ce9"; };

  };

}
#endif