# obs_avoidance for ros_lawn_tractor

# Hardware
[JSN-SR04T](https://www.ebay.com/itm/183304077630)
 Ultrasound senors are used to detect distance of obstacles.

 The ultrasound sensors publish sensor data to an Arduino Nano that publishes the distance to ROS as "ultrasonic" node as [sensor_msgs/Range](http://docs.ros.org/kinetic/api/sensor_msgs/html/msg/Range.html) over "us_range" topic.

A PCB board has been designed and can be found in the schematics folder that holds a design for a PCB board that can support upto 4 JSN-SR04T sensors connecting to an Arduino Nano. 

 # Software
The microcontroller_sw folder holds a .ino file to program a microcontroller, here Arduino Nano.
