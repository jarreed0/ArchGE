#include "object.h"
#include "collision.h"

Object::Object() {

}
Object::~Object() {}

void Object::center(int w, int h) {
  setDest(getFrameW(), getFrameH(), (w/2)-(getFrameW()/2), (h/2)-(getFrameH()/2));
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
