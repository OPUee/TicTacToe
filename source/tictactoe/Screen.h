#ifndef SCREEN_H
#define SCREEN_H

#include "SElement.h"


class Screen
{
  public:
    Screen(int rotation, int background);
    void render(Adafruit_ILI9341 tft) const;
    void addElement(const SElement &e);
    void checkEvent(int x, int y) const;
    int id;
    
  private:
    const SElement *elements[20];
    int elemI;
    int rotation;
    int background;
};

#endif
