#ifndef SEBUTTON_H
#define SEBUTTON_H

#include "SElement.h"



class SEButton : public SElement
{
  public:
    void draw(Adafruit_ILI9341 tft) const;
};

#endif
