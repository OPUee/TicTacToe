#ifndef SEGRID_H
#define SEGRID_H

#include "SElement.h"

class SEGrid : public SElement
{
  public:
    SEGrid(int x, int y, int width, int height, int rows, int cols, int color);
    void draw(Adafruit_ILI9341 tft) const;
    int rows;
    int cols;

  private:
    int color;
    
};

#endif
