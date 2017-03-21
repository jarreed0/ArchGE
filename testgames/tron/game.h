#ifndef GAME_H
#define GAME_H

#include "../../engine/engine.h"
#include "../../engine/input.h"
#include "../../engine/tileset.h"
#include "../../engine/tile.h"
#include "../../engine/object.h"
#include "../../engine/entity.h"
#include "../../engine/map.h"
#include "../../engine/stage.h"
#include "../../engine/level.h"
#include "../../engine/physics-tmp.h"
#include "../../engine/gamestate.h"

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
