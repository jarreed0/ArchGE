#include "engine.h"

Engine::Engine() {
  simulationTime = 0;
  realTime = 0;
  fps = 1;
  bkg = 0;
  splashed = false;
  custom = false;
  debug = false;
}
Engine::~Engine() {
  SDL_DestroyRenderer(engren);
  SDL_DestroyWindow(engwin);
  SDL_Quit();
}

SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag) {
  init(s, w, h, flag, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_INIT_EVERYTHING);
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int it) {
  init(s, w, h, flag, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, it);
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int x, int y) {
  init(s, w, h, flag, x, y, SDL_INIT_EVERYTHING);
  return engren;
}
SDL_Renderer* Engine::init(string s, const int& w, const int& h, int flag, int x, int y, int it) {
  int res = SDL_Init(it);
  SDL_CHECK(res == 0, "SDL_Init");
  setSize(w, h);
  SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, flag, &engwin, &engren);
  SDL_CHECK(engwin, "SDL_CreateWindowAndRenderer");
  SDL_CHECK(engren, "SDL_CreateWindowAndRenderer");
  setPos(x, y);
  setName(s);
  loopStart();
  render();
  return engren;
}

void Engine::setName(string s) {
  SDL_SetWindowTitle(engwin, s.c_str());
}
void Engine::setPos(int x, int y) {
  SDL_SetWindowPosition(engwin, x, y);
}
void Engine::setSize(int w, int h) {
  WIDTH = w;
  HEIGHT = h;
}

SDL_Renderer* Engine::getRenderer() {
  return engren;
}

void Engine::setColor(Uint8 r, Uint8 g, Uint8 b) {
  red = r;
  green = g;
  blue = b;
}

void Engine::loopStart() {
  SDL_RenderClear(engren);
  SDL_SetRenderDrawColor(engren, red, green, blue, 0xff);
  if(bkg) drawBackground();
}
void Engine::render() {
  if(!splashed) { splash(); cout << "splash" << endl; }
  SDL_RenderPresent(engren);
  timeval a;
  realTime = gettimeofday(&a, 0);
}
void Engine::update() {
  simulationTime += 16;
  if(simulationTime < realTime) { fps = true; } else { fps = false; }
}

void Engine::draw(Object obj) {
  if(splashed) {
    SDL_Rect src = obj.getFrame();
    SDL_Rect des = obj.getDest();
    SDL_RenderCopyEx(engren, obj.getImage().getTexture(), &src, &des, obj.getAngle(), NULL, SDL_FLIP_NONE);
  }
}
void Engine::draw(vector<Object> objs) {
  if(splashed) {
    for(int i=0; i<objs.size(); i++) {
      draw(objs[i]);
    }
  }
}
void Engine::draw(Object obj, int key) {
  if(key = 4231998) {
    SDL_Rect src = obj.getFrame();
    SDL_Rect des = obj.getDest();
    SDL_RenderCopyEx(engren, obj.getImage().getTexture(), &src, &des, obj.getAngle(), NULL, SDL_FLIP_NONE);
  }
}
void Engine::draw(Level lvl) {
  if(splashed) {
    vector<Tile> tiles = lvl.getTilesToRender();
    for(int i=0; i<tiles.size(); i++) {
      draw(tiles[i]);
    }
    vector<Object> objects = lvl.getObjectsToRender();
    for(int i=0; i<objects.size(); i++) {
      draw(objects[i]);
    }
    vector<Entity> entities = lvl.getEntitiesToRender();
    for(int i=0; i<entities.size(); i++) {
      draw(entities[i]);
    }
  }
}

void Engine::setBackground(string filename) {
  Background b;
  b.setBackground(filename, WIDTH, HEIGHT, engren);
  background = b;
  bkg = true;
}
void Engine::drawBackground() {
  draw(background);
}

void Engine::splash() {
  setColor(0xff, 0xff, 0xff);
  Object s;
  //b.setImage("http://archeantus.net/images/splash.bmp", getRenderer());
  s.setImage("../../engine/res/engine-logo.png", getRenderer());
  s.setFrame(0, 0, 256, 256);
  s.center(WIDTH, HEIGHT);
  draw(s, 4231998);
  render();
  sleep(2.3);
  splashed=true;
  if(custom) runCustomSplash();
}
void Engine::bypassSplash(int key) {
  if(key = 4231998) {
    splashed = true;
  }
}
bool Engine::hasSplashed() {
  return splashed;
}
bool Engine::runCustomSplash() {
  Object b;
  b.setImage(cf.c_str(), getRenderer());
  b.setFrame(0, 0, cw, ch);
  b.center(WIDTH, HEIGHT);
  draw(b);
  render();
  sleep(ct);
}
void Engine::customSplash(string file, double time, int w, int h) {
  cf = file;
  ct = time;
  cw = w;
  ch = h;
  custom = true;
}

void Engine::debugMode(bool d) {
  debug = true;
  splashed = true;
  cout << "In debug mode!" << endl;
  cout << "Which at this time only means bypassing the splashscreen." << endl;
}

void Engine::hideMouseInWindow(Input i) {
  Object mouse;
  mouse.setPos(2, 2, i.getMouseX(), i.getMouseY());
  Object screen;
  screen.setPos(0, 0, WIDTH, HEIGHT);
  if(col.isTouching(mouse, screen)) {
    SDL_ShowCursor(false);
  } else {
    SDL_ShowCursor(true);
  }
}
