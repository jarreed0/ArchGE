#include "arch.h"

/*
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/12/17
*/

//Create Engine and initialize SDL
Arch::Arch() {
  SDL_Init(SDL_INIT_VIDEO);
}

//Deconstruct Engine and SDL
Arch::~Arch() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

//Create a Window based on variables
void Arch::createWindow() {
  const char * t = title.c_str();
  win = SDL_CreateWindow(t, posX, posY, width, height, flags);
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
}

//function for gameloop for rendering window
bool Arch::loopCall() {
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return false;
    }
  }

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  return true;
}
