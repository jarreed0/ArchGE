#ifndef OBJECT_H
#define OBJECT_H

#include "global.h"
#include "coord.h"

/*
This class is going to be used to store basic values about objects in the game.
Created by: Avery Reed on 2/14/17
Last Edited by: Avery Reed 2/15/17
*/

class Object {
public:
  Object();
  Object(Coord c);
  ~Object();
  Coord getCoord() const {return c;}
  void setCoord(Coord ci) {c = ci;}
  string getName() const {return name;}
  void setName(string n) {name = n;}
private:
  Coord c;
  string name;
};

#endif //OBJECT_H
