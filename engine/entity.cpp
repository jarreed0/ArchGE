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
