
byte convertFunction(float valueConvert, float maxConvert, float minConvert)
{
  byte convertResults = 0;
  convertResults  = (((valueConvert - minConvert)/maxConvert)*100);
  return(convertResults);
}
