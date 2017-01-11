/*#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Adafruit_STMPE610.h>*/

#include "ScreenManager.h"
#include "Screen.h"
#include "SEButton.h"

// The display also uses hardware SPI, plus #9 & #10
#define TFT_DC 9
#define TFT_CS 10

// The STMPE610 uses hardware SPI on the shield, and #8
#define STMPE_CS 8

#define WIDTH 240
#define HEIGHT 320


Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

ScreenManager sm;
Screen *s_menu = new Screen(0,0);
Screen *s_credits = new Screen(0,0);

void setup() {
  Serial.begin(9600);
  Serial.println("TicTacToe!"); 

  // init display
  tft.begin();
  
  // init touch screen
  if (!ts.begin()) {
    Serial.println("Couldn't start touchscreen controller");
    while (1);
  }
  Serial.println("Touchscreen started");

  Serial.println("BP0");

  // play intro
  //drawIntro();
  
  // create first screen
  *s_menu = mainMenu();
  *s_credits = credits();
  sm.setScreen(s_menu);

  
}

void loop() {
  sm.render(tft);
  sm.checkEvents(ts);
}

