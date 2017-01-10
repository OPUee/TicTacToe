#ifndef SELEMENT_H
#define SELEMENT_H


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

class SElement
{
  public:
    SElement();
    virtual void draw(Adafruit_ILI9341 tft) const = 0;
    void setOnClick(void (*onClick)(void));
    void click();
    
  private:
    void (*onClick)(void);
};

#endif
