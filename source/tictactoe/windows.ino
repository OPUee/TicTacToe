Screen mainMenu()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);
  
  SEButton *seb_singleplayer = new SEButton(15,25,300,60,(char*)"ONE PLAYER");
  SEButton *seb_multiplayer = new SEButton(15,95,300,60,(char*)"TWO PLAYER");
  SEButton *seb_options = new SEButton(15,165,300,60,(char*)"OPTIONS");
  SEButton *seb_credits = new SEButton(15,235,300,60,(char*)"CREDITS");
  
  seb_singleplayer->setOnClick(&onClick_nothing);
  seb_multiplayer->setOnClick(&onClick_game);
  seb_options->setOnClick(&onClick_nothing);
  seb_credits->setOnClick(&onClick_credit);  
  
  s.addElement(*seb_singleplayer);
  s.addElement(*seb_multiplayer);
  s.addElement(*seb_options);
  s.addElement(*seb_credits);

  return s;
}

Screen credits()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);

  char *text = (char*)"TicTacToe\ncreated by\nJulian Altmeyer\nLukas Luschin";
  
  SELabel *sel_header = new SELabel(40,20,100,100,(char*)"TicTacToe",ILI9341_LIGHTGREY,3);
  SELabel *sel_line1 = new SELabel(90,60,100,100,(char*)"created by",ILI9341_LIGHTGREY,1);
  SELabel *sel_line2 = new SELabel(30,120,100,100,(char*)"Julian Altmeyer",ILI9341_LIGHTGREY,2);
  SELabel *sel_line3 = new SELabel(110,150,100,100,(char*)"&",ILI9341_LIGHTGREY,3);
  SELabel *sel_line4 = new SELabel(40,190,100,100,(char*)"Lukas Luschin",ILI9341_LIGHTGREY,2);

  SELabel *sel_back = new SELabel(0,0,WIDTH,HEIGHT,(char*)"",0,0);
  
  sel_header->setOnClick(&onClick_nothing);  
  sel_line1->setOnClick(&onClick_nothing);
  sel_line2->setOnClick(&onClick_nothing);
  sel_line3->setOnClick(&onClick_nothing);
  sel_line4->setOnClick(&onClick_nothing);

  sel_back->setOnClick(&onClick_back);

  s.addElement(*sel_back);
  s.addElement(*sel_header);
  s.addElement(*sel_line1);
  s.addElement(*sel_line2);
  s.addElement(*sel_line3);
  s.addElement(*sel_line4);

  return s;
}

// save the grid object global for evaluation process later... 
// it's nasty :S .. but wayne
SEGrid *seg_game = new SEGrid(0,60,WIDTH,HEIGHT-60,3,3,ILI9341_YELLOW);

Screen game()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);

  SEButton *seb_back = new SEButton(0,0,WIDTH,60,(char*)"EXIT");

  seb_back->setOnClick(&onClick_back);
  seg_game->setOnClick(&onClick_game_preeval);

  s.addElement(*seg_game);
  s.addElement(*seb_back);

  return s;  
}

void onClick_nothing(TS_Point p)
{
  
}

void onClick_back(TS_Point p)
{
  sm.setScreen(s_menu);
}

void onClick_game(TS_Point p)
{
  *s_game = game();
  sm.setScreen(s_game);
  cnt->reset();
}

void onClick_credit(TS_Point p)
{
  sm.setScreen(s_credits);
}

void onClick_game_draw(int pos)
{
  int vOffset = seg_game->width / seg_game->cols;
  int hOffset = seg_game->height / seg_game->rows;
  
  int col = pos % seg_game->cols;
  int row = pos / seg_game->cols;

  int x = (col * vOffset) + 23 + seg_game->x;
  int y = (row * hOffset) + 19 + seg_game->y; 
  
  if(cnt->getCurrentPlayer())
  {
    SELabel *sel_icon = new SELabel(x,y,100,100,(char*)"O",ILI9341_GREENYELLOW,7);
    sel_icon->draw(tft);
    delete sel_icon;
  }
  else
  {
    SELabel *sel_icon = new SELabel(x,y,100,100,(char*)"X",ILI9341_ORANGE,7);
    sel_icon->draw(tft);
    delete sel_icon;
  }

  // game postevaluation
  if(cnt->isGameOver())
  {
    // even better way than last time

    int winner = cnt->getWinner();
    char *text; 
    
    if(winner < 0)
    {
      text = (char*)"TIED!";
    }
    else
    {
      text = (char*)"PLAYER 1 WON";
      char *tmp;
      itoa(cnt->getWinner()+1,tmp,10);
      text[7] = *tmp;
    }
    
    SEButton *seb_over = new SEButton(0,130,240,60,text);
    seb_over->setOnClick(&onClick_nothing);
    s_game->addElement(*seb_over); 
    seb_over->draw(tft);
  }
  
}

void onClick_game_preeval(TS_Point p)
{
  int vOffset = seg_game->width / seg_game->cols;
  int hOffset = seg_game->height / seg_game->rows;

  p.x = p.x - seg_game->x;
  p.y = p.y - seg_game->y;

  int col = p.x / hOffset;
  int row = p.y / vOffset;

  int mPos = (row * seg_game->cols) + col;
  
  cnt->setMark(mPos);
}

