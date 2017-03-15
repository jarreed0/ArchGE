#ifndef STAGE_H
#define STAGE_H

#include "tileset.h"
#include "map.h"

//! The Stage class stores a Map and Tileset.
class Stage {
private:
  Map map;
  Tileset tileset;
public:
  Stage();
  ~Stage();
  //! Create a stage by passing in a Map and Tileset.
  void createStage(Map m, Tileset t) { setMap(m); setTileset(t); }
  //! Create a stage by passing in the maps file, a name for the tiles, file of the tile image, the renderer, width and height of a tile, what row of the image the tiles are onem and how many tiles there are.
  void createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  void createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Set the Map by passing in a Map.
  void setMap(Map m) { map = m; }
  //! Load in a new map by passing in the map file.
  Map setMap(string filename) { map.loadMap(filename); return map; }
  //! Get the Map.
  Map getMap() const { return map; }
  //! Set the Tileset with a given Tileset.
  void setTileset(Tileset t) { tileset = t; }
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Get the Tileset.
  Tileset getTileset() const { return tileset; }
};

#endif //STAGE_H
