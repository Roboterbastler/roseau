#ifndef _ROS_auto_warehousing_Package_h
#define _ROS_auto_warehousing_Package_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

  class Package : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _type_id_type;
      _type_id_type type_id;

    Package():
      id(0),
      type_id(0)
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
      *(outbuffer + offset + 0) = (this->type_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type_id);
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
      this->type_id =  ((uint32_t) (*(inbuffer + offset)));
      this->type_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type_id);
     return offset;
    }

    const char * getType(){ return "auto_warehousing/Package"; };
    const char * getMD5(){ return "deb8587ce4dfba7871cb511e3cf31f9d"; };

  };

}
#endif