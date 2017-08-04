/*
===Contact & Support===
Website: http://eeenthusiast.com/
Youtube: https://www.youtube.com/EEEnthusiast
Facebook: https://www.facebook.com/EEEnthusiast/
Patreon: https://www.patreon.com/EE_Enthusiast
Revision: 1.0 (July 13th, 2016)

===Hardware===
- Arduino Uno R3
- MPU-6050 (Available from: http://eeenthusiast.com/product/6dof-mpu-6050-accelerometer-gyroscope-temperature/)

===Software===
- Latest Software: https://github.com/VRomanov89/EEEnthusiast/tree/master/MPU-6050%20Implementation/MPU6050_Implementation
- Arduino IDE v1.6.9
- Arduino Wire library

===Terms of use===
The software is provided by EEEnthusiast without warranty of any kind. In no event shall the authors or 
copyright holders be liable for any claim, damages or other liability, whether in an action of contract, 
tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in 
the software.
*/

#include <Wire.h>
#include <TimerOne.h>

long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;
//float pitch = 0; 
//float roll = 0;
//double pitch2 = 0;
//double roll2 = 0;
float aAngleX, aAngleY;
float aAngleX2, aAngleY2;


long gyroX, gyroY, gyroZ;
float rotX = 0;
float rotY = 0;
float rotZ = 0;
float gAngleX = 0;
float gAngleY = 0;
float gAngleZ = 0;

float cAngleX = 0;
float cAngleY = 0;

long timeOld = 0.0;
long timeNew = 0.0;
long deltaTime = 0.0;

bool t = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Timer1.initialize(10000);
  Timer1.attachInterrupt(TimerOneISR);
  setupMPU();
}


void loop() {
  if (t) {
    timeNew = millis();
    deltaTime = (timeNew - timeOld);
    timeOld = timeNew;
    t = false;
    //Serial.println(deltaTime);
    recordAccelRegisters();
    recordGyroRegisters();
    ComplimentaryFilter(rotX, rotY, rotZ, gForceX, gForceY, gForceZ, cAngleX, cAngleY);
  }
  
 
  printData();
  delay(10);
}


void TimerOneISR()
{
  t = true;
}



void printData() {
  //Serial.print("Gyro (deg)");
  //Serial.print(" X=");
  Serial.print(gAngleX);
  Serial.print(",");
  //Serial.print("\t");
  //Serial.print(" Y=");
  //Serial.print(gAngleY);
  //Serial.print(",");
  //Serial.print("\t");
  //Serial.print(" Z=");
  //Serial.print(gAngleZ);
  //Serial.print(" Accel (g)");
  //Serial.print(" X=");
  //Serial.print(gForceX);
  //Serial.print(",");
  //Serial.print("\t");
  //Serial.print(" Y=");
  //Serial.print(gForceY);
  //Serial.print(",");
  //Serial.print("\t");
  //Serial.print(" Z=");
  //Serial.println(gForceZ);
  //Serial.print(" Pitch=");
  Serial.print(aAngleX);
  Serial.print(",");
  //Serial.print(" Roll=");
  //Serial.print(aAngleY);
  //Serial.print(",");
  //Serial.print("Pitch2=");
  //Serial.print(aAngleX2);
  //Serial.print(",");
  //Serial.print("Roll2=");
  //Serial.print(aAngle2);
  Serial.println(cAngleX);
  //Serial.println(cAngleY);
  
  //Serial.println("");
}

