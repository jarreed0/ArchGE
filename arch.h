#ifndef ARCH_H
#define ARCH_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

/*
This is the main header file for the engine that will have most classes underneath.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/12/17
*/

class Arch {
public:
  Arch();
  Arch(int WIDTH, int HEIGHT);
  Arch(int WIDTH, int HEIGHT, Uint32 FLAGS);
  ~Arch();
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  SDL_Event event;
};

#endif //ARCH_H
