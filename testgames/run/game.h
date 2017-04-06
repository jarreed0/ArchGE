#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>
#include <vector>

#define SPEED 7
#define ROTATE 1.5
#define WIDTH 720
#define HEIGHT 580

class Game {
private:
  Engine e;
  Input i;
  Object o;
  Collision col;
  bool u,d,l,r;
  bool pu,pd;
  float vel;
  vector<Object> burn;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  double get_degrees(double input);
  void genBurn();
};

#endif //GAME_H
