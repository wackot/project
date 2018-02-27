  byte peltierPWM = 0;
  byte peltierMaxMax = 90;
  byte peltierMaxMin = 85;




void IfhumidToHigh ()
{

  
  if (humid1 > 20){
    if (peltierTemp < peltierMaxMax) {
      peltierPWM = peltierPWM + 20;
      if(peltierPWM > 230) peltierPWM = 256;
      }
    if (peltierTemp > peltierMaxMin) {
      peltierPWM = peltierPWM - 20;
      if(peltierPWM < 20) peltierPWM = 0;
      }
    analogWrite (controlOutPin3, peltierPWM);
    Serial.print("\npeltier is = ");
    Serial.println(peltierPWM);
  }
  else{
    peltierPWM = 0;
  }
  
}
