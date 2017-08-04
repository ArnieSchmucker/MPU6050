void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x3B); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processAccelData();
  processAccelRollPitch(gForceX, gForceY, gForceZ, aAngleX, aAngleY);
  processAccelRollPitch2(gForceX, gForceY, gForceZ, aAngleX2, aAngleY2);
}

void processAccelData(){
  gForceX = accelX / 16384.0;
  gForceY = accelY / 16384.0; 
  gForceZ = accelZ / 16384.0;
}

void processAccelRollPitch(float gX, float gY, float gZ, float &raAngleX, float &raAngleY)
{
  raAngleX = atan(gY/sqrt(gX * gX + gZ * gZ))*57.3;
  raAngleY = atan(-gX/sqrt(gY * gY + gZ * gZ))*57.3;
  //Serial.println(gY);
  //Serial.print(rRoll);
  //Serial.print("\t");
  //Serial.println(rPitch);
}

void processAccelRollPitch2(float gX, float gY, float gZ, float &raAngleX2, float &raAngleY2)
{
  raAngleX2 = atan2(-gY,sqrt(gX * gX + gZ * gZ))*57.3;
  raAngleY2 = atan2(-gX, sqrt(gY * gY + gZ * gZ))*57.3;
}

