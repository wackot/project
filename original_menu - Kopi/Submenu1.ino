byte lastSubMenu;

void subMenu1()
{
  
  switch (submenu) {
  
  case 1:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 1-1"));
  }
  if(button == 1) Serial.print(F("Measurring temp \ntemp is = "));
  break;
  
  case 2:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 1-2"));
  }
   if(button == 1) Serial.print(F("Measurring voltage \nvoltage is = "));
  break;
  
  case 3:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 1-3"));
  }
   if(button == 1) Serial.print(F("Measurring humidity \nhumidity is = "));
  break;
  
  case 4:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 1-4"));
  }
   if(button == 1) Serial.print(F("Measurring waterlevel \nwaterlevel is = "));
  break;
  
  case 5:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 1-5"));
  }
   if(button == 1) Serial.print(F("Measurring Out temp \nOut temp is = "));
  break;
  }
  lastSubMenu = submenu;
  
  }
////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu2()
{
  
  switch (submenu) {
  
  case 1:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 2-1 - inside temp"));
  }
  if(button == 1) Serial.print(F("Measurring inside temp \ntemp is = "));
  break;
  
  case 2:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 2-2 - Outside temp"));
  }
  if(button == 1) Serial.print(F("Measurring Outside temp \ntemp is = "));
  break;
  
  case 3:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 2-3 - Water temp"));
  }
  if(button == 1) Serial.print(F("Measurring Water temp \ntemp is = "));
  break;
  
  case 4:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 2-4 - pool temp"));
  }
  if(button == 1) Serial.print(F("Measurring pool temp \ntemp is = "));
  break;
  
  case 5:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 2-5 - Water heater temp"));
  }
  if(button == 1) Serial.print(F("Measurring Water heater temp \ntemp is = "));
  break;
  }
  lastSubMenu = submenu;
  
  }
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu3()
{
  
  switch (submenu) {
  
  case 1:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 3-1"));
  }
  break;
  
  case 2:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 3-2"));
  }
  break;
  
  case 3:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 3-3"));
  }
  break;
  
  case 4:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 3-4"));
  }
  break;
  
  case 5:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 3-5"));
  }
  break;
  }
  lastSubMenu = submenu;
  
  }
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu4()
{
  
  switch (submenu) {
  
  case 1:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 4-1"));
  }
  break;
  
  case 2:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 4-2"));
  }
  break;
  
  case 3:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 4-3"));
  }
  break;
  
  case 4:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 4-4"));
  }
  break;
  
  case 5:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 4-5"));
  }
  break;
  }
  lastSubMenu = submenu;
  
  }
  ////////////////////////////////////////////////////////////////////////////////////////////
  void subMenu5()
{
  
  switch (submenu) {
  
  case 1:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 5-1"));
  }
  break;
  
  case 2:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 5-2"));
  }
  break;
  
  case 3:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 5-3"));
  }
  break;
  
  case 4:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 5-4"));
  }
  break;
  
  case 5:
  if (submenu != lastSubMenu)
  {
  Serial.print(F("\nSubMenu 5-5"));
  }
  break;
  }
  lastSubMenu = submenu;
  
  }
