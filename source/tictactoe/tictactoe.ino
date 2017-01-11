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
Screen menu(0,0);

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
  menu = mainMenu();
  sm.setScreen(menu);
}

void loop() {
  sm.render(tft);
  sm.checkEvents(ts);
}

Screen mainMenu()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);
  
  SEButton *seb_singleplayer = new SEButton(15,25,300,60,(char*)"SINGLEPLAYER");
  SEButton *seb_multiplayer = new SEButton(15,95,300,60,(char*)"MULTIPLAYER");
  SEButton *seb_options = new SEButton(15,165,300,60,(char*)"OPTIONS");
  SEButton *seb_credits = new SEButton(15,235,300,60,(char*)"CREDITS");
  
  seb_singleplayer->setOnClick(&clii);
  
  
  s.addElement(*seb_singleplayer);
  s.addElement(*seb_multiplayer);
  s.addElement(*seb_options);
  s.addElement(*seb_credits);

  return s;
}

void clii()
{
  tft.fillCircle(40,40,40,ILI9341_RED);
}

