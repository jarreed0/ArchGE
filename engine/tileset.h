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
  void loadTiles(string filename, int iw, int ih);
  void addTile(Tile t); //push tile
  void addTile(string name, string file, SDL_Renderer* ren, int value, int r, int c, int width, int height);
  void addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height);
  void addTile(string name, string file, SDL_Renderer* ren, int value, int size);
  vector<Tile> getTilesToRender();
  void move(int mx, int my);
private:
  struct tile {
    int x;
    int y;
    Tile tile;
  };
  struct layer {
    int width;
    int height;
    int x;
    int y;
    int tw, th;
    vector < tile > tiles;
  };
  int angle;
  int x, y;
  bool set;
  int winWidth, winHeight;
  int layersize, xsize, ysize;
  vector < layer > tileset;
  Tile *tiles;
};

#endif //TILESET_H
