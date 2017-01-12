#include "SElement.h"

SElement::SElement(int x, int y, int width, int height)
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

void SElement::click(TS_Point p)
{
  onClick(p);
}

void SElement::setOnClick(void (*onClick)(TS_Point))
{
  this->onClick = onClick;
}

