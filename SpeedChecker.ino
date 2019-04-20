/*Beaver's Hobby Channel Easy Arduino Project #3: Micro RC (Mini-Z) Speed Checker
What you need:
1. Arduino of your choice
2. Speed Measuring Sensor eg. FC-03
*/
#include <TimerOne.h>
const byte interruptPin = 2;
unsigned int counter = 0;
const float pi = 3.14159;
const float wheel = 24.0; // Wheel diameter in mm
unsigned int rot = 0;
float speed = 0;

void count()
{
  counter++;
}

void getRPS()
{
  Timer1.detachInterrupt();  //Stop the timer

  Serial.println(counter, DEC); // Printing the raw counter value

  //Calculate and print the speed to serial monitor
  rot = counter/3;
  speed = pi*wheel*rot*0.0036;
  
  Serial.print(rot,DEC);
  Serial.print(" RPS , Speed = ");
  Serial.println(speed,DEC);
 
  counter =0; //Reset the counter
  Timer1.attachInterrupt(getRPS);  //Re-enable the timer
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, RISING);
  Timer1.attachInterrupt(getRPS);
}

void loop() {
}
