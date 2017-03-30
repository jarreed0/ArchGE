#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <cassert>
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
#include "text.h"
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
  bool fps; //!< Boolean for loop.
  bool bkg; //!< Boolean for if there is a set background.
  Background background; //!< Background to display.
  Uint8 red, green, blue; //!< Colors for background.
  bool splashed, custom;  //!< Boolean that shows if the splashscreen has occured.
  string cf; //!< Custom splashscreen file path.
  double ct; //!< Custom splashscreen duration.
  int cw, ch; //!< Custom splashcreen width and height.
  bool debug;
  Collision col;
  Input input;
  bool exitOnEsc;
  bool running;
  time_t lastTime, curTime;
  long capLast, capCur;
  int frameCount;
  int framesPerSecond, cappedFrame, capTime, capMark, renderMiliGap;
  bool glMode;
  int glView[9];
  int curFPS;
  Text text;
  Uint8 fr, fg, fb;
  double gravity;
public:
  Engine();
  //! Decontructs renderer and window and then quits SDL.
  ~Engine();
  void setGravity(double g) {gravity=g;}
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
  //! Draw an object with a pass key before/during splash.
  void draw(Object obj, int key);
  //! Draw the level.
  void draw(Level lvl);
  //! Calls splashscreen at the beginning of the game. This is automatically called unless deactivated.
  void draw(int s, int x, int y);
  void draw(string s, int x, int y);
  void splash();
  //! Deactives the splashscreen, requires key.
  void bypassSplash(int key);
  //! Check if the splashscreen has occured.
  bool hasSplashed();
  //! Run custom splashscreen. This is automatically called after splash if there is a custom splashscreen.
  bool runCustomSplash();
  //! Create a custom game splashscreen to be shown after the engine splashscreen by passing in the path to the image, the duration for it be displayed, and the size of the image.
  void customSplash(string file, double time, int w, int h);
  //! Active debugger with Boolean
  void debugMode(bool d);
  void hideMouse();
  void showMouse();
  void exitOnEscape(bool e) { exitOnEsc=e; }
  bool getRunning() const { return running; }
  void setRunning(bool r) { running = r; }
  void setGLView(int a, int b, int c, int d, int e, int f, int g, int h, int i);
  void setGLMode(bool m) {glMode=m;}
  int getFPS() const {return curFPS;}
  void setFontColor(Uint8 r, Uint8 g, Uint8 b) {fr=r; fg=g; fb=b;}
};

#endif //ENGINE_H
