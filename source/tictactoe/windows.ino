Screen mainMenu()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);
  
  SEButton *seb_singleplayer = new SEButton(15,25,300,60,(char*)"SINGLEPLAYER");
  SEButton *seb_multiplayer = new SEButton(15,95,300,60,(char*)"MULTIPLAYER");
  SEButton *seb_options = new SEButton(15,165,300,60,(char*)"OPTIONS");
  SEButton *seb_credits = new SEButton(15,235,300,60,(char*)"CREDITS");
  
  seb_singleplayer->setOnClick(&scli);
  seb_multiplayer->setOnClick(&sclii);
  seb_options->setOnClick(&scliii);
  seb_credits->setOnClick(&scliiii);  
  
  s.addElement(*seb_singleplayer);
  s.addElement(*seb_multiplayer);
  s.addElement(*seb_options);
  s.addElement(*seb_credits);

  return s;
}

void scli()
{
  tft.fillCircle(40,40,40,ILI9341_RED);
}

void sclii()
{
  tft.fillCircle(40,40,40,ILI9341_GREENYELLOW);
}

void scliii()
{
  tft.fillCircle(40,40,40,ILI9341_PINK);
}

void scliiii()
{
  sm.setScreen(s_credits);
}

Screen credits()
{
  //create Window  
  Screen s(0, ILI9341_BLACK);

  char *text = (char*)"TicTacToe\ncreated by\nJulian Altmeyer\nLukas Luschin";
  
  SEButton *seb_content = new SEButton(0,0,WIDTH,HEIGHT,text);
  
  seb_content->setOnClick(&back);  
  
  s.addElement(*seb_content);

  return s;
}

void back()
{
  sm.setScreen(s_menu);
}

