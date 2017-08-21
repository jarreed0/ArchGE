#include "engine.h"

Engine::Engine() {
  //simulationTime = 0;
  //realTime = 0;
  setFPS = 60;
  bkg = 0;
  lastFrame = 0;
  splashed = false;
  custom = false;
  debug = false;
  setRunning(true);
  frameCount = lastTime = 0;capLast = capCur = 0;
  //framesPerSecond = 60;
  //capTime = 10;
  //capMark = renderMiliGap = cappedFrame = 0;
  glMode=false;
}
Engine::~Engine() {
  TTF_Quit();
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
  if(glMode) {
   SDL_GL_CreateContext(engwin);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(70,(double)w/h,1,1000);
   glEnable(GL_DEPTH_TEST);
  }
  TTF_Init();
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
  if(!glMode) SDL_RenderClear(engren);
  SDL_SetRenderDrawColor(engren, red, green, blue, 0xff);
  if(bkg) drawBackground();
  lastFrame = getTicks();
  curTime = time(0);
  if(curTime > lastTime) {
   lastTime = curTime; curFPS=frameCount; cout << "FPS: " << curFPS << endl; frameCount=0;
  }
}
void Engine::render() {
  //struct timespec spec; clock_gettime(CLOCK_REALTIME, &spec); capCur=round(spec.tv_nsec/1.0e6);
  //if(renderMiliGap = 0 || (capCur-capLast)>renderMiliGap) {
  if(!splashed) { splash(); cout << "splash" << endl; }
  timeval a;
  realTime = gettimeofday(&a, 0);
  frameCount++;
  //}
  //capLast=capCur;
  if(glMode) {
   glEnd();
   glFlush();
   SDL_GL_SwapWindow(engwin);
  } else {
   SDL_RenderPresent(engren);
  }

  int timerFps = getTicks() - lastFrame;
  if(timerFps < 1000/setFPS) {
    delay((1000/setFPS) - timerFps);
  }
}

void Engine::update() {
  //simulationTime += 16;
  //if(simulationTime < realTime) { fps = true; } else { fps = false; }
  if(glMode) {
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity( );
   gluLookAt(glView[0],glView[1],glView[2],glView[3],glView[4],glView[5],glView[6],glView[7],glView[8]);
  }
}

void Engine::loop() {
 render();
 loopStart();
 update();
}

void Engine::draw(Object obj) {
  if(splashed) {
     SDL_Rect des = obj.getDest();
    if(obj.imageSet()) {
     SDL_Rect src = obj.getFrame();
     SDL_RenderCopyEx(engren, obj.getImage().getTexture(), &src, &des, obj.getAngle(), NULL, SDL_FLIP_NONE);
    } else {
     SDL_SetRenderDrawColor(engren, obj.getColor().r, obj.getColor().g, obj.getColor().b, obj.getColor().a);
     SDL_RenderFillRect(engren, &des);
     SDL_SetRenderDrawColor(engren, red, green, blue, 255);
    }
  }
}
void Engine::draw(vector<Object> objs) {
  if(splashed) {
    for(int i=0; i<objs.size(); i++) {
      draw(objs[i]);
    }
  }
}
void Engine::draw(vector<vector<Object>> objs) {
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

void Engine::loadFont(char *font_path) {
    font = TTF_OpenFont(font_path, 24);
}

void Engine::draw(const char *text, int x, int y, int r, int g, int b) {
    SDL_Surface *surface;
    SDL_Texture *texture;

    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
    SDL_Rect rect;
    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(engren, surface);
    rect.x = x;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(engren, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
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

void Engine::hideMouse() {
  SDL_ShowCursor(false);
}

void Engine::showMouse() {
  SDL_ShowCursor(true);
}

void Engine::setGLView(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
  glView[0]=a; glView[1]=b; glView[2]=c; glView[3]=d; glView[4]=e; glView[5]=f; glView[6]=g; glView[7]=h; glView[8]=i;
}

int Engine::getTicks() { return SDL_GetTicks(); }
void Engine::delay(int time) { SDL_Delay(time); }
