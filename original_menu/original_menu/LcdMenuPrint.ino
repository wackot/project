
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
