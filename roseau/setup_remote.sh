ROSEAU_HOST=roseau

ROSEAU_IP=$(getent hosts $ROSEAU_HOST | awk '{ print $1 }')

export ROS_MASTER_URI=http://$ROSEAU_HOST:11311
export ROS_IP=$ROSEAU_IP

printf "Configured environment variables for connecting to %s (%s).\n" $ROSEAU_HOST $ROSEAU_IP
