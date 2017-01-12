#include "SELabel.h"

SELabel::SELabel(int x, int y, int width, int height, char *text, int color, int size)
: SElement( x, y, width, height)
{
  this->text = text;
  this->color = color;
  this->size = size;
}

void SELabel::draw(Adafruit_ILI9341 tft) const
{
  tft.setCursor(x,y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.println(text);
}
