#ifndef GAME_H
#define GAME_H

#include "../../engine/arch.h"

#define SPEED 2
#define WIDTH 640
#define HEIGHT 480

class Game {
private:
  Engine e;
  bool running, facedown, faceup, faceleft, faceright, timeToMove;
  Input i;
  Object arena;
  Object bike;
  Object tile;
  Object logo;
  GameState gs;
  bool l, r, u, d;
  int vel, mcount = 0, scount = 0, sdelay = 1000;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
   void drawTiles();
};

#endif //GAME_H
