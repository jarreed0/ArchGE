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

#define TILE_SIZE 24
#define TOTAL_TILES 60
#define SPEED 2
#define WIDTH 750
#define HEIGHT 550

class Game {
private:
  Engine e;
  bool running;
  Input i;
  Level level;
  Stage stage;
  Map map;
  Tileset tileset;
  bool l, r, u, d;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
