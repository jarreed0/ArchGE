#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 560
#define HEIGHT 380
#define SPEED 3

class Game {
private:
  Engine e;
  Input i;
  Object paddle;
  Object paddle2;
  Object ball, hitball;
  Object hitpaddle, hitpaddle2;
  int p;
  Collision col;
  float xballspeed, yballspeed;
  int score,score2;
  bool bhitball, bhitpaddle, bhitpaddle2;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void spawnball();
  void configballhit();
  void configpaddlehit();
  void configpaddle2hit();
};

#endif //GAME_H
