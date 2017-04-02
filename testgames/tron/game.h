#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define SPEED 6
#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60
#define TILESIZE 64

class Game {
private:
  Engine e;
  bool running, facedown, faceup, faceleft, faceright;
  Input i;
  Collision col;
  Object arena;
  Entity bike;
  vector<Object> tile;
  Object logo;
  Object spawn;
  vector<Object> beam;
  int streak;
  GameState gs;
  bool l, r, u, d;
  bool paused;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void genTiles();
  void newBeam();
  void respawn();
};

#endif //GAME_H
