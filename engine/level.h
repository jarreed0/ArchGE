#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "stage.h"
#include "collision.h"

class Level {
private:
  Stage stage;
  vector< vector<Tile>> tiles;
  double x, y;
  int tilewidth, tileheight;
  Object screen;
  Collision col;
public:
  Level();
  ~Level();
  void create();
  void setStage(Stage s) { stage = s; }
  void setStage(Map m, Tileset t) { stage.setMap(m); stage.setTileset(t); }
  void setScale(int w, int h);
  void setScale(int s) { setScale(s, s); }
  void calcPos();
  vector<Tile> getTilesToRender();
  void move(int mx, int my);
  void setCoord(double x, double y) { setX(x); setY(y); screen.setPosCoord(getX(), getY()); }
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }
  double getX() const { return x; }
  double getY() const { return y; }
  void setScreenSize(int w, int h) { screen.setPosSize(w, h); }
};

#endif //LEVEL_H
