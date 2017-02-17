#include "H/arch.h"

/*
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/16/17
*/

//Create Engine and initialize SDL
Arch::Arch() {
  construct();
}
//Constructor with specified windows
Arch::Arch(int w, int h, string t) {
  construct();
  declareWindow(w, h, t);
}
Arch::Arch(int w, int h, string t, int x, int y) {
  construct();
  declareWindow(w, h, t, x, y);
}
Arch::Arch(int w, int h, string t, Uint32 f) {
  construct();
  declareWindow(w, h, t, f);
}
Arch::Arch(int w, int h, string t, int x, int y, Uint32 f) {
  construct();
  declareWindow(w, h, t, x, y, f);
}

//Set Variables
void Arch::construct() {
  SDL_Init(SDL_INIT_VIDEO);
  posX = SDL_WINDOWPOS_UNDEFINED;
  posY = SDL_WINDOWPOS_UNDEFINED;
  width = 640;
  height = 480;
  flags = 0;
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

  //Game loop
  start=SDL_GetTicks();
	//SDL_BlitSurface(background,&camera,screen,NULL);
  if(!bkg.isNull()) drawBackground();
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  if(1000/30>(SDL_GetTicks()-start)) SDL_Delay(1000/30-(SDL_GetTicks()-start));
  //

  return true;
}

void Arch::drawBackground() {
  renderer = bkg.draw(renderer);
}
