#ifndef TILE_H
#define TILE_H

#include "object.h"

//! An Object class that stores the a tile value and name.
class Tile : public Object {
private:
  int value; //!< Tiles value. Used for reading from a map file, etc.
  bool solid;
public:
  Tile();
  ~Tile();
  //! Set value of the tile. This is used when reading from a map file, etc.
  void setValue(int v);
  //! Get the value of the tile.
  int getValue() const { return value; }
  void setSolid() { solid = true; }
  void setPassable() { solid = false; }
  bool isSolid() const { return solid; }
};

#endif //TILE_H
