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
private:
  SDL_Renderer* engren;
  SDL_Window *engwin;
  int WIDTH, HEIGHT;
  Object background;
  bool bkg;
  bool splashed;
};

#endif //ENGINE_H
