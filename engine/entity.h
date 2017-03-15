#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
#include "collision.h"
//#include "inventory.h" //not yet created

//! Class for storing health, emotion, team, etc. of an Object.
class Entity : public Object {
private:
  double health; //!< Int for the Entity's health.
  double maxHealth; //!< Int for the Enitity's max health.
  //Inventory inv; //!< Not yet created. Is going to be an instance of an Inventory class that need to be made.
  int emotion; //!< Int for creating a range of emotional states.
  int team; //!< Int for setting the team the Entity is on.
  bool active; //!< Boolean for declaring if an entity is active.
  Collision col;
  SDL_Rect detect;
public:
  Entity();
  ~Entity();
  //! Get Entity's health.
  double getHealth() const { return health; }
  //! Set the Entity's health. If the health is higher then the max health it will set it to the max health.
  void setHealth(double h) { health=h; }
  //! Get max health.
  double getMaxHealth() const { return maxHealth; }
  //! Set max health.
  void setMaxHealth(double mh) { maxHealth=mh; }
  //! Deal damage. Subtracted from health. If health is less then zero it kills the entity.
  void damage(double d);
  //! Give health to the Entity.
  void heal(double h);
  //! Get current emotion state.
  int getEmotion() const { return emotion; }
  //! Set current emotion state.
  void setEmotion(int e) { emotion=e; }
  //! Get Entity's team.
  int getTeam() const { return team; }
  //! Set Entity's team.
  void setTeam(int t) { team=t; }
  //! Check if Entity is active.
  bool isActive() const { return active; }
  //! Sets health to zero and deactives the Entity.
  void kill();
  //! Sets active to false.
  void deactivate();
  //! Sets active to true.
  void activate();
  //! Checks if an the Entity is in the current screen by passing the screen to it.
  void checkDisplayable(Object screen);
  //! Returns the detection radius.
  SDL_Rect getDetect() const { return detect; }
  //! Sets the detection with another SDL_Rect.
  void setDetect(SDL_Rect d) { detect = d; }
  //! Sets the detection radius with a single given distance.
  void setDetectRange(int r);
  //! Sets the detection radius with two given distances in both directions.
  void setDetectRange(int w, int h);
};

#endif //ENTITY_H
