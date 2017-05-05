#!/usr/bin/python
import rospy
from roseau_backbone_bridge.srv import *
from roseau_motor_controller.msg import WheelRpm

def backbone_write(msg):
    rospy.loginfo("Forwarding backbone write message to device: %d", msg.address)

    try:
        # forward message via backbone I2C
        
        data = [ord(c) for c in msg.data]
        
        for i, d in enumerate(data):
            backbone_bus.write_byte_data(msg.address, msg.data_index + i, d)
            print("Wrote byte {0} to device ({1}) at index {2}".format(d, msg.address, msg.data_index+i))
    except IOError, err:
        rospy.logerr("Writing backbone device failed. Device: %d", msg.address)
        
def backbone_read(req):
    rospy.loginfo("Read from backbone device: %d", req.address)
    data = []
    
    print("Data size: {0}".format(req.data_size))
    
    try:
        # read data from I2C device
        for i in range(req.data_size):
            data.append(backbone_bus.read_byte_data(req.address, req.data_start + i))
    except IOError, err:
        print("Reading backbone device failed.")
        rospy.logerr("Reading backbone device failed. Device: %d", srv.address)
        
    return BackboneReadResponse(rospy.Time.now(), ''.join(chr(c) for c in data))

def main():
    # initialize ROS node
    rospy.init_node('motor_controller')
    
    pub = rospy.Publisher('wheel_rpm', WheelRpm, queue_size=1)
    backbone_read_client = rospy.ServiceProxy('backbone_read', BackboneRead)
    
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        # read rpms
        response = backbone_read_client(16, 8, 4)
        data = [ord(c) for c in response.data]
        left_wheel_rpm = data[0] | (data[1] << 8)
        right_wheel_rpm = data[2] | (data[3] << 8)
        
        wheel_rpms = WheelRpm(rospy.Time.now(), left_wheel_rpm, right_wheel_rpm)
    
        # publish rpms
        pub.publish(wheel_rpms)
        
        rate.sleep()

if __name__ == "__main__":
   main()
