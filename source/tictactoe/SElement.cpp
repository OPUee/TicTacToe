#include "SElement.h"

SElement::SElement(int x, int y, int width, int height)
{
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

void SElement::click()
{
  onClick();
}

void SElement::setOnClick(void (*onClick)(void))
{
  this->onClick = onClick;
}

