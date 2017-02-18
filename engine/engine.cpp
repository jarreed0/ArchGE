#include "engine.h"

Engine::Engine() {}
Engine::~Engine() {}

SDL_Renderer* Engine::init(const int& w, const int& h, int flag) {
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED);
  return engren;
}
SDL_Renderer* Engine::init(const int& w, const int& h, int flag, int it) {
  int res = SDL_Init(it);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED);
  return engren;
}
SDL_Renderer* Engine::init(const int& w, const int& h, int flag, int x, int y) {
  int res = SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, x, y);
  return engren;
}
SDL_Renderer* Engine::init(const int& w, const int& h, int flag, int x, int y, int it) {
  int res = SDL_Init(it);
  SDL_CHECK(res == 0, "SDL_Init");
  SDL_CreateWindowAndRenderer(w, h, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  SDL_SetWindowPosition(engwin, x, y);
  return engren;
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
}
void Engine::endLoop() {
  SDL_RenderPresent(engren);
}

int Engine::random(int min, int max) {
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);

   return num;
}

double Engine::random(double min, double max) {
   assert(min < max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   
   assert(min <= num && num <= max);

   return num;
}
