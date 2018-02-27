
byte SensorNumbers = 0; 
byte lowThreshold1 = 200;
byte lowThreshold2 = 1;
int highThreshold = 1000;
byte SensorDelay = 50;

void Sensors()
{
  TestSensorNumber();

  //Serial.print(F("\nSensorNumbers is = "));
  //Serial.print(SensorNumbers);
  
  SensorValue1 = analogRead(analogpin1);
  SensorON1 = TestOfUse(SensorValue1, 0, highThreshold);   // 0 = always on
  delay(SensorDelay);
  
  SensorValue2 = analogRead(analogpin2);
  SensorON2 = TestOfUse(SensorValue2, lowThreshold1, highThreshold);
  delay(SensorDelay);
  
  SensorValue3 = analogRead(analogpin3);
  SensorON3 = TestOfUse(SensorValue3, lowThreshold2, highThreshold);
  delay(SensorDelay);
  
  SensorValue4 = analogRead(analogpin4);
  SensorON4 = TestOfUse(SensorValue4, lowThreshold1, highThreshold);
  delay(SensorDelay);
  
  SensorValue5 = analogRead(analogpin5);
  SensorON5 = TestOfUse(SensorValue5, lowThreshold1, highThreshold);
  delay(SensorDelay);
  
  #ifdef mega
   SensorValue6 = analogRead(analogpin6);
   SensorON6 = TestOfUse(SensorValue6, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue7 = analogRead(analogpin7);
  SensorON7 = TestOfUse(SensorValue7, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue8 = analogRead(analogpin8);
  SensorON9 = TestOfUse(SensorValue8, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue9 = analogRead(analogpin9);
  SensorON9 = TestOfUse(SensorValue9, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue10 = analogRead(analogpin10);
  SensorON10 = TestOfUse(SensorValue10, lowThreshold1, highThreshold);
  delay(SensorDelay); 
  SensorValue11 = analogRead(analogpin11);
  SensorON11 = TestOfUse(SensorValue11, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue12 = analogRead(analogpin12);
  SensorON12 = TestOfUse(SensorValue12, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue13 = analogRead(analogpin13);
  SensorON13 = TestOfUse(SensorValue13, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue14 = analogRead(analogpin14);
  SensorON14 = TestOfUse(SensorValue14, lowThreshold1, highThreshold);
  delay(SensorDelay);
  SensorValue15 = analogRead(analogpin15);
  SensorON15= TestOfUse(SensorValue15, lowThreshold1, highThreshold);
  delay(SensorDelay); 
    #endif
  switch(th.Read()) 
  {
    case 2:
    tempHumidON = 0;
    break;
    case 1: 
    tempHumidON = 0;
    break;
    case 0:
    tempHumidON = 1;
    break;
    }
    
  }


  void TestSensorNumber()
  {
    #ifdef mega
    SensorNumbers = 15;
    #else
    SensorNumbers = 5;
    #endif
    }

    int TestOfUse(int value, byte MinThreshold, byte MaxThreshold)
    {
      int x;
      if (value > MinThreshold and value < MaxThreshold)
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


