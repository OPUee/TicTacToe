#include "SEButton.h"

void SEButton::draw(Adafruit_ILI9341 tft) const
{
  tft.fillRect(20,20,200,200,ILI9341_YELLOW);
}
