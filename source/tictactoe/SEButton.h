#ifndef SEBUTTON_H
#define SEBUTTON_H

#include "SElement.h"



class SEButton : public SElement
{
  public:
    SEButton(int x, int y, int width, int height, char* text);
    void draw(Adafruit_ILI9341 tft) const;

    char *text;
};

#endif
