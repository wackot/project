/*
 this is my first library learning code
*/
  
  #include "Arduino.h"
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  #include <AM2320.h>  
  AM2320 th;
  LiquidCrystal_I2C lcd(0x27,20,4);   // set the LCD address to 0x27 for a 16 chars and 2 line display


  
  void setup() {
  Serial.begin(9600);
  setups();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcdCustomSymbols();
  StartMenu();
  Sensors();   //Checks if sensors are connected or function correct
  }
  
  void loop() {
  MenuChange();
  menu1();
  AutoMeasure();
  IfhumidToHigh();
  IfTempToHigh();
  }
  
  


