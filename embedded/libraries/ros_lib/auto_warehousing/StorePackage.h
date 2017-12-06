#ifndef _ROS_SERVICE_StorePackage_h
#define _ROS_SERVICE_StorePackage_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace auto_warehousing
{

static const char STOREPACKAGE[] = "auto_warehousing/StorePackage";

  class StorePackageRequest : public ros::Msg
  {
    public:
      typedef uint32_t _task_id_type;
      _task_id_type task_id;
      uint32_t input_tray_ids_length;
      typedef uint32_t _input_tray_ids_type;
      _input_tray_ids_type st_input_tray_ids;
      _input_tray_ids_type * input_tray_ids;
      uint32_t storage_tray_ids_length;
      typedef uint32_t _storage_tray_ids_type;
      _storage_tray_ids_type st_storage_tray_ids;
      _storage_tray_ids_type * storage_tray_ids;

    StorePackageRequest():
      task_id(0),
      input_tray_ids_length(0), input_tray_ids(NULL),
      storage_tray_ids_length(0), storage_tray_ids(NULL)
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
      *(outbuffer + offset + 0) = (this->input_tray_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->input_tray_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->input_tray_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->input_tray_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_tray_ids_length);
      for( uint32_t i = 0; i < input_tray_ids_length; i++){
      *(outbuffer + offset + 0) = (this->input_tray_ids[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->input_tray_ids[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->input_tray_ids[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->input_tray_ids[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_tray_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->storage_tray_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->storage_tray_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->storage_tray_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->storage_tray_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->storage_tray_ids_length);
      for( uint32_t i = 0; i < storage_tray_ids_length; i++){
      *(outbuffer + offset + 0) = (this->storage_tray_ids[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->storage_tray_ids[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->storage_tray_ids[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->storage_tray_ids[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->storage_tray_ids[i]);
      }
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
      uint32_t input_tray_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      input_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      input_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      input_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->input_tray_ids_length);
      if(input_tray_ids_lengthT > input_tray_ids_length)
        this->input_tray_ids = (uint32_t*)realloc(this->input_tray_ids, input_tray_ids_lengthT * sizeof(uint32_t));
      input_tray_ids_length = input_tray_ids_lengthT;
      for( uint32_t i = 0; i < input_tray_ids_length; i++){
      this->st_input_tray_ids =  ((uint32_t) (*(inbuffer + offset)));
      this->st_input_tray_ids |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_input_tray_ids |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_input_tray_ids |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_input_tray_ids);
        memcpy( &(this->input_tray_ids[i]), &(this->st_input_tray_ids), sizeof(uint32_t));
      }
      uint32_t storage_tray_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      storage_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      storage_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      storage_tray_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->storage_tray_ids_length);
      if(storage_tray_ids_lengthT > storage_tray_ids_length)
        this->storage_tray_ids = (uint32_t*)realloc(this->storage_tray_ids, storage_tray_ids_lengthT * sizeof(uint32_t));
      storage_tray_ids_length = storage_tray_ids_lengthT;
      for( uint32_t i = 0; i < storage_tray_ids_length; i++){
      this->st_storage_tray_ids =  ((uint32_t) (*(inbuffer + offset)));
      this->st_storage_tray_ids |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_storage_tray_ids |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_storage_tray_ids |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_storage_tray_ids);
        memcpy( &(this->storage_tray_ids[i]), &(this->st_storage_tray_ids), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return STOREPACKAGE; };
    const char * getMD5(){ return "78937f32a3a2c21cde28ef2be251388e"; };

  };

  class StorePackageResponse : public ros::Msg
  {
    public:
      typedef uint32_t _storage_id_type;
      _storage_id_type storage_id;
      typedef float _estimated_time_type;
      _estimated_time_type estimated_time;

    StorePackageResponse():
      storage_id(0),
      estimated_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->storage_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->storage_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->storage_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->storage_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->storage_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->estimated_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->storage_id =  ((uint32_t) (*(inbuffer + offset)));
      this->storage_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->storage_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->storage_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->storage_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->estimated_time));
     return offset;
    }

    const char * getType(){ return STOREPACKAGE; };
    const char * getMD5(){ return "cf4a6afb292a74d3b885f54964349956"; };

  };

  class StorePackage {
    public:
    typedef StorePackageRequest Request;
    typedef StorePackageResponse Response;
  };

}
#endif
