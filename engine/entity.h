#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
//#include "inventory.h" //not yet created

class Entity : public Object {
public:
  Entity();
  ~Entity();
  double getHealth() const { return health; }
  void setHealth(double h) { health=h; }
  double getMaxHealth() const { return maxHealth; }
  void setMaxHealth(double mh) { maxHealth=mh; }
  void damage(double d);
  void heal(double h);
  int getEmotion() const { return emotion; }
  void setEmotion(int e) { emotion=e; }
  int getTeam() const { return team; }
  void setTeam(int t) { team=t; }
private:
  double health;
  double maxHealth;
  //Inventory inv; //not yet created
  int emotion;
  int team;
};

#endif //ENTITY_H
