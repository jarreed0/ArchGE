#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "stage.h"
#include "entity.h"
#include "collision.h"

//! This class stores a Stage and Objects and can move them and display them.
class Level {
private:
  Stage stage;
  vector< vector<Tile>> tiles;
  vector<Object> objects;
  vector<Entity> entities;
  double x, y;
  int tilewidth, tileheight;
  Object screen;
  Collision col;
  bool precise;
  int mainEntityID;
  bool mainEntitySet;
  Object camera, lens;
  bool activeCam, activeLens;
public:
  Level();
  ~Level();
  //! Create the Level based on the given stage.
  void create();
  //! Give a Stage to the Level.
  void setStage(Stage s) { stage = s; }
  //! Create a Stage for the Level by giving a Map and a Tileset.
  void setStage(Map m, Tileset t) { stage.setMap(m); stage.setTileset(t); }
  //! Scale the Level by giving it the width and height to scale by.
  void setScale(int w, int h);
  //! Scale the Level by giving it a single integer to scale by.
  void setScale(int s) { setScale(s, s); }
  //! Calculate the position of the level based on coordinates.
  void calcPos();
  //! Return the Tiles that are currently on the screen.
  vector<Tile> getTilesToRender();
  //! Return the Objects that are currently on the screen.
  vector<Object> getObjectsToRender();
  //! Return the Entities that are currently on the screen.
  vector<Entity> getEntitiesToRender();
  //! Move the screen by passing in how much to move on the x and y coordinates.
  void move(int mx, int my);
  void moveEntity(int id, int mx, int my);
  //! Set the coordinate for the screen with a given x and y.
  void setCoord(double x, double y) { setX(x); setY(y); screen.setPosCoord(getX(), getY()); }
  //! Set the x coordinate.
  void setX(double x) { this->x = x; }
  //! Set the y coordinate.
  void setY(double y) { this->y = y; }
  //! Get the x coordinate.
  double getX() const { return x; }
  //! Get the y coordinate.
  double getY() const { return y; }
  Object getScreen() const { return screen; }
  //! Set the size of the screen by passing in the width and height.
  void setScreenSize(int w, int h) { screen.setPosSize(w, h); }
  //! Active precise if you want the coordinates in a map file to go to that exact pixel, or leave it off if you want it to go to that Tile.
  void setPrecise(bool p) { precise = p; }
  //! Add Object to Level
  void addObject(Object o);
  //! Add vector of Objects to Level
  void addObject(vector<Object> o);
  //! Add Entity to Level
  int addEntity(Entity e);
  //! Add vector of Entity's to Level
  void addEntity(vector<Entity> e);
  //! Set main Entity.
  int setMainEntity(Entity e);
  //! Tell Level which one Entity is the main one.
  int setMainEntity(int m);
  void setCameraMargin(int wm, int hm);
  void centerCamera(int percentage);
  void setLensMargin(int wn, int hm);
  void centerLens(int percentage);
  Object getCamera();
  Object getLens();
};

#endif //LEVEL_H
