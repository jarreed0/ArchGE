#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 400
#define HEIGHT 400

class Game {
private:
  Model monkey;
  Engine e;
  Input i;
  double angleX, angleZ;
  Uint32 last_time, current_time, ellapsed_time, start_time;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
};

#endif //GAME_H
