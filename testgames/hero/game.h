#ifndef GAME_H
#define GAME_H

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

#define WIDTH 1080
#define HEIGHT 480
#define TILE_SIZE 32
#define SPEED 2
#define TOTAL_TILES 54

class Game {
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void loadLevel();
  void mouseMove();
private:
  Engine e;
  Input i;
  Tileset level;
  string TITLE = "Hero";
  bool running;
  vector<Tile> disp;
  bool mm;
};

#endif //GAME_H
