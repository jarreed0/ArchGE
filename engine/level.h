#ifndef LEVEL_H
#define LEVEL_H

#include "tileset.h"
#include "map.h"

class Level {
private:
  Map map;
  Tileset tileset;
public:
  Level();
  ~Level();
  void createLevel(Map m, Tileset t) { setMap(m); setTileset(t); }
  void createLevel(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createLevel(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  void createLevel(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createLevel(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  void setMap(Map m) { map = m; }
  Map setMap(string filename) { map.loadMap(filename); return map; }
  Map getMap() const { return map; }
  void setTileset(Tileset t) { tileset = t; }
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  Tileset getTileset() const { return tileset; }
};

#endif //LEVEL_H
