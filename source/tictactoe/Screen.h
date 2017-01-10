#ifndef SCREEN_H
#define SCREEN_H

#include "SElement.h"


class Screen
{
  public:
    Screen();
    void render(Adafruit_ILI9341 tft) const;
    void addElement(const SElement &e);
    void checkEvent(int x, int y) const;
    
  private:
    const SElement *elements[20];
    int elemI;
};

#endif
