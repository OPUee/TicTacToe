#ifndef SCREEN_H
#define SCREEN_H

#include "SElement.h"


class Screen
{
  public:
    Screen(int rotation, int background);
    void render(Adafruit_ILI9341 tft) const;
    void addElement(const SElement &e);
    void checkEvent(TS_Point p) const;
    
  private:
    const SElement *elements[20];
    int elemI;
    int rotation;
    int background;
};

#endif
