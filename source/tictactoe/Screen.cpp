//#include "list"
#include "Screen.h"
#include "SElement.h"

//std::list<SElement> elements;


Screen::Screen()
{
  elemI = 0;
}

void Screen::render(Adafruit_ILI9341 tft) const
{
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
    elements[i]->click();
  }
}

