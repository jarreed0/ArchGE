#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>
#include <vector>
#include <iostream>
using namespace std;
#include <cstdlib>
#include <fstream>

#define SPEED 2
#define WIDTH 720
#define HEIGHT 580
#define SIZE 10

class Game {
private:
  Engine e;
  Input i;
  PerlinNoise noise;
  int seed;
  vector< vector<Object> > land;
  int x, y;
  int ground, max, min;
public:
  Game();
  void loop();
  void draw();
  void input();
  void update();
  void setSeed(int s) {seed=s; srand(seed);}
  bool inRange(int p, int s, int e);
};

#endif //GAME_H
