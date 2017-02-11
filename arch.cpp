#include "arch.h"

/*
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/10/17
*/

Arch::Arch() {
  gl.out("Created engine.\n");
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    gl.out("SDL_Init Error: ");
    gl.out(SDL_GetError());
    gl.out("/n");
  }
}

Arch::~Arch() {
  gl.out("Closing engine.\n");
}

bool Arch::createWindow() {
  Window window();
}
