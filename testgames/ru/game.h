#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 370
#define HEIGHT 743
#define SPEED 3
#define SCORETOWIN 7

class Game {
private:
  Engine e;
  Input i;
  Object phone, map, fc, mc, party, settings, button, m, mouse;
  string looking;
  bool drawMenu;
  Collision col;
  int menum;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void menu();
};

#endif //GAME_H
