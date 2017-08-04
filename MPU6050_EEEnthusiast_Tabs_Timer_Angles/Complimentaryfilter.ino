void ComplimentaryFilter(float rRotX, float rRotY, float rRotZ, float gX, float gY, float gZ, float &rcAngleX, float &rcAngleY)
{
  float alpha = 0.98;
  //float beta = 0.98;
  //Serial.print(rRoll);
  //Serial.print("\t");
  //Serial.println(rPitch);
  //delay(10);
  //Serial.print(deltaTime);
  rcAngleY = alpha * (rcAngleY + (rotY* deltaTime /1000.0)) + (1.0 - alpha) * atan(-gX/sqrt(pow(gY,2) + pow(gZ,2)))*57.3;
  rcAngleX = alpha * (rcAngleX + (rotX * deltaTime / 1000.0)) + (1.0 - alpha) * atan(gY/sqrt(pow(gX,2) + pow(gZ, 2)))*57.3;
  //Serial.print(rRoll);
  //Serial.print("\t");
  //Serial.println(rPitch);
  //Serial.println("");
  //delay(10);
}

