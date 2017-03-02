#ifndef COLLISION_H
#define COLLISION_H

#include "object.h"

class Collision {
public:
  Collision();
  ~Collision();
  bool isTouching(Object a, Object b);
  bool outOfBoundsOf(Object a, Object b);
  bool isAbove(Object a, Object b);
  bool isBelow(Object a, Object b);
  bool isRightOf(Object a, Object b);
  bool isLeftOf(Object a, Object b);
  Object calibrate(Object a, Object b, int pad);
private:
};

#endif //COLLISION_H
