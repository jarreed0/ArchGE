#include "engine.h"

Engine::Engine() {
  bkg = false;
}
Engine::~Engine() {}

SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag) {
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED);
  setName(s);
  WIDTH = w;
  HEIGHT = h;
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int it) {
  int res = SDL_Init(it);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED);
  setName(s);
  WIDTH = w;
  HEIGHT = h;
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int x, int y) {
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, x, y);
  setName(s);
  WIDTH = w;
  HEIGHT = h;
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int x, int y, int it) {
  int res = SDL_Init(it);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, x, y);
  setName(s);
  WIDTH = w;
  HEIGHT = h;
  return engren;
}

void Engine::setName(string s) {
  SDL_SetWindowTitle(engwin, s.c_str());
}

void Engine::deconstruct(){
  SDL_DestroyRenderer(engren);
  SDL_DestroyWindow(engwin);
  SDL_Quit();
}

void Engine::pushToScreen(Object obj) { //Insert NULL for source to display whole image
  SDL_Rect tsrc = obj.getSource();
  SDL_Rect tdes = obj.getDest();
  SDL_RenderCopyEx(engren, obj.getImage(), &tsrc, &tdes, obj.getAng(), NULL, SDL_FLIP_NONE);
}

SDL_Renderer* Engine::renderScreen() {
  return engren;
}

void Engine::setColor(Uint32 r, Uint32 g, Uint32 b) {
  SDL_SetRenderDrawColor(engren, r, g, b, 0xff);
}

void Engine::preLoop() {
  SDL_RenderClear(engren);
  if(bkg) pushToScreen(background);
}
void Engine::endLoop() {
  SDL_RenderPresent(engren);
}

void Engine::setBackground(string file) {
  setBackground(file, WIDTH, HEIGHT);
}
void Engine::setBackground(string file, int iw, int ih) {
  background.setImage(file, renderScreen());
  background.setSource(0, 0, iw, ih);
  background.setDest(WIDTH, HEIGHT, 0, 0);
  bkg = true;
}
