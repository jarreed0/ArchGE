#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
  public:
    GameState();
    ~GameState();
    int SPLASH = 0, MENU = 1, INGAME = 2, GAMEOVER = 3, PAUSE = 4;
    int getGameState();
    void setGameState(int);
  private:
    int currentstate = 0;
};

#endif //GAMESTATE_H
