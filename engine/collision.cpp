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

bool Collision::overlaps(Object a, Object b) {
  //if (RectA.Left < RectB.Right && RectA.Right > RectB.Left && RectA.Top < RectB.Bottom && RectA.Bottom > RectB.Top ) 
  if ((a.getDestX() < (b.getDestX() + b.getDestW())) && ((a.getDestX() + a.getDestW()) > b.getDestX()) &&
   (a.getDestY() < (b.getDestY() + b.getDestH())) && ((a.getDestY() + a.getDestH()) > b.getDestY())) {
    return true;
  }
  else {
    return false;
  }
}

bool Collision::contains(Object a, Object b)
{
    if (((b.getDestX() + b.getDestW()) < (a.getDestX() + a.getDestW())) && (b.getDestX() > a.getDestX()) &&
     (b.getDestY() > a.getDestY()) && ((b.getDestY() + b.getDestH()) < (a.getDestY()+a.getDestH()))) {
        return true;
    }
    else {
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
