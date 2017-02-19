#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <fstream>
#include "tile.h"

class Tileset {
public:
  Tileset(int amount); //amout of types of tiles
  ~Tileset();
  void setAng(int ang);
  void pushAng();
  void setCoord(int ix, int iy);
  void setWindowSize(int ww, int wh);
  int getX();
  int getY();
  void loadTiles(string filename);
  void addTile(Tile t); //push tile
  vector<Tile> getTilesToRender();
private:
  int angle;
  int x, y;
  int winWidth, winHeight;
  vector<int> width, height;
  int layersize, xsize, ysize;
  vector < vector < vector < int > > > tileset;
  Tile tiles[];
};

#endif //TILESET_H
