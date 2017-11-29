#!/usr/bin/python
import rospy
from backbone_bridge.srv import *
from motor_controller.msg import WheelRpm

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
