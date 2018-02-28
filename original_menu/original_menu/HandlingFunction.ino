
void IfhumidToHigh ()
{
  if (humid1 > 20)
  {
    if (peltierTemp < peltierMaxMax) 
    {
        if(peltierPWM < 210) peltierPWM = peltierPWM + 20;
        if(peltierPWM > 210) peltierPWM = 256;
    }
    if (peltierTemp > peltierMaxMin) 
    {
      if(peltierPWM > 40) peltierPWM = peltierPWM - 20;
      if(peltierPWM < 40) peltierPWM = 0;
    }
    analogWrite (controlOutPin3, peltierPWM);
    Serial.print("\npeltier is = ");
    Serial.println(peltierPWM);
    peltierOff = 0;
  }
  if (humid1 < 18)
  {
    if (peltierOff == 0)
    {
    peltierPWM = 0;
    peltierOff = 1;
    analogWrite (controlOutPin3, peltierPWM);
    Serial.print("\npeltier is = ");
    Serial.println(peltierPWM);
    }
  }
  
}

void IfTempToHigh ()
{
  if (temp1 > MaxMaxtemp)     //original -> if (temp1 > 30)
  {
    temp1Byte = (byte) temp1;
    temp1Byte = temp1Byte - MaxMaxtemp;
    Serial.print("\temp1Byte is = ");
    Serial.println(temp1Byte);
    switch(temp1Byte)
    {
    case 0:
    blowerPWM = 25;
    break;
    case 1:
    blowerPWM = 25;
    break;
    case 2:
    blowerPWM = 50;
    break;
    case 3:
    blowerPWM = 75;
    break;
    case 4:
    blowerPWM = 100;
    break;
    case 5:
    blowerPWM = 125;
    break;
    case 6:
    blowerPWM = 150;
    break;
    case 7:
    blowerPWM = 175;
    break;
    case 8:
    blowerPWM = 200;
    break;
    case 9:
    blowerPWM = 225;
    break;
    case 10:
    blowerPWM = 256;
    break;
    }
    blowerOff = 0;
    analogWrite (controlOutPin4, blowerPWM);
    Serial.print("\nblowerPWM is = ");
    Serial.println(blowerPWM);
  }
  if (temp1 < 20)           //original -> if (temp1 > 28)
  {
    if (blowerOff == 0)
    {
    blowerPWM = 0;
    blowerOff = 1;
    analogWrite (controlOutPin4, blowerPWM);
    Serial.print("\nblowerPWM is = ");
    Serial.println(blowerPWM);
    }
  }
  
}
