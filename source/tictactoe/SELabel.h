#ifndef SELABEL_H
#define SELABEL_H

#include "SElement.h"

class SELabel : public SElement
{
  public:
    SELabel(int x, int y, int width, int height, char* text, int color, int size);
    void draw(Adafruit_ILI9341 tft) const;

  private:
    char* text;
    int size;
    int color;
    
};

#endif
