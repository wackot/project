byte lastMenu;

void menu1()
{
  
  switch (menu) {
  
  case 1:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 1");
  button = 0;
  }
  subMenu1();
  MenuRotate();
  break;
  
  case 2:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 2");
  }
  subMenu2();
  MenuRotate();
  break;
  
  case 3:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 3");
  }
  subMenu3();
  MenuRotate();
  break;
  
  case 4:
  if (menu != lastMenu)
  {
    MenuFunctionMenu("Menu 4");
  }
  subMenu4();
  MenuRotate();
  break;
  
  case 5:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 5");
  }
  subMenu5();
  MenuRotate();
  break;
  }
  lastMenu = menu;
  
  }

  void MenuFunctionMenu(String TextMenu)
  {
  Serial.println(TextMenu);
  lcdMenuPrintString(TextMenu);
  submenu = 0;
  lastSubMenu = 0;
    }
  
  void MenuRotate()
  {
      if (submenu < 0) submenu = 5;{}
      if (submenu > 5) submenu = 1;{}
    }
    
