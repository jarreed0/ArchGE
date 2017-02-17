#ifndef ENGINE_H
#define ENGINE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

#include "image.h"
#include "object.h"
#include "input.h"

class Engine {
public:
  Engine();
  ~Engine();
  SDL_Renderer* init(const int& w, const int& h, int flag);
  SDL_Renderer* init(const int& w, const int& h, int flag, int it);
  SDL_Renderer* init(const int& w, const int& h, int flag, int x, int y);
  SDL_Renderer* init(const int& w, const int& h, int flag, int x, int y, int it);
  void deconstruct();
  void pushToScreen(Object obj);
  SDL_Renderer* renderScreen();
  void setColor(Uint32 r, Uint32 g, Uint32 b);
  void preLoop();
  void endLoop();
private:
  SDL_Renderer* engren;
  SDL_Window *engwin;
};

#endif //ENGINE_H
