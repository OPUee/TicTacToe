#ifndef CONTROLLER_H
#define CONTROLLER_H

#define GRID_SIZE 9

#define NOT_SET   -1
#define O_PLAYER  0
#define X_PLAYER  1

class Controller
{
  public:
    Controller();
    void setMark(int pos);
    void nextPlayer();
    void checkGameOver();
    bool isGameOver();
    int getWinner();
    int getCurrentPlayer();
    void reset();
    
  private:
    int currentPlayer;
    bool gameOver;
    int winner;
    int turnCount;
    int grid[GRID_SIZE];
};

#endif
