
void MenuChange()
{

joyRead(analogpin1);
joyRead(analogpin2);
  
  if (key1 == 1) var = 1;
  if (key2 == 1) var = 2;
  if (key3 == 1) var = 3;
  if (key4 == 1) var = 4;
  if (key1 == 0 and key2 == 0 and key3 == 0 and key4 == 0) var = 0;

  switch(var)                   // var is just i variable and could be any variable, and can be a variable getting the temp 
  {  
  case 1: // 1 could also be a variable exsample -> temp
    menu++;
    if (menu > MaxMenu) menu = 1;
    delay(200);
    break;  // break; end this switch, and jumps to the end of the switch case and continues from there.
  case 2: // 2 could also be a variable exsample -> light
    menu--;
    if (menu <1) menu = MaxMenu;
    delay(200);
    break;
  case 3: // 3 could also be a variable exsample -> volume
    submenu++;
    delay(200);
    break;
  case 4: // 3 could also be a variable exsample -> volume
    submenu--;
    delay(200);
    break;
    
  default: // if nothing matches this case wil run.
    delay(200);
    break;
  }
  button = digitalRead(controlInPin2);
  if (button == 1)
  {
    Serial.println(F("button pushed"));
    delay(100); 
  }
}

