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
  if((a.getPosY() + a.getPosH()) < b.getPosY()) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isBelow(Object a, Object b) {
  if(a.getPosY() > (b.getPosY() + b.getPosH())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isRightOf(Object a, Object b) {
  if(a.getPosX() > (b.getPosX() + b.getPosW())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isLeftOf(Object a, Object b) {
  if((a.getPosX() + a.getPosW()) < b.getPosX()) {
    return true;
  } else {
    return false;
  }
}
