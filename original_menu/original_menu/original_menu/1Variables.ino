
  ////////////Variables for "Start"/////////////////////////////
  #define mega
  #define controlInPin2       2       //Define can be used as it's value that never change
  #define controlOutPin3      3
  #define controlOutPin4      4
  ////////////Variables for "Start" END/////////////////////////////
  
  ////////////Variables for "StartMenu"/////////////////////////////
  #define delayTime 200
  #define times 16
  ////////////Variables for "StartMenu" END/////////////////////////////

  ////////////Variables for "Automeasure"/////////////////////////////
  #define interval         3000
  #define interval2        6000
  unsigned long previousMillis = 0;
  unsigned long previousMillis2 = 0;
  ////////////Variables for "Automeasure" END/////////////////////////////
  
  ////////////Variables for "MenuChange"/////////////////////////////
  byte menu     = 1;
  byte lastMenu;
  int  submenu  = 1;
  byte lastSubMenu;
  byte var      = 0;
  ////////////Variables for "MenuChange" END/////////////////////////////

  ////////////Variables for "joystickRead"/////////////////////////////
  byte key1 = 0;
  byte key2 = 0;
  byte key3 = 0;
  byte key4 = 0;
  int  val  = 0;
  ////////////Variables for "joystickRead" END/////////////////////////////
  
  ////////////SENSORS/////////////////////////////
  #define analogpin1   0   //Define can be used as it's value that never change    //Used in test sketch as control
  #define analogpin2   1   //Define can be used as it's value that never change    //Used in test sketch as control
  #define analogpin3   2   //Define can be used as it's value that never change    //Sunlight sensor
  #define analogpin4   3   //Define can be used as it's value that never change    //Peltier temp sensor
  #define analogpin5   4   //Define can be used as it's value that never change    
  #ifdef mega  
  #define analogpin6   5   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin7   6   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin8   7   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin9   8   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin10  9   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin11 10   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin12 11   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin13 12   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin14 13   //Define can be used as it's value that never change    //can only be used on mega
  #define analogpin15 14   //Define can be used as it's value that never change    //can only be used on mega
  #endif

  byte SensorValue1  = 0;  //Used in test sketch as control    
  byte SensorValue2  = 0;  //Used in test sketch as control
  byte SensorValue3  = 0;  //Sunlight sensor
  byte SensorValue4  = 0;  //Peltier temp sensor
  byte SensorValue5  = 0;
  #ifdef mega
  byte SensorValue6  = 0;
  byte SensorValue7  = 0;
  byte SensorValue8  = 0;
  byte SensorValue9  = 0;
  byte SensorValue10 = 0;
  byte SensorValue11 = 0;
  byte SensorValue12 = 0;
  byte SensorValue13 = 0;
  byte SensorValue14 = 0;
  byte SensorValue15 = 0;
  #endif
  
  bool SensorON1  = 0;
  bool SensorON2  = 0;
  bool SensorON3  = 0;
  bool SensorON4  = 0;
  bool SensorON5  = 0;
  #ifdef mega
  bool SensorON6  = 0;
  bool SensorON7  = 0;
  bool SensorON8  = 0;
  bool SensorON9  = 0;
  bool SensorON10 = 0;
  bool SensorON11 = 0;
  bool SensorON12 = 0;
  bool SensorON13 = 0;
  bool SensorON14 = 0;
  bool SensorON15 = 0;
  #endif
  bool tempHumidON  = 0;
  float temp1       = 0;          //Using float for negative sensor readings
  byte humid1       = 0;
  byte peltierTemp  = 0;
  ///////////SENSORS END/////////////////////////
  
  
  //////////////Variables for "HandlingFunction"////////////////////
  byte temp1Byte     = 0;
  byte peltierPWM    = 0;
  byte peltierOff    = 0;
  byte blowerPWM     = 0;
  byte blowerOff     = 0;
  byte peltierMaxMax = 90;
  byte peltierMaxMin = 85;
  byte MaxMaxtemp    = 23;          // original ->  MaxMaxtemp    = 45;

  
  //////////////Variables for "HandlingFunction" END////////////////////
  
  //////////////Variables for "Sensors"////////////////////
  byte SensorNumbers = 0; 
  byte lowThreshold1 = 200;
  byte lowThreshold2 = 1;
  int  highThreshold  = 1024;
  byte SensorDelay   = 50;
  //////////////Variables for "Sensors" END////////////////////

  //////////////Variables for "menuFunction"////////////////////
  #define MaxMenu 5
  #ifdef mega
  #define MaxSubMenu 15
  #else
  #define MaxSubMenu 5
  #endif
  byte button = 0;
  //////////////Variables for "menuFunction" END////////////////////

