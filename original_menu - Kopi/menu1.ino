byte lastMenu;

void menu1()
{
  
  switch (menu) {
  
  case 1:
  if (menu != lastMenu)
  {
  Serial.print(F("\nMenu 1"));
  button = 0;
  submenu = 1;
  lastSubMenu = 0;
  }
  subMenu1();
  break;
  
  case 2:
  if (menu != lastMenu)
  {
  Serial.print(F("\nMenu 2 - Temperatures"));
  submenu = 1;
  lastSubMenu = 0;
  }
  subMenu2();
  break;
  
  case 3:
  if (menu != lastMenu)
  {
  Serial.print(F("\nMenu 3"));
  submenu = 1;
  lastSubMenu = 0;
  }
  subMenu3();
  break;
  
  case 4:
  if (menu != lastMenu)
  {
  Serial.print(F("\nMenu 4"));
  submenu = 1;
  lastSubMenu = 0;
  }
  subMenu4();
  break;
  
  case 5:
  if (menu != lastMenu)
  {
  Serial.print(F("\nMenu 5"));
  submenu = 1;
  lastSubMenu = 0;
  }
  subMenu5();
  break;
  }
  lastMenu = menu;
  
  }
