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
#include "../../engine/sdl_check.h"

#define WIDTH 640
#define HEIGHT 480
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
  Tile grass;
  Tile rock;
  Tile flower;
  Tile water;
  Tile dirt;
  Tile copper;
  Tile iron;
  Tile wood;
  Tile torch;
  Tile table;
  Tile stone;
  Tile brick;
  Tile leaf;
  Tile cobble;
  Tile post;
  Tile chamber;
  Tile workbench;
  Tile plank;
  Tile chickenegg;
  Tile sand;
  Tile cactus;
  Tile snow;
  vector<Tile> tiles;
};

#endif //GENESIS_H
