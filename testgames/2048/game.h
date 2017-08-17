#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 353
#define HEIGHT 353
#define SPEED 3
#define SCORETOWIN 7

class Game {
private:
  Engine e;
  Input i;
  Object grid;
  bool l,r,u,d;
  int tiles[4][4];
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void drawGrid();
};

#endif //GAME_H
