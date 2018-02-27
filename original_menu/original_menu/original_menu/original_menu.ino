/*
 this is my first library learning code
*/
  #define mega
  #include "Arduino.h"
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  #include <AM2320.h>
  
  AM2320 th;
  
  //#define analogpin 0   //Define can be used as it's value that never change
  //#define analogpin2 1  //Define can be used as it's value that never change
  #define interval  2000
  #define interval2 4000
  #define controlInPin2     2       //Define can be used as it's value that never change
  #define controlOutPin3    3
  #define controlOutPin4    4

  ////////////SENSORS/////////////////////////////
  #define analogpin1 0   //Define can be used as it's value that never change    //Used in test sketch as control
  #define analogpin2 1   //Define can be used as it's value that never change    //Used in test sketch as control
  #define analogpin3 2   //Define can be used as it's value that never change    //Sunlight sensor
  #define analogpin4 3   //Define can be used as it's value that never change    //Peltier temp sensor
  #define analogpin5 4   //Define can be used as it's value that never change    
  #ifdef mega  
  #define analogpin6 5   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin7 6   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin8 7   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin9 8   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin10 9   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin11 10   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin12 11   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin13 12   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin14 13   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin15 14   //Define can be used as it's value that never change    //can only be used on mega
  #endif

  LiquidCrystal_I2C lcd(0x27,20,4); // set the LCD address to 0x27 for a 16 chars and 2 line display
  unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;
  byte SensorValue1 = 0;  //Used in test sketch as control    
  byte SensorValue2 = 0;  //Used in test sketch as control
  byte SensorValue3 = 0;  //Sunlight sensor
  byte SensorValue4 = 0;  //Peltier temp sensor
  byte SensorValue5 = 0;
  #ifdef mega
  byte SensorValue6 = 0;
  byte SensorValue7 = 0;
  byte SensorValue8 = 0;
  byte SensorValue9 = 0;
  byte SensorValue10 = 0;
  byte SensorValue11 = 0;
  byte SensorValue12 = 0;
  byte SensorValue13 = 0;
  byte SensorValue14 = 0;
  byte SensorValue15 = 0;
  #endif
  
  bool SensorON1 = 0;
  bool SensorON2 = 0;
  bool SensorON3 = 0;
  bool SensorON4 = 0;
  bool SensorON5 = 0;
  #ifdef mega
  bool SensorON6 = 0;
  bool SensorON7 = 0;
  bool SensorON8 = 0;
  bool SensorON9 = 0;
  bool SensorON10 = 0;
  bool SensorON11 = 0;
  bool SensorON12 = 0;
  bool SensorON13 = 0;
  bool SensorON14 = 0;
  bool SensorON15 = 0;
  #endif
  bool tempHumidON = 0;
  float temp1 = 0;          //Using float for negative sensor readings
  byte humid1 = 0;
  byte peltierTemp = 0;
  ///////////SENSORS END/////////////////////////
  byte button = 0;
  
  
  byte menu = 1;
  int submenu = 1;
  byte var = 0;
    byte key1 = 0;
    byte key2 = 0;
    byte key3 = 0;
    byte key4 = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(controlInPin2, INPUT);
  pinMode(controlOutPin3, OUTPUT);  
  pinMode(controlOutPin4, OUTPUT);
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight(); 
  StartMenu();
  Sensors();   //Checks if sensors are connected or function correct

}
  void loop() {
joyRead(analogpin1);
joyRead(analogpin2);



//Serial.print(F("\nSensorON3 is "));
//Serial.print(SensorON2);
//delay(2000);

MenuChange();
menu1();
IfhumidToHigh();

     unsigned long currentMillis = millis();
 if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;  
    AutoMeasure();
  }
button = digitalRead(controlInPin2);

if (button == 1)
{
Serial.println(F("button pushed"));
 delay(100); 
 
}

}



