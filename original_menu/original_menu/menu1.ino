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
  if (submenu > 5) submenu = 5;
  subMenu1();
  break;
  
  case 2:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 2");
  }
  if (submenu > 5) submenu = 5;
  subMenu2();
  break;
  
  case 3:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 3");
  }
  if (submenu > 5) submenu = 5;
  subMenu3();
  break;
  
  case 4:
  if (menu != lastMenu)
  {
    MenuFunctionMenu("Menu 4");
  }
  if (submenu > 5) submenu = 5;
  subMenu4();
  break;
  
  case 5:
  if (menu != lastMenu)
  {
  MenuFunctionMenu("Menu 5");
  }
  subMenu5();
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
  

    
