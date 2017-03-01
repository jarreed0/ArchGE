#include "collision.h"

Collision::Collision() {}
Collision::~Collision() {}

bool Collision::isTouching(Object a, Object b) {
  if(!isAbove(a, b) && !isBelow(a, b)) {
    return true;
  } else if(!isRightOf(a, b) && !isLeftOf(a, b)) {
    return true;
  } else {
    cout << "nada" << endl;
    return false;
  }
}

bool Collision::outOfBoundsOf(Object a, Object b) {
  if(isAbove(a, b) || isBelow(a, b)) {
    return true;
  } else if(isRightOf(a, b) || isLeftOf(a, b)) {
    return true;
  } else {
    cout << "nada" << endl;
    return false;
  }
}

bool Collision::isAbove(Object a, Object b) {
  if((a.getDY() + a.getDH()) < b.getDY()) {
    cout << "above" << endl;
    return true;
  } else {
    return false;
  }
}

bool Collision::isBelow(Object a, Object b) {
  if(a.getDY() > (b.getDY() + b.getDH())) {
    cout << "below" << endl;
    return true;
  } else {
    return false;
  }
}

bool Collision::isRightOf(Object a, Object b) {
  if(a.getDX() > (b.getDX() + b.getDW())) {
    cout << "right" << endl;
    return true;
  } else {
    return false;
  }
}

bool Collision::isLeftOf(Object a, Object b) {
  if((a.getDX() + a.getDW()) < b.getDX()) {
    cout << "left" << endl;
    return true;
  } else {
    return false;
  }
}
