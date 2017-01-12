Screen mainMenu()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);
  
  SEButton *seb_singleplayer = new SEButton(15,25,300,60,(char*)"SINGLEPLAYER");
  SEButton *seb_multiplayer = new SEButton(15,95,300,60,(char*)"MULTIPLAYER");
  SEButton *seb_options = new SEButton(15,165,300,60,(char*)"OPTIONS");
  SEButton *seb_credits = new SEButton(15,235,300,60,(char*)"CREDITS");
  
  seb_singleplayer->setOnClick(&onClick_game);
  seb_multiplayer->setOnClick(&onClick_nothing);
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

Screen game()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);

  SEButton *seb_back = new SEButton(0,0,WIDTH,60,"EXIT");
  SEGrid *seg_game = new SEGrid(0,60,WIDTH,HEIGHT-60,3,3,ILI9341_YELLOW);

  seb_back->setOnClick(&onClick_back);
  seg_game->setOnClick(&onClick_eval);

  s.addElement(*seg_game);
  s.addElement(*seb_back);

  return s;  
}

void onClick_nothing()
{
  
}

void onClick_back()
{
  sm.setScreen(s_menu);
}

void onClick_game()
{
  *s_game = game();
  sm.setScreen(s_game);
}

void onClick_credit()
{
  sm.setScreen(s_credits);
}

void onClick_eval()
{
  SELabel *sel_asd = new SELabel(20,80,100,100,"X",ILI9341_CYAN,7);
  sel_asd->setOnClick(&onClick_nothing);
  s_game->addElement(*sel_asd);

  SELabel *sel_asw = new SELabel(20,170,100,100,"O",ILI9341_ORANGE,7);
  sel_asw->setOnClick(&onClick_nothing);
  s_game->addElement(*sel_asw);
  sm.setScreen(s_game);
}

