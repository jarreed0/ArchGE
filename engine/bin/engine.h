#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;
#include <iostream>
#include <cassert>
#include <string>
#include <unistd.h>
#include <sys/time.h>
#include <vector>
#include <ctime>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "image.h"
#include "object.h"
#include "background.h"
#include "tile.h"
#include "entity.h"
#include "collision.h"
#include "tileset.h"
#include "input.h"
#include "physics-tmp.h"
#include "stage.h"
#include "level.h"
#include "gamestate.h"

/*
#include "splash.h"
*/

//! Class for declaring an engine, which does basic SDL commands like creating the window and renderer.
class Engine {
private:
  SDL_Renderer* engren; //!< SDL Renderer.
  SDL_Window *engwin; //!< SDL Window.
  int WIDTH, HEIGHT; //!< Width and height of the window.
  int simulationTime, realTime; //!< Timestamps used for fps loop.
  //bool fps; //!< Boolean for loop.
  bool bkg; //!< Boolean for if there is a set background.
  Background background; //!< Background to display.
  Uint8 red, green, blue; //!< Colors for background.
  bool debug;
  bool running;
  time_t lastTime, curTime;
  long capLast, capCur;
  int frameCount;
  //int framesPerSecond, cappedFrame, capTime, capMark, renderMiliGap;
  bool glMode;
  int glView[9];
  int curFPS, setFPS, lastFrame;
  double gravity;
  TTF_Font *font;
  GameState gs;
  int sr,sg,sb;
  SDL_Color fcolor;
public:
  Engine();
  //! Decontructs renderer and window and then quits SDL.
  ~Engine();
  void setGravity(double g) {gravity=g;}
  void setFrameRate(int f) {setFPS=f;}
  double getGravity() const {return gravity;}
  //! Create a window with a given name, width, height, and anyother SDL_Window flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag);
  //! Create a window with a given name, width, height, SDL_Window flags, and  specified SDL_Init flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int it);
  //! Create a window with a given name, width, height, SDL_Window flags, and specified x and y coordinate.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y);
  //! Create a window with a given name, width, height, SDL_Window flags, specified x and y coordinate, and SDL_Init flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y, int it);
  //! Set window name.
  void setName(string s);
  //! Set window position.
  void setPos(int x, int y);
  //! Set window size.
  void setSize(int w, int y);
  //! Returns screen renderer.
  SDL_Renderer* getRenderer();
  //! Returns screen window.
  SDL_Window* getWindow() const { return engwin; }
  //! Sets SDL color.
  void setColor(Uint8 r, Uint8 g, Uint8 b);
  //! Call this at the beginning of a loop to initilaize the loop.
  void loopStart();
  //! Call this at the end of the game loop to render.
  void render();
  //! Get fps.
  //bool FPS() const { return fps; }
  //! Update loop time.
  void update();
  //! Set background.
  void setBackground(Background b) { background = b; }
  //! Set background with filename.
  void setBackground(string filename);
  //! Get background.
  Background getBackground() const { return background; }
  //! Draw background.
  void drawBackground();
  //! Draw an object on the screen.
  void draw(Object obj);
  //! Draw a vector of Objects
  void draw(vector<Object> objs);
  void draw(vector<vector<Object>> objs);
  //! Draw an object with a pass key before/during splash.
  void draw(Object obj, int key);
  //! Draw the level.
  void draw(Level lvl);
  //! Write to the screen with a char, coordinates, color, ttf file
  void draw(string text, int x, int y, int r, int g, int b);
  //! Calls splashscreen at the beginning of the game. This is automatically called unless deactivated.
  void splash();
  //! Deactives the splashscreen, requires key.
  void bypassSplash(int key);
  //! Check if the splashscreen has occured.
  bool hasSplashed();
  //! Active debugger with Boolean
  void debugMode(bool d);
  void loadFont(char *font_path);
  //! Set Font Color Using RGB.
  void setFontColor(int r, int g, int b);
  void hideMouse();
  void showMouse();
  bool getRunning() const { return running; }
  void setRunning(bool r) { running = r; }
  void setGLView(int a, int b, int c, int d, int e, int f, int g, int h, int i);
  void setGLMode(bool m) {glMode=m; glViewport(0, 0, WIDTH, HEIGHT); }
  int getFPS() const {return curFPS;}
  void loop();
  int getTicks();
  void delay(int time);
  void enableTransparency() {SDL_SetRenderDrawBlendMode(engren, SDL_BLENDMODE_BLEND);}
  struct color { Uint8 r, g, b; };
  void setGamestate(int s) {if(gs.getGameState()!=0) gs.setGameState(s);}
  int getGameState() {return gs.getGameState();}
  void setSplashColor(int r, int g, int b) {sr=r;sg=g;sb=b;}
};

#endif //ENGINE_H
