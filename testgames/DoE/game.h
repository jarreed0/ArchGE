#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60

class Game {
private:
  Engine e;
  bool running, paused = false, movingl = false, movingr = false, lookingleft = false, lookingright = true, jumping = false, nj = false;
  Input i;
  Collision col;
  Entity player;
  Object tile, tile2, tile3, ground, screen, ray, ray2;
  int pframe = 0, iframe = 0, fcount = 0, fdelay = 10, icount = 0, idelay = 20, jump = 0;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void updatePlayer();
  void gravity();
  void drawFloor();
  void nowJumping();
  void drawCRT();
};

#endif //GAME_H
