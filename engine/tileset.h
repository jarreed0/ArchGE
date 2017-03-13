#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <fstream>
#include "tile.h"
#include "object.h"
#include "collision.h"

//! Class for loading in maps, tileset images, and then displaying them.
class Tileset {
public:
  //! Amout of types of tiles
  Tileset(int amount);
  ~Tileset();
  //! Set the angle of all the tiles. Calls pushAng().
  void setAng(int ang);
  //! Sets all tiles to the angle (I don't think this is working yet).
  void pushAng();
  //! Set the coordinate with a given x and y.
  void setCoord(double ix, double iy);
  //! Set the coordinate with the given x and y and the amount to move by on the x and y.
  void setCoord(double ix, double iy, double mx, double my);
  //! Set the window width and height.
  void setWindowSize(int ww, int wh);
  //! Gets the current x coordinate.
  double getX();
  //! Gets the current y cooridnate.
  double getY();
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Read in map file with given path to the file and width and height of the tiles.
  void loadTiles(string filename, int iw, int ih);
  //! Push Tile in tile with given Tile.
  void addTile(Tile t);
  //! Generate and push Tile with tile name, path tot he tile image, SDL renderer, tile value, row and columg the tile as on in the image, the tiles width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int r, int c, int width, int height);
  //! Generate and push Tile with a given name, path to image file, SDL renderer, given value, and tile width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height);
  //! Generate and push Tile with a given name, path to the image, SDL renderer, value, and size (used for width and height).
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int size);
  //! Get Tiles to renderer based on screen size and location.
  vector<Tile> getTilesToRender();
  //! Get tiles to renderer based on screen size, location, and given tile width and height.
  vector<Tile> getTilesToRender(int w, int h);
  //! Move map x and y amount.
  void move(double mx, double my);
  //! Given x and y amount to move and a given Object that also need to be moved, this function calculates the movement based on the Camera and Lens and then moves the Object and map if needed then returns the modified Object.
  Object move(double mx, double my, Object p);
  //! Moves all tilesets by looping through them and calling calcSetPos() given movement on the x and y coordinate.
  void calcPos(double mx, double my);
  //! Moves all tiles in a given tileset by looping through and calling calcTilesPos() given the point in the array the tileset is and the movement on the x and coordinates.
  void calcSetPos(int i, double mx, double my);
  //! Moves tile given the point on the array the tile is and the movement on the x and y coordinate.
  void calcTilesPos(int i, double mx, double my);
  //! Set the width and height of the Camera.
  void setCameraMargin(int wm, int hm);
  //! Set the Camera size based on percentage of window to cover.
  void centerCamera(int percentage);
  //! Get the Camera.
  Object getCamera();
  //! Set the width and height of the Lens.
  void setLensMargin(int wm, int hm);
  //! Set the Lens based on the percentage of the Camera to cover.
  void centerLens(int percentage);
  //! Get the Lens.
  Object getLens();
  //! Sets all tiles from a given start to end to solid. (I don't think this works yet).
  void setSolid(int s, int l);
  //! Sets all tiles in a given tileset from a given start to end to solid. (I don't think this works yet).
  void setSolid(int l); //! Sets a certain tile value to solid.
  void setSolid(int s, int e, int l);
  //! Sets all tiles from a given start to end to passable (not solid). (I don't think this works yet).
  void setPassable(int s, int l);
  //! Set all tiles in a given tileset from a given start to end to passable (not solid). (I don't think this works yet).
  void setPassable(int s, int e, int l);
 //! Set a certain tile value to passable (not solid). (I don't think this works yet).
  void setPassable(int l);
private:
  //! Contains the Tile and its x and y coordinate.
  struct tile {
    //! tile x coordinate
    double x = 0;
    //! tile y coordinate
    double y = 0; 
    //! tile's Tile
    Tile tile;
  }; 
  //! Contains a set of tiles, the width and height of the set, the x and y coordinate of the set, and the Tiles width and height.
  struct layer {
    //! layers width
    int width = 0;
    //! layers height
    int height = 0;
    //! layers x coordinate
    double x = 0;
    //! layers y coordinate
    double y = 0;
    //! Tiles width
    int tw = 0;
    //! Tiles height
    int th = 0;
    //! Vector of tiles
    vector < tile > tiles;
  };
  //! Display angle.
  int angle;
  //! Display/map coordinates.
  double x, y;
  //! Boolean that says if the maps coordinates has already been set.
  bool set;
  //! Window width and height.
  int winWidth, winHeight;
  //! Layer, x, and y size. (I don't think these are actually used).
  int layersize, xsize, ysize;
  //! Vector of layers (tilesets).
  vector < layer > tileset;
  //! Array of tiles with undeclared size.
  Tile *tiles;
  //! Camera object. When in the Camera, the map and Object move.
  Object camera;
  //! Lens object. When in the Lens, only the given Object moves.
  Object lens;
  //! Instance of Collision.
  Collision colCheck;
  //! Boolean that shows if the Camera and Lens have been activated.
  bool activeCam, activeLens;
};

#endif //TILESET_H
