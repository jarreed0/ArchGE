#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60

class Game {
private:
  Engine e;
  bool running, paused = false, movingl = false, movingr = false, lookingleft = false, lookingright = true;
  Input i;
  Collision col;
  Entity player;
  Object tile;
  int pframe = 0, iframe = 0, fcount = 0, fdelay = 10, icount = 0, idelay = 20;
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
};

#endif //GAME_H
