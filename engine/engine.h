#ifndef ENGINE_H
#define ENGINE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <cassert>
#include <unistd.h>

#include "image.h"
#include "object.h"
#include "input.h"
#include "physics.h"
#include "tile.h"
#include "tileset.h"
#include "collision.h"

//! Class for declaring an engine, which does basic SDL commands like creating the window and renderer.
class Engine {
public:
  Engine();
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
  //! Call in game deconstructor to destroy renderer, window, and to quit SDL.
  void deconstruct();
  //! Draw an object on the screen.
  void pushToScreen(Object obj);
  //! Draw an object on the screen during splashscreen, requires key.
  void pushToScreen(Object obj, int key);
  //! Returns screen renderer.
  SDL_Renderer* renderScreen();
  //! Sets SDL color.
  void setColor(Uint32 r, Uint32 g, Uint32 b);
  //! Call this at the beginning of the game loop.
  void preLoop();
  //! Call this at the end of the game loop.
  void endLoop();
  //! Give path file for a window background.
  void setBackground(string file);
  //! Give path file for a window background and width and height of the image to display.
  void setBackground(string file, int iw, int ih);
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
private:
  //! SDL Renderer.
  SDL_Renderer* engren;
  //! SDL Window.
  SDL_Window *engwin;
  //! Width and height of the window.
  int WIDTH, HEIGHT;
  //! Background object incase the user sets on from setBackground().
  Object background;
  //! Boolean that shows if there is a set background.
  bool bkg;
  //! Boolean that shows if the splashscreen has occured.
  bool splashed, custom;
  //! Custom splashscreen file path.
  string cf;
  //! Custom splashscreen duration.
  double ct;
  //! Custom splashcreen width and height.
  int cw, ch;
};

#endif //ENGINE_H
