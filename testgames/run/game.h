#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>
#include <vector>

#define SPEED 7
#define ROTATE 1.5
#define WIDTH 1124
#define HEIGHT 580
#define SCALE 1.3

#define PSPEED 4
#define PROTATE 4

class Game {
private:
  Engine e;
  Input i;
  Object car;
  bool inCar;
  Entity player;
  Collision col;
  bool u,d,l,r;
  float vel, pvel;
  vector<Object> burn;
  Object bullet;
  vector<Object> bullets;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  double get_degrees(double input);
  void genBurn();
  void driveCar();
  void walk();
  void getOut();
  void getIn();
  void fire();
};

#endif //GAME_H
