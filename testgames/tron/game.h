#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define SPEED 10
#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60

class Game {
private:
  Engine e;
  bool running, facedown, faceup, faceleft, faceright;
  Input i;
  Object arena;
  Object bike;
  Object tile;
  Object logo;
  GameState gs;
  bool l, r, u, d;
  int vel, timerFps = 0;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void drawTiles();
};

#endif //GAME_H
