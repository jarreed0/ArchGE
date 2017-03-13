#ifndef TILE_H
#define TILE_H

#include "object.h"

//! An Object class that stores the a tile value and name.
class Tile : public Object {
public:
  Tile();
  ~Tile();
  //! Set value of the tile. This is used when reading from a map file, etc.
  void setValue(int v);
  //! Get the value of the tile.
  int getValue();
  //! Set the Tiles name.
  void setName(string s);
  //! Get the Tiles name.
  string getName();
private:
  //! Tiles value. Used for reading from a map file, etc.
  int value;
  //! Tile name.
  string name;
};

#endif //TILE_H
