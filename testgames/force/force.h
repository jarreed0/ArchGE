#ifndef FORCE_H
#define FORCE_H

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
#include "../../engine/entity.h"

#define WIDTH 820
#define HEIGHT 680
#define TILE_SIZE 24
#define SPEED 2
#define TOTAL_TILES 60

class Force {
public:
  Force();
  ~Force();
  void loop();
  void draw();
  void input();
  void loadLevels();
private:
  Engine e;
  Input i;
  Tileset level;
  string TITLE = "Force";
  bool running;
  vector<Tile> disp;
  Entity player;
  int pLeft, pRight;
  Collision col;
  bool falling, jumping, moveLeft, moveRight;
  int jumpCount;
};

#endif //FORCE_H
