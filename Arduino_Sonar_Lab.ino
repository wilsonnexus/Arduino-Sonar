// Includes the Servo library
#include <Servo.h>. 

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int Trig = 11;
const int Echo = 12;
// Variables for the duration and the distance
long duration;
int distance;

int CoAbs(int x)
{
  if (x<0)
  {
    x = -x;
  }
  return x;
}

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
  pinMode(Trig, OUTPUT); // Sets the trigPin as an Output
  pinMode(Echo, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(10); // Defines on which pin is the servo motor attached
}
void loop() {
  int objJump = 0;
  int oldDis = 0;
  int objDis1 = 0;
  int objAng1 = 0;
  int objDis2 = 0;
  int objAng2 = 0;
  int state = 0;
  
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  
  myServo.write(i);
  delay(50);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  
  Serial.print("Angle: "); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(", "); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print("Distance (cm): "); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.println("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  objJump = CoAbs(oldDis - distance);

  if(i!=16 && i != 17 && i != 18)
  {
  if(distance >= 23){
  if(state == 1)
  {
    if(objJump >= 15)
    {
    objDis2 = oldDis;
    objAng2 = i;
    state = 2;
    }
  }
  }
  }
  if(i != 16 && i != 17 && i != 18)
  {
  if(distance <= 23){
  if(state == 0)
  {
  if(objJump >= 15)
  {
    objDis1 = distance;
    objAng1 = i;
    state = 1;
  }
  }
  }
  }
  
  oldDis = distance;
 
  }
  
  if(state == 2)
  {
  float robjAng = float(objAng2 - objAng1) * 0.01745;
  
  int objWidth = (sqrt((pow(objDis1,2) + pow(objDis2,2)) - ((2 * objDis1 * objDis2) * cos(robjAng))));
  Serial.print("Width: ");
  Serial.println(objWidth);
  }
  delay(1000);
}


// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(Trig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  duration = pulseIn(Echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration/29/2; // to distance in centimeters
  return distance;
}