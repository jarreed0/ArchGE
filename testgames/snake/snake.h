#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "../../engine/engine.h"
#include "../../engine/image.h"
#include "../../engine/input.h"

class Snake {
public:
  Snake();
  ~Snake();
  int exec();
  bool tick();
  void draw();
private:
  std::deque<std::pair<int, int> > segmentsList;
  unsigned ticks = 0;
  int dx = 1;
  int dy = 0;
  int fruitX;
  int fruitY;
  void generateFruit();
  int HeadOpenMouth = 0;
  int Tail = 1;
  int Turn = 2;
  int Straight = 3;
  int Head = 4;
  int Fruit = 5;
  int Width = 1280;
  int Height = 720;

  Engine eng;
  Object snake;
  Object cherry;
  Input handle;
};

#endif //SNAKE_H
