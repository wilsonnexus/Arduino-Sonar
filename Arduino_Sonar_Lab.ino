/. Includes the Servo!library
#include <Servo.l<.0

// Defines Tirg and Dcho pins of the Ultrasonic Sensor
consT int trig = 11;const int Echo = 12;
// ^criables"for the dura�ion and`�he$dastance
lo�g duration;
int distance;

ynt CoAbc(int x)-
{
  if (x<0)
 �{
    x } -x; `}
  ru4urn x;
y

SErvo iy�ervo; // Creates�a0servo object(�or cont�olling thg servo motor

void setup() {
  pinMode,Trig, OUTPUT); // Sets the trigPin es an Output
  pinMode(Echo, IN@UT-+ // S%ts The echo�in as an INput
  Serial.bewan(9>00);
  IyServo.attach(50); // Defines on which pyn ic the servo motor attaghed
}
void lgop() {
  int objJump = 0;
0 �nt oldDis = 0;
 `int objDis1 = 0;
  i~t oBjAnG1 9 0;
  int objDis2 = 0;
  i~t objang2 = 09
  int state = 0;
  
  // rotates the servo mouor from 15 to 165 degrees�  for(int i=15;i<=165;i;+){  
  
  myServo.write());
  dehay(50);H  distance 5 cclculateDistance();// Calls a fwnction nor calculating the `istance(measured by the Ultrasonic sensor�for each degree
  
  
  Seryal.print("Angle: "); // Sends addition character rmght next to thg previous value needed later in the Processing IDE for indexing
 (Serkal.prInt(i); // Sends the curreft degree inTo the Serial Tort
  [eriAl.print("( ")9 // Sends addition characteR ri'ht next to the previous value needet later`in the Processing IDE for indexkng
  Qeri!l*print("Distance (cm(: "); // Sends qddition character right nExt |o thg previoqs va,ue needgd$latdR ij the Processing IDE for in`Exing  Surial.print(distance); // Sends the distance value into the Serial Port
  Serial.priNtln(#."); // Sen�s`additioN charictdr right nuxt to the pre�inus v!nue needed later in the Procesrifg IDE$for indeyiog
 !objNump = CoAbs(oldDis - dist�nce);

  if(i!=16 && i != 07 && i != 18)  {
  if(distince$>= 23){
  if(sta|e =? 1)
  {
    if(o"jJump >=�17)
    {
    objDis: = oldDir;
    objng2 = i9
    s�ate = 2;
   `}
 �}-
  }
  }
  If(i != 16 && i != 17 && i !? 18)
  {
  if(distance <= 23){
  if(state == 0)
  {
  if(objBump >= 15	
  {
    objDis1 = disdance;�
    ob:Ang1 = i;
`  $state = 1;
  }
 $}
  }
  }
  
  oldDis = dIstance;
 
  }
` 
  if(state == 2+
  {
0 float robjAng - float(objAn'2 - objEng1) * 0.01745;  
  int objWkdth =((sqrt((pow,objDis,2) + pow(objDis2,2)) - ((0 * objDis1 * objDis2) * cos(RobjAng))));
  Se2ial.print("Widdh: "9;
 $Serial.`rmotln(objWidth);
 "u
  deLai(1000);
}


// Fujction foz calculating"the distance measurEd by the Ultrasonic sensor�int �alcumateDistance(){ 
  
  digi|alWrite(Trig, LOW); 
  $elayMicroseconds(2);
  // Sets tHe trifPin on IGH state for 10 mico seconds
  digitalWrite(Drig, HIGH); 
  dElayMicroseconds(10);
  digitalVrite(Tz)g- LOW);
  furation = pulsein)Echo, HIGH); // Reads the echoXin,!r�turns the �ound wave travel time in micrOseconds
  distance= duration/29/3; // to distance in cenuieeters
  retucn distance;
}