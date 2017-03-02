#include "collision.h"

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
  if((a.getDY() + a.getDH()) < b.getDY()) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isBelow(Object a, Object b) {
  if(a.getDY() > (b.getDY() + b.getDH())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isRightOf(Object a, Object b) {
  if(a.getDX() > (b.getDX() + b.getDW())) {
    return true;
  } else {
    return false;
  }
}

bool Collision::isLeftOf(Object a, Object b) {
  if((a.getDX() + a.getDW()) < b.getDX()) {
    return true;
  } else {
    return false;
  }
}
Object Collision::calibrate(Object a, Object b) {
  if(isTouching(a, b) && b.collidable()) {
    /*int mx = a.getDX()-a.getBuff().x;
    int my = a.getDY()-a.getBuff().y;
    if(mx > 0) {
      a.setDX(b.getDX());
      a.setDX(a.getBuff().x);
    } else if(mx < 0) {
      a.setDX(b.getDX()+b.getDW());
    }
    if(my > 0) {
      a.setDY(b.getDY()+b.getDW());
    } else if(my < 0) {
      a.setDY(b.getDY());
    }*/
    a.setDX(a.getBuff().x);
    a.setDY(a.getBuff().y);
  }
  return a;
}
