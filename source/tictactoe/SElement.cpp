#include "SElement.h"

SElement::SElement()
{
}

void SElement::click()
{
  onClick();
}

void SElement::setOnClick(void (*onClick)(void))
{
  this->onClick = onClick;
}

