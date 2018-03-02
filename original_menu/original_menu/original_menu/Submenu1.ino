
void subMenu1()
{
  
  switch (submenu) 
  {
  case 1:
  SensorSubMenu("SubMenu 1-1","Temp",tempHumidON);
  MeasureFunction(button, "Meas. temp", "Temp is = ", temp1, "C", 2);
  
  break;
  
  case 2:
  SensorSubMenu("SubMenu 1-2","Voltage",1);
   if(button == 1) 
   {
      SensorSubMenuMeasure("Meas. voltage","Voltage is = ");
   }
  break;
  
  case 3:
  SensorSubMenu("SubMenu 1-3","Humidity",tempHumidON);
  MeasureFunction(button, "Meas. humidity", "Humid is =", humid1, "%", 3);
  break;
  
  case 4:
  SensorSubMenu("SubMenu 1-4","waterlevel",SensorON1);
   if(button == 1) SensorSubMenuMeasure("Meas. waterlevel temp","Level is = ");
  break;
  
  case 5:
  SensorSubMenu("SubMenu 1-5","Out temp",SensorON1);
   if(button == 1) SensorSubMenuMeasure("Meas. Out temp","temp is = ");
  break;
  }
  lastSubMenu = submenu;
  
}
////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu2()
{
  
  switch (submenu) 
  {
  case 1:
  SensorSubMenu("SubMenu 2-1","Sunlight",SensorON3);
  MeasureFunction(button, "Meas. Sunlight", "Sunlight is =", (convertFunction(analogRead(analogpin3), 1000, 10)), "%", 1);
  break;
  
  case 2:
  SensorSubMenu("SubMenu 2-2","Outside temp",SensorON1);
  if(button == 1) 
  {
    SensorSubMenuMeasure("Meas. Out temp","temp is = ");
  }
  break;
  
  case 3:
  SensorSubMenu("SubMenu 2-3","water temp",SensorON1);
  if(button == 1) 
  {
    SensorSubMenuMeasure("Meas. Water temp","temp is = ");
  }
  break;
  
  case 4:
  SensorSubMenu("SubMenu 2-4","pool temp",SensorON1);
  if(button == 1) 
  {
    SensorSubMenuMeasure("Meas. pool temp","temp is = ");
  }
  break;
  
  case 5:
  SensorSubMenu("SubMenu 2-5","Water heat temp",SensorON1);
  if(button == 1) 
  {
  SensorSubMenuMeasure("Meas. heat temp","temp is = ");
  }
  break;
  }
  lastSubMenu = submenu;
  
}
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu3()
{
  
  switch (submenu) 
  {
  case 1:
  SensorSubMenu("SubMenu 3-1","Sensor 1",SensorON1);
  break;
  
  case 2:
  SensorSubMenu("SubMenu 3-2","Sensor 2",SensorON1);
  break;
  
  case 3:
  SensorSubMenu("SubMenu 3-3","Sensor 3",SensorON1);
  break;
  
  case 4:
  SensorSubMenu("SubMenu 3-4","Sensor 4",SensorON1);
  break;
  
  case 5:
  SensorSubMenu("SubMenu 3-5","Reread sensor on",1);
  if(button == 1) 
  {
    Sensors();
    lcdMenuPrint2String("                ");
    lcdMenuPrint2String("sensor checked");
  }
  break;
  }
  lastSubMenu = submenu;
  
}
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu4()
{
  
  switch (submenu) 
  {
  case 1:
  SensorSubMenu("SubMenu 4-1","Sensor 1",SensorON1);
  break;
  
  case 2:
  SensorSubMenu("SubMenu 4-2","Sensor 2",SensorON1);
  break;
  
  case 3:
  SensorSubMenu("SubMenu 4-3","Sensor 3",SensorON1);
  break;
  
  case 4:
  SensorSubMenu("SubMenu 4-4","Sensor 4",SensorON1);
  break;
  
  case 5:
  SensorSubMenu("SubMenu 4-5","Sensor 5",SensorON1);
  break;
  }
  lastSubMenu = submenu;
  
}
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu5()
{
  
  switch (submenu) 
  {
  case 1:
  SensorSubMenu("SubMenu 5-1","Sensor 1",SensorON1);
  break;
  
  case 2:
  SensorSubMenu("SubMenu 5-2","Sensor 2",SensorON2);
  break;
  
  case 3:
  SensorSubMenu("SubMenu 5-3","Sensor 3",SensorON3);
  break;
  
  case 4:
  SensorSubMenu("SubMenu 5-4","Sensor 4",SensorON4);
  break;
  
  case 5:
  SensorSubMenu("SubMenu 5-5","Sensor 5",SensorON5);
  break;
#ifdef mega
  case 6:
  SensorSubMenu("SubMenu 5-6","Sensor 6",SensorON6);
  break;
  case 7:
  SensorSubMenu("SubMenu 5-7","Sensor 7",SensorON7);
  break;
  case 8:
  SensorSubMenu("SubMenu 5-8","Sensor 8",SensorON8);
  break;
  case 9:
  SensorSubMenu("SubMenu 5-9","Sensor 9",SensorON9);
  break;
  case 10:
  SensorSubMenu("SubMenu 5-10","Sensor 10",SensorON10);
  break;
  case 11:
  SensorSubMenu("SubMenu 5-11","Sensor 11",SensorON11);
  break;
  case 12:
  SensorSubMenu("SubMenu 5-12","Sensor 12",SensorON12);
  break;
  case 13:
  SensorSubMenu("SubMenu 5-13","Sensor 13",SensorON3);
  break;
  case 14:
  SensorSubMenu("SubMenu 5-14","Sensor 14",SensorON14);
  break;
  case 15:
  SensorSubMenu("SubMenu 5-15","Sensor 15",SensorON15);
  break;
  #endif
  }
  lastSubMenu = submenu;
  
}


  
void SensorSubMenu(String SensorMenuName, String SensorName, byte IsItOn)
{
     if (submenu != lastSubMenu)
     {
        Serial.println(F("TEST PRINT is sensor connected = "));
        Serial.print(IsItOn);
  
        Serial.println(SensorMenuName);
        lcdMenuPrintString(SensorMenuName);
            if (IsItOn == 1)
            {
                lcdMenuPrint2String("                ");
                lcdMenuPrint2String(SensorName);
            }
                else
                {
                    lcd.setCursor(0,1);
                    lcd.print("NOT CONNECTED");
                }
    }
}

void SensorSubMenuMeasure(String SensorMenuName, String SensorName)
{
    Serial.println(SensorMenuName);
    lcdMenuPrintString(SensorMenuName);
    lcdMenuPrint2String(SensorName);
}

void SensorSubMenuvalue(float MesValue, String unit, byte icon)
{
     lcd.print(MesValue);
     lcd.print(unit);
     lcd.setCursor(15,0);
     lcd.print(char(icon));
}

void MeasureFunction(bool button, String FirstLineText, String SecondLineText, float SensorToMeasure, String UnitToShow, byte icon)
{
     if(button == 1) 
     {
       SensorSubMenuMeasure(FirstLineText,SecondLineText);
       Serial.print(SecondLineText);
       Serial.print(SensorToMeasure);
       Serial.println(UnitToShow);
       SensorSubMenuvalue(SensorToMeasure, UnitToShow,icon);
       
     }
}

 
