#ifndef _ROS_gnss_initializer_msgs_MatchingPoints_h
#define _ROS_gnss_initializer_msgs_MatchingPoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "gnss_initializer_msgs/EstimatedTransform.h"

namespace gnss_initializer_msgs
{

  class MatchingPoints : public ros::Msg
  {
    public:
      uint32_t icp_points_length;
      typedef geometry_msgs::Point _icp_points_type;
      _icp_points_type st_icp_points;
      _icp_points_type * icp_points;
      uint32_t gnss_points_length;
      typedef geometry_msgs::Point _gnss_points_type;
      _gnss_points_type st_gnss_points;
      _gnss_points_type * gnss_points;
      typedef gnss_initializer_msgs::EstimatedTransform _transform_type;
      _transform_type transform;

    MatchingPoints():
      icp_points_length(0), icp_points(NULL),
      gnss_points_length(0), gnss_points(NULL),
      transform()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->icp_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->icp_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->icp_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->icp_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->icp_points_length);
      for( uint32_t i = 0; i < icp_points_length; i++){
      offset += this->icp_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->gnss_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gnss_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gnss_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gnss_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gnss_points_length);
      for( uint32_t i = 0; i < gnss_points_length; i++){
      offset += this->gnss_points[i].serialize(outbuffer + offset);
      }
      offset += this->transform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t icp_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      icp_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      icp_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      icp_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->icp_points_length);
      if(icp_points_lengthT > icp_points_length)
        this->icp_points = (geometry_msgs::Point*)realloc(this->icp_points, icp_points_lengthT * sizeof(geometry_msgs::Point));
      icp_points_length = icp_points_lengthT;
      for( uint32_t i = 0; i < icp_points_length; i++){
      offset += this->st_icp_points.deserialize(inbuffer + offset);
        memcpy( &(this->icp_points[i]), &(this->st_icp_points), sizeof(geometry_msgs::Point));
      }
      uint32_t gnss_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gnss_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gnss_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gnss_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gnss_points_length);
      if(gnss_points_lengthT > gnss_points_length)
        this->gnss_points = (geometry_msgs::Point*)realloc(this->gnss_points, gnss_points_lengthT * sizeof(geometry_msgs::Point));
      gnss_points_length = gnss_points_lengthT;
      for( uint32_t i = 0; i < gnss_points_length; i++){
      offset += this->st_gnss_points.deserialize(inbuffer + offset);
        memcpy( &(this->gnss_points[i]), &(this->st_gnss_points), sizeof(geometry_msgs::Point));
      }
      offset += this->transform.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "gnss_initializer_msgs/MatchingPoints"; };
    const char * getMD5(){ return "8ccda6d7a8f35c94cc715ec83e71b0a3"; };

  };

}
#endif