#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define TILE_SIZE 24
#define TOTAL_TILES 60
#define SPEED 1
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
  Entity player;
  int mcount = 0, mdelay = 20;
  Collision col;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
