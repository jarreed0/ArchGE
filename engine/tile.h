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
  //! Get the value of the Tile.
  int getValue() const { return value; }
  //! Set if the Tile is solid.
  void setSolid() { solid = true; }
  //! Set if the Tile is passable (not solid).
  void setPassable() { solid = false; }
  //! Check if the Tile is solid.
  bool isSolid() const { return solid; }
};

#endif //TILE_H
