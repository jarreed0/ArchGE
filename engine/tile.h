#ifndef TILE_H
#define TILE_H

#include "object.h"

class Tile : public Object {
public:
  Tile();
  ~Tile();
  void setValue(int v);
  int getValue();
  void setName(string s);
  string getName();
private:
  int value;
  string name;
};

#endif //TILE_H
