#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define TILE_SIZE 45
#define TOTAL_TILES 16
#define TILES_PER_ROW 8
#define PLAYER_SIZE 35
#define SPEED 4
#define WIDTH 1200
#define HEIGHT 480

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
  Object crossair;
  Object bullet;
  int mcount = 0, mdelay = 20;
  Collision col;
  bool firenow;
  int firex, firey;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void fire(int mx, int my);
};

#endif //GAME_H

