#include <math.h>
#include "object.h"
#include "collision.h"

Object::Object() {
 objsImage=false;
}
Object::~Object() {}

void Object::center(int w, int h) {
  setDestCoord((w/2)-(getDestW()/2), (h/2)-(getDestH()/2));
}

void Object::setName(string s) {
  name = s;
}
string Object::getName() {
  return name;
}

void Object::checkDisplayable(Object screen) {
  Collision col;
  Object obj;
  obj.setDest(getPos());
  if(col.isTouching(obj, screen)) {
    displayable = true;
  } else {
    displayable = false;
  }
}

void Object::centerOn(Input i) {
  setDestCoord(i.getMouseX()-(getDestW()/2), i.getMouseY()-(getDestH()/2));
}

void Object::centerOn(int cx, int cy) {
  setPosCoord(cx-(getDestW()/2), cy-(getDestH()/2));
}

void Object::setVelTo(Object o) {
  double angle = atan2(o.getDestY() - getDestY(), o.getDestX() - getDestX());
  double c = cos(angle) * getSpeed();
  double s = sin(angle) * getSpeed();
  setVelX(c);
  setVelY(s);
}

void Object::lookAt(Object o) {
  double angle = atan2(o.getDestY() - getDestY(), o.getDestX() - getDestX()) * (180/PI);
  setAngle(angle);
}

void Object::lookAt(Input i) {
  Object tmp;
  tmp.setDestCoord(i.getMouseX(), i.getMouseY());
  lookAt(tmp);
}

void Object::centerOn(Object obj) {
 centerOn(obj.getDestX()-(obj.getDestW()/2), obj.getDestY()-(obj.getDestH()/2));
}
