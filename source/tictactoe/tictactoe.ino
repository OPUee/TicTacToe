#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define WIDTH 240
#define HEIGHT 320

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {

  //drawIntro();
  //delay(3000);
  mainWnd();
}
void mainWnd()
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
}

