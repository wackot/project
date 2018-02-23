#define delayTime 200
#define times 36

void StartMenu()
{
  Serial.print(F("\n------------------------ WELCOME ---------------------------------------"));
  Serial.print(F("\nYou have now startet your autoSystem and it will be ready to use shortly"));
  Serial.print(F("\n- "));
  StartUp();
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
  Serial.print(F("- "));
  delay(delayTime);
    }
    }
