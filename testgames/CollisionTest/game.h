#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60
#define SPEED 4

class Game {
private:
  Engine e;
  Input i;
  Object area, block;
  Collision c;
  bool u, d, l, r;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
