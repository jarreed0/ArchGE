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
Object Collision::calibrate(Object a, Object b, int pad) {
  if(isTouching(a, b) && b.collidable()) {
    /*int mx = a.getDX()-a.getBuff().x;
    int my = a.getDY()-a.getBuff().y;
    if(mx > 0) {
      a.setDX(b.getDX()+pad);
    } else if(mx < 0) {
      a.setDX(b.getDX()+b.getDW()+pad);
    }
    if(my > 0) {
      a.setDY(b.getDY()+pad);
    } else if(my < 0) {
      a.setDY(b.getDY()+b.getDW()+pad);
    }*/
    //a.setDX(a.getBuff().x);
    //a.setDY(a.getBuff().y);
    Object c;
    c.setDest(a.getDW(), a.getDH(), a.getBuff().x, a.getBuff().y);
    if(isAbove(c, b)) {
      a.setDY(b.getDY()+pad);
    } else if(isBelow(c, b)) {
      a.setDY(b.getDY()+b.getDH()+pad);
    }
    if(isRightOf(c, b)) {
      a.setDX(b.getDX()+b.getDW()+pad);
    } else if(isLeftOf(c, b)) {
      a.setDX(b.getDX()+pad);
    }
  }
  return a;
}
