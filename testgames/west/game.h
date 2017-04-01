#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 400
#define HEIGHT 400

class Game {
private:
  Engine e;
  Input i;
  Object bkg;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
