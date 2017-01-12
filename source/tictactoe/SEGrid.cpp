#include "SEGrid.h"

#define WIDTH 240
#define HEIGHT 320

SEGrid::SEGrid(int x, int y, int width, int height, int rows, int cols, int color)
: SElement( x, y, width, height)
{
  this->rows = rows;
  this->cols = cols;
  this->color = color;
}

void SEGrid::draw(Adafruit_ILI9341 tft) const
{  
  int vOffset = width / cols;
  int hOffset = height / rows;

  for(int i = 1; i < cols; i++)
  {
    tft.drawFastVLine(i * vOffset + x,y,height,color);
  }

  for(int i = 1; i < rows; i++)
  {
    tft.drawFastHLine(x,i * hOffset + y,width,color);
  }
}
