#ifndef TILE_H
#define TILE_H

#include "object.h"

class Tile : public Object {
public:
  Tile();
  ~Tile();
  void setValue(int v);
  int getValue();

  //Tile& operator=(const Tile& rhs);
private:
  int value;
};

#endif //TILE_H
