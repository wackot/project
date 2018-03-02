
float convertFunction(float valueConvert, float maxConvert, float minConvert)
{
  float convertResults = 0;
  convertResults  = (((valueConvert - minConvert)/maxConvert)*100);
  return(convertResults);
}
