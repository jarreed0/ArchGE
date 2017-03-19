#include "object.h"
#include "collision.h"

Object::Object() {

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

void Object::centerOnMouse(Input i) {
  setDestCoord(i.getMouseX()-(getDestW()/2), i.getMouseY()-(getDestH()/2));
}
