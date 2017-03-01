#ifndef GENESIS_H
#define GENESIS_H

#include <iostream>
using namespace std;
#include <vector>
#include "../../engine/engine.h"
#include "../../engine/image.h"
#include "../../engine/input.h"
#include "../../engine/object.h"
#include "../../engine/physics.h"
#include "../../engine/tile.h"
#include "../../engine/tileset.h"
#include "../../engine/collision.h"
#include "../../engine/sdl_check.h"

#define WIDTH 1230
#define HEIGHT 580
#define TILE_SIZE 25

class Genesis {
public:
  Genesis();
  ~Genesis();
  void start();
  void draw();
  void checkInput();
private:
  Engine engine;
  Input input;
  Tileset map;
  bool running;
  string TITLE = "Genesis";
  Object background;
  Object player;
  vector<Tile> tiles;
  double speed;
  Collision colCheck;
};

#endif //GENESIS_H
