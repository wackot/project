#define delayTime 200
#define times 16

void StartMenu()
{
  Serial.print(F("\n------------------------ WELCOME ---------------------------------------"));
  Serial.print(F("\nYou have now startet your autoSystem and it will be ready to use shortly"));
  Serial.print(F("\n- "));
  lcdMenuPrintString("---WELCOME---");
  lcdMenuPrint2String("autoSyst start");
  delay(5000);
  lcdMenuPrintString("LOADING");
  lcd.setCursor(0,1);
  StartUp();
  lcd.setCursor(0,0);
  lcd.print("PRESS TO ENTER");
  Serial.print(F("\n\n               PRESS BUTTON TO ENTER"));
  while (button == 0)
  {
  button = digitalRead(inpin);
  }
  menu = 1;
  OnceStart = 1;
  }

  void StartUp()
  {
    for (int i = 0; i<times; i++)
    {
  
  
  lcd.print("-");
  Serial.print(F("- "));
  delay(delayTime);
    }
    }
