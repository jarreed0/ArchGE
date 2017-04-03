#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>
#include <vector>

#define SPEED 5
#define ROTATE 3
#define WIDTH 720
#define HEIGHT 580

class Game {
private:
  Engine e;
  Input i;
  Object o;
  Collision col;
  bool u,d,l,r;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
