#include<ros.h>
#include<sensor_msgs/Range.h>

ros::NodeHandle nh;
sensor_msgs::Range us_range;
ros::Publisher ultrasonic("ultrasonic",&us_range);

const uint8_t radiation_type = 0;
float field_of_view = 0;
float min_range = 2;
float max_range = 500;


// defines pins numbers
const int T1 = 2;
const int E1 = 3;
const int T2 = 4;
const int E2 = 5;
const int T3 = 6;
const int E3 = 7;
//only three sensors implemented on Matt's machine
//const int T3 = 8;
//const int E3 = 9;

//function to calculate distance
void MeasureDistance(int trig, int echo) {
long duration = 0;
int d = 0;
//digitalWrite(trig, LOW);
//delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(20);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
// Calculating the distance cm
d = duration*0.034/2;

us_range.radiation_type = radiation_type;
us_range.field_of_view = field_of_view;
us_range.min_range = min_range;
us_range.max_range = max_range;
us_range.range = d;
ultrasonic.publish(&us_range);
nh.spinOnce();
}

void setup() {
nh.initNode();
nh.advertise(ultrasonic);

pinMode(T0, OUTPUT); // Sets the T1 as an Output
pinMode(E0, INPUT); // Sets the E1 as an Input
pinMode(T1, OUTPUT); // Sets the T2 as an Output
pinMode(E1, INPUT); // Sets the E2 as an Input
pinMode(T2, OUTPUT); // Sets the T3 as an Output
pinMode(E2, INPUT); // Sets the E3 as an Input
pinMode(T3, OUTPUT); // Sets the T4 as an Output
pinMode(E3, INPUT); // Sets the E4 as an Input
pinMode(LED0, OUTPUT); //Sets the led as Output
Serial.begin(115200); // Starts the serial communication
}

void loop() {
MeasureDistance(T0,E0);
MeasureDistance(T1,E1);
MeasureDistance(T2,E2);
MeasureDistance(T3,E3);
}
