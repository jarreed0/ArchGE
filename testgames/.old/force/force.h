#ifndef FORCE_H
#define FORCE_H

#include <iostream>
using namespace std;
#include <vector>
#include <arch/arch.h>

#define WIDTH 820
#define HEIGHT 680
#define TILE_SIZE 24
#define SPEED 2
#define TOTAL_TILES 60

class Force {
public:
  Force();
  ~Force();
  void loop();
  void draw();
  void input();
  void loadLevels();
private:
  Engine e;
  Input i;
  Level level;
  string TITLE = "Force";
  bool running;
  vector<Tile> disp;
  Entity player;
  int pLeft, pRight;
  Collision col;
  bool falling, jumping, moveLeft, moveRight;
  int jumpCount;
};

#endif //FORCE_H
