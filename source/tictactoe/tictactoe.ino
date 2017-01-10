#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Adafruit_STMPE610.h>

#include "Screen.h"
#include "SEButton.h"

// The display also uses hardware SPI, plus #9 & #10
#define TFT_DC 9
#define TFT_CS 10

// The STMPE610 uses hardware SPI on the shield, and #8
#define STMPE_CS 8

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000

Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define WIDTH 240
#define HEIGHT 320

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  if (!ts.begin()) {
    Serial.println("Couldn't start touchscreen controller");
    while (1);
  }
  Serial.println("Touchscreen started");
}

void loop() {

  Screen current;

  //create Window
  SEButton seb1;
  seb1.setOnClick(&clii);
  
  Screen s;
  s.addElement(seb1);
  s.render(tft); 

  // check for tab on screen
  if (ts.bufferEmpty()) {
    return;
  }

  TS_Point p;
  
  while(!ts.bufferEmpty())
  {
    p = ts.getPoint();
  }
  
   

  p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());

  //Serial.println("Tabbed: " + p.x + ":" + p.y);
  Serial.print(p.x);
  Serial.print(":");
  Serial.print(p.y);
  Serial.print("\n");
  
  s.checkEvent(p.x, p.y);

}

void clii()
{
  tft.fillCircle(40,40,40,ILI9341_RED);
}



/*void mainWnd()
{
  // create window
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(0);

  drawBtn(15, 25, "SINGLEPLAYER");
  drawBtn(15, 95, "MULTIPLAYER");
  drawBtn(15, 165, "OPTIONS");
  drawBtn(15, 235, "CREDITS");

  delay(10);
}

void drawBtn(int x, int y, char* text)
{  
  tft.fillRect(x,y,300,60,ILI9341_DARKCYAN);
  tft.drawRect(x,y,300,60,ILI9341_BLUE);
  tft.drawRect(x+1,y+1,299,58,ILI9341_BLUE);

  tft.setCursor(x+8,y+23);
  tft.setTextColor(ILI9341_BLACK);
  tft.setTextSize(3);
  tft.println(text);
} */
