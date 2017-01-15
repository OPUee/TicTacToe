// this is quite unbusinesslike, but this is the best I could get out of the lib in that time ;)

class Star
{
  public:
    Star(int x, int y)
    {
      this->x = x;
      this->y = y;
    }

    void afresh()
    {
      tft.fillRect(x-3,y-2,7,11,ILI9341_BLACK);
      inc();
    }

    void draw()
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
  private:
    int x;
    int y;

    void inc()
    {
      y -= 5;
      if(y < 11)
      {
        y = WIDTH;
      }
    }
};

class Rainbow
{
  public:
    Rainbow(char* text, int num)
    {
      this->text = text;
      this->num = num;
      this->cOff = 0;

      colors[0] = ILI9341_RED;
      colors[1] = ILI9341_ORANGE;
      colors[2] = ILI9341_YELLOW;
      colors[3] = ILI9341_GREEN;
      colors[4] = ILI9341_CYAN;
      colors[5] = ILI9341_BLUE;
    }

    void draw()
    {
      tft.setCursor(60,100);
      tft.setTextColor(ILI9341_LIGHTGREY);
      tft.setTextSize(4);
      
      for(int i = 0; i < num; i++)
      {
        tft.setCursor((22 * i) + 60,100);
        tft.setTextColor(colors[(i+cOff)%6]);
        tft.println(text[i]);
        delay(10);
      }

      cOff++;
    }
    
  private:
    char* text;
    int num;
    int cOff;
    int colors[6];
};


void drawIntro()
{
  Star *s[15];

  s[ 0] = new Star( 10, 25);
  s[ 1] = new Star( 40,143);
  s[ 2] = new Star( 60, 90);
  s[ 3] = new Star( 80,240);
  s[ 4] = new Star(100, 53);
  s[ 5] = new Star(120,195);
  s[ 6] = new Star(140, 49);
  s[ 7] = new Star(160,121);
  s[ 8] = new Star(180, 38);
  s[ 9] = new Star(200,209);
  s[10] = new Star(220, 83);
  s[11] = new Star(240, 17);
  s[12] = new Star(260,230);
  s[13] = new Star(280, 20);
  s[14] = new Star(300,151);

  Rainbow *r = new Rainbow((char*)"TicTacToe",9);
  
  // create window
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(3);  
  
  for(int i = 0; i < 50; i++)
  { 
    for(int j = 0; j < 15; j++)
    {
      s[j]->afresh();
      s[j]->draw();
    }

    // draw logo
    r->draw();
    delay(100);
  }

  // needs to be here... otherwise the lower row in the TicTac Toe grid wouldt work..
  // don't ask me why please -.-'
  tft.setRotation(0);

  for(int i = 0; i < 15; i++)
  {
    delete s[i];
  }
  delete r;
}

