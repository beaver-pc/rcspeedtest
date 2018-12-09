#include <TimerOne.h>
unsigned int counter=0;
unsigned int wheel = 25; //Wheel size in mm
const float Pi = 3.14159;

void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
} 

void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  Serial.print("Motor Speed: "); 
  int rotation = counter;  // divide by number of holes in Disc
  Serial.print(rotation,DEC);  
  Serial.print(" RPM = ");
  float spd = (wheel*Pi)*rotation*0.0036;
  Serial.print(spd,DEC);
  Serial.println(" KPH"); 
  counter=0;  //  reset counter to zero
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}

void setup() 
{
  Serial.begin(9600);
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt( timerIsr ); // enable the timer
} 

void loop()
{

}
