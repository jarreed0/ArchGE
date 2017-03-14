#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <cassert>
#include <unistd.h>
#include <sys/time.h>

#include "image.h"
#include "object.h"
#include "background.h"
#include "tile.h"
#include "entity.h"
#include "collision.h"
#include "tileset.h"
#include "tileset-tmp.h"
#include "input-tmp.h"
#include "physics-tmp.h"
#include "stage.h"
/*
#include "splash.h"
#include "level.h"
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
public:
  Engine();
  //! Decontructs renderer and window and then quits SDL.
  ~Engine();
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
  //! Sets SDL color.
  void setColor(Uint8 r, Uint8 g, Uint8 b);
  //! Call this at the end of the game loop to render.
  void render();
  //! Get fps.
  bool FPS() const { return fps; }
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
  void draw(Object obj, int key);
  //! Calls splashscreen at the beginning of the game. This is automatically called unless deactivated.
  void splash();
  //! Deactives the splashscreen, requires key.
  void bypassSplash(int key);
  //! Check if the splashscreen has occured.
  bool hasSplashed();
  //! Run custom splashscreen. This is automatically called after splash if there is a custom splashscreen.
  bool runCustomSplash();
  //! Create a custom game splashscreen to be shown after the engine splashscreen by passing in the path to the image, the duration for it be displayed, and the size of the image.
  void customSplash(string file, double time, int w, int h);
};

#endif //ENGINE_H
