#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include "tile.h"

//! Class for loading in multiple Tiles.
class Tileset {
private:
  vector<Tile> tiles;
public:
  Tileset();
  ~Tileset();
  vector<Tile> getTileset() const { return tiles; }
  SDL_Rect getFrame(int i) { return tiles[i-1].getFrame(); }
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Push Tile in tile with given Tile.
  void addTile(Tile t);
  //! Generate and push Tile with tile name, path tot he tile image, SDL renderer, tile value, row and columg the tile as on in the image, the tiles width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int r, int c, int width, int height);
  //! Generate and push Tile with a given name, path to image file, SDL renderer, given value, and tile width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height);
  //! Generate and push Tile with a given name, path to the image, SDL renderer, value, and size (used for width and height).
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int size);
  //! Set the angle of all the tiles. Calls pushAng().
  void setAngle(int ang);
  void setSolid();
  void setSolid(int t);
  void setSolid(int s, int e);
  void setPassable();
  void setPassable(int t);
  void setPassable(int s, int e);
  void setName(string n, int id);
};

#endif //TILESET_H
