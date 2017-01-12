#ifndef SELEMENT_H
#define SELEMENT_H


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Adafruit_STMPE610.h>

#define TFT_DC 9
#define TFT_CS 10

class SElement
{
  public:
    SElement(int x, int y, int width, int height);
    virtual void draw(Adafruit_ILI9341 tft) const = 0;
    void setOnClick(void (*onClick)(TS_Point));
    void click(TS_Point p);

    int x;
    int y;
    int width;
    int height;
    
  private:
    void (*onClick)(TS_Point);
};

#endif
