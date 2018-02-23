
int val = 0;

void joyRead(byte joy )
{
val = analogRead(joy);
Serial.print(" Joystik ");
Serial.print(joy);
Serial.print(" value is = ");
Serial.print(val);


if (joy == 0)
{
if (val < 300)
key1 = 1;

if (val > 800)
key2 = 1;

if (val < 799)
{if (val > 301)
{
  key1 = 0;
  key2 = 0;
  }
}
}

if (joy == 1)
{
if (val > 300)
key3 = 1;

if (val < 800)
key4 = 1;

if (val < 799)
{if (val > 301)
{
  key3 = 0;
  key4 = 0;
  }
}
}

}
