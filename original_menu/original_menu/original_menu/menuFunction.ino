
#define MaxMenu 5
#ifdef mega
#define MaxSubMenu 15
#else
#define MaxSubMenu 5
#endif









void MenuChange()
{
if (key1 == 1) var = 1;
if (key2 == 1) var = 2;
if (key3 == 1) var = 3;
if (key4 == 1) var = 4;
if (key1 == 0 and key2 == 0 and key3 == 0 and key4 == 0) var = 0;

  switch(var){   // var is just i variable and could be any variable, and can be a variable getting the temp 
  case 1: // 1 could also be a variable exsample -> temp
    menu++;
    if (menu > MaxMenu) menu = 1;
   // Serial.println("\n menu is = ");
   // Serial.println(menu);
    delay(200);
    break;  // break; end this switch, and jumps to the end of the switch case and continues from there.
  case 2: // 2 could also be a variable exsample -> light
    menu--;
    if (menu <1) menu = MaxMenu;
   // Serial.print("\n menu is = ");
   // Serial.println(menu);
    delay(200);
    break;
  case 3: // 3 could also be a variable exsample -> volume
    submenu++;
    //if (submenu > MaxSubMenu) submenu = MaxSubMenu;
   //Serial.print("\n Submenu is = ");
   // Serial.println(submenu);
    delay(200);
    break;
  case 4: // 3 could also be a variable exsample -> volume
    submenu--;
    //if (submenu <1) submenu = 1;
    //Serial.print("\n Submenu is = ");
    //Serial.println(submenu);
    delay(200);
    break;
    
  default: // if nothing matches this case wil run.

    //Serial.print("\n menu is = ");
    //Serial.println(menu);
    //Serial.print("and submenu is = ");
    //Serial.println(submenu);
    delay(200);
    
    break;
  }
}

