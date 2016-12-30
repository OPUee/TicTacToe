
void drawIntro()
{
  for(int i = 0; i < 100; i++)
  {
    render(i*2);
    delay(1);
  }
}

void render(int i)
{
  // create window
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(3);
  
  // draw background
  drawStar(20,WIDTH-i);
  
  // draw logo
  tft.setCursor(60,100);
  tft.setTextColor(ILI9341_LIGHTGREY);
  tft.setTextSize(4);
  tft.println("TicTacToe"); 
}

void drawStar(int x, int y)
{
  // inner stuff
  tft.drawPixel(x,y,ILI9341_WHITE);
  tft.drawPixel(x-1,y,ILI9341_WHITE);
  tft.drawPixel(x+1,y,ILI9341_WHITE);
  tft.drawPixel(x,y-1,ILI9341_WHITE);
  tft.drawPixel(x,y+1,ILI9341_WHITE);
  tft.drawPixel(x,y+2,ILI9341_WHITE);

  // bloom
  tft.drawPixel(x,y-2,ILI9341_LIGHTGREY);
  tft.drawPixel(x,y+3,ILI9341_LIGHTGREY);
  tft.drawPixel(x,y+4,ILI9341_LIGHTGREY);

  // left side
  tft.drawPixel(x-1,y-1,ILI9341_LIGHTGREY);
  tft.drawPixel(x-1,y+1,ILI9341_LIGHTGREY);
  tft.drawPixel(x-1,y+2,ILI9341_LIGHTGREY);
  tft.drawPixel(x-1,y+3,ILI9341_LIGHTGREY);
  tft.drawPixel(x-2,y,ILI9341_LIGHTGREY);
  tft.drawPixel(x-2,y+1,ILI9341_LIGHTGREY);
  
  // right side
  tft.drawPixel(x+1,y-1,ILI9341_LIGHTGREY);
  tft.drawPixel(x+1,y+1,ILI9341_LIGHTGREY);
  tft.drawPixel(x+1,y+2,ILI9341_LIGHTGREY);
  tft.drawPixel(x+1,y+3,ILI9341_LIGHTGREY);
  tft.drawPixel(x+2,y,ILI9341_LIGHTGREY);
  tft.drawPixel(x+2,y+1,ILI9341_LIGHTGREY);

  //colored
  tft.drawPixel(x,y+5,ILI9341_DARKGREY);
  tft.drawPixel(x,y+6,ILI9341_DARKGREY);
  tft.drawPixel(x,y+7,ILI9341_DARKGREY);
  tft.drawPixel(x,y+8,ILI9341_DARKGREY);

  // left side
  tft.drawPixel(x-1,y-2,ILI9341_DARKGREY);
  tft.drawPixel(x-1,y+4,ILI9341_DARKGREY);
  tft.drawPixel(x-1,y+5,ILI9341_DARKGREY);
  tft.drawPixel(x-2,y-2,ILI9341_DARKGREY);
  tft.drawPixel(x-2,y-1,ILI9341_DARKGREY);
  tft.drawPixel(x-2,y+2,ILI9341_DARKGREY);
  tft.drawPixel(x-2,y+3,ILI9341_DARKGREY);
  tft.drawPixel(x-3,y-1,ILI9341_DARKGREY);
  tft.drawPixel(x-3,y,ILI9341_DARKGREY);
  tft.drawPixel(x-3,y+1,ILI9341_DARKGREY);
  
  // right side
  tft.drawPixel(x+1,y-2,ILI9341_DARKGREY);
  tft.drawPixel(x+1,y+4,ILI9341_DARKGREY);
  tft.drawPixel(x+1,y+5,ILI9341_DARKGREY);
  tft.drawPixel(x+2,y-2,ILI9341_DARKGREY);
  tft.drawPixel(x+2,y-1,ILI9341_DARKGREY);
  tft.drawPixel(x+2,y+2,ILI9341_DARKGREY);
  tft.drawPixel(x+2,y+3,ILI9341_DARKGREY);
  tft.drawPixel(x+3,y-1,ILI9341_DARKGREY);
  tft.drawPixel(x+3,y,ILI9341_DARKGREY);
  tft.drawPixel(x+3,y+1,ILI9341_DARKGREY);
  
}

void drawRainbow(char* text)
{
  
}

