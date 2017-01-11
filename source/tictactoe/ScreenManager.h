#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"

#include "Wire.h"
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Adafruit_STMPE610.h>

#define TFT_DC 9
#define TFT_CS 10

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000

#define WIDTH 240
#define HEIGHT 320

class ScreenManager
{
  public:
    ScreenManager();
    void setScreen(const Screen s);
    void render(Adafruit_ILI9341 tft);
    void checkEvents(Adafruit_STMPE610 ts);

  private:
    boolean isActive;
    const Screen *current;
    
};

#endif
