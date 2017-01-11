#include "ScreenManager.h"

ScreenManager::ScreenManager()
{
  this->isActive = true;
  idI = 0;
}

void ScreenManager::setScreen(Screen *s)
{
  this->current = s;
  this->isActive = false;

  s->id = idI;
  idI++;
}

void ScreenManager::render(Adafruit_ILI9341 tft)
{
  if(!isActive)
  {
    Serial.print("render_screen_id: ");
    Serial.println(current->id);
    current->render(tft);
    isActive = true;
  }
}

void ScreenManager::checkEvents(Adafruit_STMPE610 ts)
{
  // check for tab on screen
  if (!ts.bufferEmpty())
  {
    TS_Point p;
    
    while(!ts.bufferEmpty())
    {
      p = ts.getPoint();
    }
    
    
    //p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    //p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, WIDTH);
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, HEIGHT);
  
    //Serial.println("Tabbed: " + p.x + ":" + p.y);
    Serial.print(p.x);
    Serial.print(":");
    Serial.print(p.y);
    Serial.print("\n");
    
    current->checkEvent(p.x, p.y);
  }
}

