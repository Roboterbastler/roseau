#!/usr/bin/python
import rospy
import smbus
from backbone_bridge.msg import BackboneWrite
from backbone_bridge.srv import *

# create and open I2C instance
backbone_bus = smbus.SMBus(1)

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
    rospy.init_node('backbone_bridge')

    # listen to backbone write messages
    rospy.Subscriber("backbone_write", BackboneWrite, backbone_write)
    
    # advertise backbone read service
    rospy.Service('backbone_read', BackboneRead, backbone_read)
    
    rospy.spin()

if __name__ == "__main__":
   main()
