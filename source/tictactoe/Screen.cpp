#include "Screen.h"
#include "SElement.h"

Screen::Screen(int rotation, int background)
{
  this->rotation = rotation;
  this->background = background;
  elemI = 0;
}

void Screen::render(Adafruit_ILI9341 tft) const
{
  tft.setRotation(rotation);
  tft.fillScreen(background);
  
  for(int i = 0; i < elemI; i++)
  {
    elements[i]->draw(tft);
  }
}

void Screen::addElement(const SElement &e)
{
  elements[elemI] = &e;
  elemI++;
}

void Screen::checkEvent(int x, int y)const
{
  //routine zum checken des punkte B-)
  
  for(int i = 0; i < elemI; i++)
  {
    const SElement *e = elements[i];
    if(x > e->x && x < (e->width + e->x))
    {
      if(y > e->y && y < (e->height + e->y))
      {
        e->click();
      }
    }
  }
}

