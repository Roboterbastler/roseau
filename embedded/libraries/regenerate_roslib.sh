#!/bin/bash

rm -r ros_lib
source ../../../devel/setup.bash
rosrun rosserial_arduino make_libraries.py .

