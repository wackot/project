
byte SensorNumbers = 0; 
int MinThreshold = 200;

void Sensors()
{
  TestSensorNumber();

  Serial.print(F("\nSensorNumbers is = "));
  Serial.print(SensorNumbers);
  
  SensorValue1 = analogRead(analogpin1);
  SensorON1 = TestOfUse(SensorValue1);
  delay(100);
  
  SensorValue2 = analogRead(analogpin2);
  SensorON2 = TestOfUse(SensorValue2);
  delay(100);
  
  SensorValue3 = analogRead(analogpin3);
  SensorON3 = TestOfUse(SensorValue3);
  delay(100);
  
  SensorValue4 = analogRead(analogpin4);
  SensorON4 = TestOfUse(SensorValue4);
  delay(100);
  
  SensorValue5 = analogRead(analogpin5);
  SensorON5 = TestOfUse(SensorValue5);
  delay(100);
  
  #ifdef mega
   SensorValue6 = analogRead(analogpin6);
  delay(100);
  SensorValue7 = analogRead(analogpin7);
  delay(100);
  SensorValue8 = analogRead(analogpin8);
  delay(100);
  SensorValue9 = analogRead(analogpin9);
  delay(100);
  SensorValue10 = analogRead(analogpin10);
  delay(100); 
  SensorValue11 = analogRead(analogpin11);
  delay(100);
  SensorValue12 = analogRead(analogpin12);
  delay(100);
  SensorValue13 = analogRead(analogpin13);
  delay(100);
  SensorValue14 = analogRead(analogpin14);
  delay(100);
  SensorValue15 = analogRead(analogpin15);
  delay(100); 
    #endif

    
  }


  void TestSensorNumber()
  {
    #ifdef mega
    SensorNumbers = 15;
    #else
    SensorNumbers = 5;
    #endif
    }

    int TestOfUse(byte value)
    {
      int x;
      if (value > MinThreshold)
      {
        //Serial.print(F("\nin use"));
        x = 1;
        } 
        else
        {
          //Serial.print(F("\nnot in use"));
        x = 0;
          }

      return (x);
      }


