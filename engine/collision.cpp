#include "collision.h"
#include "object.h"

Collision::Collision() {}
Collision::~Collision() {}

bool Collision::isTouching(Object a, Object b) {
  if(!outOfBoundsOf(a, b)) {
    return true;
  } else {
    return false;
  }
}

bool Collision::outOfBoundsOf(Object a, Object b) {
  if(isAbove(a, b) || isBelow(a, b)) {
    return true;
  } else if(isRightOf(a, b) || isLeftOf(a, b)) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isAbove(Object a, Object b) {
  if((a.getDestY() + a.getDestH()) < b.getDestY()) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isBelow(Object a, Object b) {
  if(a.getDestY() > (b.getDestY() + b.getDestH())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isRightOf(Object a, Object b) {
  if(a.getDestX() > (b.getDestX() + b.getDestW())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isLeftOf(Object a, Object b) {
  if((a.getDestX() + a.getDestW()) < b.getDestX()) {
    return true;
  } else {
    return false;
  }
}
