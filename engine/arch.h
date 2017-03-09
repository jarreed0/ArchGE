#ifndef COLLISION_H
#define COLLISION_H

#include "object.h"

class Collision {
public:
  Collision();
  ~Collision();
  bool isTouching(Object a, Object b);
  bool outOfBoundsOf(Object a, Object b);
  bool isAbove(Object a, Object b);
  bool isBelow(Object a, Object b);
  bool isRightOf(Object a, Object b);
  bool isLeftOf(Object a, Object b);
  Object calibrate(Object a, Object b, int pad);
private:
};

#endif //COLLISION_H
#ifndef ENGINE_H
#define ENGINE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <cassert>
#include <unistd.h>

#include "image.h"
#include "object.h"
#include "input.h"
#include "physics.h"
#include "tile.h"
#include "tileset.h"
#include "collision.h"

class Engine {
public:
  Engine();
  ~Engine();
  SDL_Renderer* init(string s, const int& w, const int& h, int flag);
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int it);
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y);
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y, int it);
  void setName(string s);
  void deconstruct();
  void pushToScreen(Object obj);
  void pushToScreen(Object obj, int key);
  SDL_Renderer* renderScreen();
  void setColor(Uint32 r, Uint32 g, Uint32 b);
  void preLoop();
  void endLoop();
  void setBackground(string file);
  void setBackground(string file, int iw, int ih);
  void splash();
  void bypassSplash(int key);
  bool hasSplashed();
  bool runCustomSplash();
  void customSplash(string file, double time, int w, int h);
private:
  SDL_Renderer* engren;
  SDL_Window *engwin;
  int WIDTH, HEIGHT;
  Object background;
  bool bkg;
  bool splashed, custom;
  string cf;
  double ct;
  int cw, ch;
};

#endif //ENGINE_H
#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
//#include "inventory.h" //not yet created

class Entity : public Object {
public:
  Entity();
  ~Entity();
  double getHealth() const { return health; }
  void setHealth(double h) { health=h; }
  double getMaxHealth() const { return maxHealth; }
  void setMaxHealth(double mh) { maxHealth=mh; }
  void damage(double d);
  void heal(double h);
  int getEmotion() const { return emotion; }
  void setEmotion(int e) { emotion=e; }
  int getTeam() const { return team; }
  void setTeam(int t) { team=t; }
  bool isActive() const { return active; }
  void kill();
  void deactivate();
  void activate();
private:
  double health;
  double maxHealth;
  //Inventory inv; //not yet created
  int emotion;
  int team;
  bool active;
};

#endif //ENTITY_H
#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

class Image {
public:
  Image();
  ~Image();
  void loadImage(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
private:
  SDL_Texture* tex;
  string filename;
};

#endif //IMAGE_H
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

class Input {
public:
  Input();
  ~Input();
  void logPress();
  bool checkKey(int k);
  void reset();
  int left, right, up, down, q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j,
    k, l, z, x, c, v, b, n, m, lshift, rshift, shift, quit, esc, mouseleft, mousemiddle, mouseright, mouseup, mousedown;
  int mousex, mousey;
private:
  bool keys[50];
};

#endif //INPUT_H
#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <iostream>
#include "image.h"

class Object {
public:
  Object();
  ~Object();
  void setImage(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
  void setSource(double x, double y, int w, int h);
  void setDest(int w, int h);
  void setDest(int w, int h, double x, double y);
  void setDestCoord(double x, double y);
  SDL_Rect getSource();
  SDL_Rect getDest();
  SDL_Rect getBuff();
  void setSX(double x);
  void setSY(double y);
  void setSW(int w);
  void setSH(int h);
  void setDX(double x);
  void setDY(double y);
  void setDW(int w);
  void setDH(int h);
  double getSX();
  double getSY();
  double getSW();
  double getSH();
  double getDX();
  double getDY();
  double getDW();
  double getDH();
  void setAng(double a);
  double getAng();
  void move(double mx, double my);
  void center(int w, int h);
  bool collidable() {return solid;}
  bool setSolid(bool s) {this->solid=s;}
  void createFrameSet(string n, int count, int x, int y, int w, int h);
  SDL_Rect createFrame(int x, int y, int w, int h);
  void nextFrame();
  void setCurFrame(int f);
  void setCurFrameSet(string n) {activeFrameSet = n;}
  void changeFrameOnMove(bool fom) {frameonmove = fom;}
private:
  Image img;
  SDL_Rect rect;
  SDL_Rect dest;
  SDL_Rect buff;
  double angle;
  bool solid;
  struct frameset {
    vector<SDL_Rect> frame;
    string name;
    int cur;
  };
  vector<frameset> set;
  string activeFrameSet;
  bool frameonmove;
};

#endif //OBJECT_H
#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <math.h> //This library has functions for math, like cos() thought I don't know exactly how to use it all, nonetheless it should be simple

#include "object.h"
//Use this class to create and load in objects
//As of now (for things that can help you) this class stores an objects coordinates and size
//It stores other things, like its image, but those don't help you
//Eventually there will be other things added on or new classes that inherit it that can pass more variables to you
//The class has a function called getDest() which will return a SDL_Rect that stores its coordinates
//It also has setDX(int x) and setDY(int y) for setting its coordinates
//There is also setAng(int ang) and getAng() that you can use to figure out the objects angle/direction
//But like I said, soon it will hold other variables, such as weight, speed, etc. for physics
//I don't have any example functions that need to be created so just have at it and create whatever functions you want
//Below and in the .cpp file I have an example function that moves an object towards another object

class Physics {
public:
  Physics();
  ~Physics();
  //This function will take two sets of points, and return the next of coordinates based on a set speed that head towards the second coordinate (des)
  Object moveTowards(Object cur, Object des);
  //this function can be remade with different parameters
  //for example say you want an object to just move towards coordinates instead of an object you could do this:
  //SDL_Rect moveTowards(Object cur, int x, int y);
private:
};

#endif //PHYSICS_H
#pragma once
#include <stdexcept>
#include <string>

#define SDL_CHECK(x, msg) if (!(x))                                      \
    throw std::runtime_error(std::string(msg": ") + SDL_GetError())
#ifndef TILE_H
#define TILE_H

#include "object.h"

class Tile : public Object {
public:
  Tile();
  ~Tile();
  void setValue(int v);
  int getValue();
  void setName(string s);
  string getName();
private:
  int value;
  string name;
};

#endif //TILE_H
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
  void setCoord(int ix, int iy);
  void setWindowSize(int ww, int wh);
  int getX();
  int getY();
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
