#include <SPI.h>
#include <LPD8806.h>

// d is green, c is blue
LPD8806 strip(32, 6, 5);
int z = 0; // magic number

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  strip.begin();
  strip.show();
}

void doRainbows()
{
  for (int i = 0; i < 32; ++i)
    switch(random(0, 6))
    {
    case 0:
      strip.setPixelColor(i, random(32, 127), 0, 0);
      break;
    case 1:
      strip.setPixelColor(i, 0, random(32, 127), 0);
      break;
    case 2:
      strip.setPixelColor(i, 0, 0, random(32, 127));
      break;
    case 3:
      strip.setPixelColor(i, random(32, 96), random(32, 96), 0);
      break;
    case 4:
      strip.setPixelColor(i, 0, random(32, 96), random(32, 96));
      break;
    case 5:
      strip.setPixelColor(i, random(32, 96), 0, random(32, 96));
      break;
    }
  strip.show();
  delay(100);
}

void alliance(boolean isRed, boolean isAuto)
{
  if (isAuto) isRed = true;
  for (byte i = 0; i < 32; ++i)
    strip.setPixelColor(i, (isRed) * (((cos(z) + 1) / 2) * 127), (isAuto) * (((cos(z) + 1) / 2) * 127), (!isRed && !isAuto) * (((cos(z++) + 1) / 2) * 127));
  delay(20);
  strip.show();
}

/*uint32_t getLEDCol(byte i)
{
  switch(i % 3)
  {
  case 0:
    return strip.Color(127, 0, 0);
  case 1:
    return strip.Color(0, 127, 0);
  case 2:
    return strip.Color(0, 0, 127);
  }
}

void bitDisp(uint32_t val)
{
  for (byte i = 0; i < 32; ++i)
    strip.setPixelColor(i, ((val >> i) & (byte)1) ? getLEDCol(i) : strip.Color(0, 0, 0));
  strip.show();
}

void doBinary()
{
  for (uint16_t i = 0; i < (pow(2, 16) - 1); ++i)
    bitDisp((uint32_t)i + ((uint32_t)i << 16));
}

void cop(int start, int end)
{
  for (int i = start; i < end; ++i)
    strip.setPixelColor(i, strip.Color(127, 0, 0));
  strip.show();
  delay(70);
  for (int i = start; i < end; ++i)
    strip.setPixelColor(i, strip.Color(127, 127, 127));
  strip.show();
  delay(70);
  for (int i = start; i < end; ++i)
    strip.setPixelColor(i, strip.Color(0, 0, 127));
  strip.show();
  delay(70);
}

void clear()
{
  for (int i = 0; i < 32; ++i)
    strip.setPixelColor(i, strip.Color(0, 0, 0));
  strip.show();
}

void doCop()
{
  cop(0, 16);
  clear();
  cop(16, 32);
  clear();
}

void demo()
{
  for (int i = 0; i < 10; ++i)
    doCop();
  for (int i = 0; i < 100; ++i)
    doRedAlliance();
  for (int i = 0; i < 100; ++i)
    doBlueAlliance();
  for (int i = 0; i < 100; ++i)
    doAuto();
  for (int i = 0; i < 100; ++i)
    doRainbows();
  doBinary();
}*/

void loop()
{
  switch(digitalRead(8) + (digitalRead(9) << 1))
  {
  case 0:
    doRainbows();
    break;
  case 1:
    alliance(true, false);
    break;
  case 2:
    alliance(false, false);
    break;
  case 3:
    alliance(false, true);
    break;
  }
}
