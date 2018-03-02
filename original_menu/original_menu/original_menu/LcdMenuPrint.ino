
void lcdMenuPrintString(String text)
{
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(text);
}

void lcdMenuPrint2String(String text)
{
     lcd.setCursor(0,1);
     lcd.print(text);
}

void lcdMenuPrintValue(byte value)
{
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(value);
}

void lcdMenuPrint2Value(byte value)
{
    
     lcd.setCursor(0,1);
     lcd.print(value);
}

void lcdCustomSymbols()
{
  byte termo[8] = {
    0b00100,
    0b01010,
    0b01010,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b01110};

  byte water[8] = {
  0b00100,
  0b00100,
  0b01110,
  0b01110,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};

  byte sun[8] = {
  0b00000,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00000,
  0b00000
};
    
  lcd.createChar (2, termo);
  lcd.createChar (3, water);
  lcd.createChar (1, sun);
  
  
}
