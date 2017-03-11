#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <fstream>
#include "tile.h"
#include "object.h"
#include "collision.h"

class Tileset {
public:
  Tileset(int amount); //amout of types of tiles
  ~Tileset();
  void setAng(int ang);
  void pushAng();
  void setCoord(double ix, double iy);
  void setCoord(double ix, double iy, double mx, double my);
  void setWindowSize(int ww, int wh);
  double getX();
  double getY();
  vector<Tile> loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  vector<Tile> loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  vector<Tile> genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  vector<Tile> genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  void loadTiles(string filename, int iw, int ih);
  void addTile(Tile t); //push tile
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int r, int c, int width, int height);
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height);
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int size);
  vector<Tile> getTilesToRender();
  vector<Tile> getTilesToRender(int w, int h);
  void move(double mx, double my);
  Object move(double mx, double my, Object p);
  void calcPos(double mx, double my);
  void calcSetPos(int i, double mx, double my);
  void calcTilesPos(int i, double mx, double my);
  void setCameraMargin(int wm, int hm);
  void centerCamera(int percentage);
  Object getCamera();
  void setLensMargin(int wm, int hm);
  void centerLens(int percentage);
  Object getLens();
  void setSolid(int s, int l);
  void setSolid(int s, int e, int l);
  void setSolid(int l);
  void setPassable(int s, int l);
  void setPassable(int s, int e, int l);
  void setPassable(int l);
private:
  struct tile {
    double x = 0;
    double y = 0;
    Tile tile;
  };
  struct layer {
    int width = 0;
    int height = 0;
    double x = 0;
    double y = 0;
    int tw = 0;
    int th = 0;
    vector < tile > tiles;
  };
  int angle;
  double x, y;
  bool set;
  int winWidth, winHeight;
  int layersize, xsize, ysize;
  vector < layer > tileset;
  Tile *tiles;
  Object camera;
  Object lens;
  Collision colCheck;
  bool activeCam, activeLens;
};

#endif //TILESET_H
