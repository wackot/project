
void AutoMeasure()
{
       unsigned long currentMillis = millis();
 if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;  
    
  Serial.print(F("\n AutoMeasuring"));
  
       temp1 = IfOnAnalog(th.t, tempHumidON);
       temp1 = temp1 - 0.4;
       humid1 = IfOnAnalog(th.h, tempHumidON);
       unsigned long currentMillis2 = millis();
       if (currentMillis2 - previousMillis2 >= interval2) 
          {
          previousMillis2 = currentMillis2;  
          th.Read();
          
          }
  SensorValue1 = IfOnAnalog(analogRead(analogpin1), SensorON1);
  SensorValue2 = IfOnAnalog(analogRead(analogpin2), SensorON2);
  SensorValue3 = IfOnAnalog((convertFunction(analogRead(analogpin3), 1000, 10)), SensorON3);     // Sunlight sensor check
  peltierTemp  = IfOnAnalog(analogRead(analogpin4), SensorON4);
  SensorValue5 = IfOnAnalog(analogRead(analogpin5), SensorON5);
  SensorValue6 = IfOnAnalog(analogRead(analogpin6), SensorON6);
  SensorValue7 = IfOnAnalog(analogRead(analogpin7), SensorON7);
  SensorValue8 = IfOnAnalog(analogRead(analogpin8), SensorON8);
  SensorValue9 = IfOnAnalog(analogRead(analogpin9), SensorON9);
  SensorValue10 = IfOnAnalog(analogRead(analogpin10), SensorON10);
  SensorValue11 = IfOnAnalog(analogRead(analogpin11), SensorON11);
  SensorValue12 = IfOnAnalog(analogRead(analogpin12), SensorON12);
  SensorValue13 = IfOnAnalog(analogRead(analogpin13), SensorON13);
  SensorValue14 = IfOnAnalog(analogRead(analogpin14), SensorON14);
  SensorValue15 = IfOnAnalog(analogRead(analogpin15), SensorON15);
  
  Serial.print("\n Auto TEST th.t is = ");
  Serial.println(temp1);
  Serial.print(" Auto TEST th.h is = ");
  Serial.println(humid1);
  Serial.print(" Auto TEST sunlight is = ");
  Serial.println(SensorValue3);
  Serial.print(" Auto TEST SensorValue1 is = ");
  Serial.println(SensorValue1);
  Serial.print(F("\n\n AutoMeasring ended"));
 }
}

  float IfOnAnalog(float sensorToMeasure, bool IsItOn)
  {
    if (IsItOn == 1)
    {
      float SaveTo;
      SaveTo = sensorToMeasure;
      return(SaveTo);
    }
  }
