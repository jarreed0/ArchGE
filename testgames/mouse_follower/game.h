#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>
#include <vector>

#define SPEED 5
#define WIDTH 720
#define HEIGHT 580

class Game {
private:
  Engine e;
  bool running, timeToMove;
  Input i;
  Object o, o2;
  vector<Object> mobjs, mobjs2, mobjs3, mobjs4;
  bool l, r, u, d;
  int vel = 300, mcount = 0;
  bool makeNewBlock;
  Collision col;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void createObj();
};

#endif //GAME_H
