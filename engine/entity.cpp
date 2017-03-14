#include "entity.h"

Entity::Entity() {}

Entity::~Entity() {}

void Entity::damage(double d) {
  health -= d;
  if(health >= 0) {
    health = 0;
    kill();
  }
}
void Entity::heal(double h) {
  health += h;
  if(h > maxHealth) {
    health = maxHealth;
  }
}
void Entity::kill() {
  setHealth(0);
  deactivate();
}

void Entity::deactivate() {
  active = 0;
}
void Entity::activate() {
  active = 1;
}

void Entity::checkDisplayable(Object screen) {
  Object obj;
  obj.setDest(getDetect());
  if(col.isTouching(obj, screen)) {
    setDisplayable(true);
  } else {
    setDisplayable(false);
  }
}

void Entity::setDetectRange(int r) {
  setDetectRange(r, r);
}
void Entity::setDetectRange(int w, int h) {
  detect.x = getPosX()-w;
  detect.y = getPosY()-h;
  detect.w = getPosW()+w+w;
  detect.h = getPosH()+h+h;
}
