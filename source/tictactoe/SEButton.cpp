#include "SEButton.h"

SEButton::SEButton(int x, int y, int width, int height, char *text)
: SElement( x, y, width, height)
{
  this->text = text;
}

void SEButton::draw(Adafruit_ILI9341 tft) const
{
  tft.fillRect(x,y,width,height,ILI9341_DARKCYAN);
  tft.drawRect(x,y,width,height,ILI9341_BLUE);
  tft.drawRect(x+1,y+1,width-1,height-2,ILI9341_BLUE);

  tft.setCursor(x+8,y+23);
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.println(text);
}
