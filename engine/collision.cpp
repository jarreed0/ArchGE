#include "collision.h"

Collision::Collision() {}
Collision::~Collision() {}

bool Collision::isTouching(Object a, Object b) {
  if(!isAbove(a, b) && !isBelow(a, b)) {
    return true;
  } else if(!isRightOf(a, b) && !isLeftOf(a, b)) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isAbove(Object a, Object b) {
  if((a.getDY()-a.getDH()) > b.getDY()) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isBelow(Object a, Object b) {
  if(a.getDY() < (b.getDY()-b.getDH())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isRightOf(Object a, Object b) {
  if(a.getDX() > (b.getDX()+b.getDW())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isLeftOf(Object a, Object b) {
  if((a.getDX()+a.getDX()) < b.getDX()) {
    return true;
  } else {
    return false;
  }
}
