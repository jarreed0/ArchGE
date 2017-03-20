#ifndef GAME_H
#define GAME_H

#include "../../engine/engine.h"
#include "../../engine/input-tmp.h"
#include "../../engine/tileset.h"
#include "../../engine/tile.h"
#include "../../engine/object.h"
#include "../../engine/entity.h"
#include "../../engine/map.h"
#include "../../engine/stage.h"
#include "../../engine/level.h"
#include "../../engine/physics-tmp.h"

#define SPEED 2
#define WIDTH 640
#define HEIGHT 480

class Game {
private:
  Engine e;
  bool running, timeToMove;
  Input i;
  Object o, o2;
  bool l, r, u, d;
  int vel = 300, mcount = 0;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
