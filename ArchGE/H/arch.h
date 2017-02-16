#ifndef ARCH_H
#define ARCH_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

#include "object.h"
#include "coord.h"

/*
This is the main header file for the engine that will have most classes underneath.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/16/17
*/

class Arch {
public:
  Arch();
  Arch(int w, int h, string t);
  Arch(int w, int h, string t, int x, int y);
  Arch(int w, int h, string t, int x, int y, Uint32 f);
  Arch(int w, int h, string t, Uint32 f);
  void construct();

  ~Arch();

  void createWindow();
  bool loopCall();

  void setPosX(int x) {posX = x;}
  void setPosY(int y) {posY = y;}
  void setWidth(int w) {width = w;}
  void setHeight(int h) {height = h;}
  void setTitle(string t) {title = t;}
  void setFlags(Uint32 f) {flags = f;}
  void declareWindow(int w, int h, string t) {setWidth(w); setHeight(h); setTitle(t);}
  void declareWindow(int w, int h, string t, int x, int y) {setWidth(w); setHeight(h); setTitle(t); setPosX(x); setPosY(y);}
  void declareWindow(int w, int h, string t, int x, int y, Uint32 f) {setWidth(w); setHeight(h); setTitle(t); setPosX(x); setPosY(y); setFlags(f);}
  void declareWindow(int w, int h, string t, Uint32 f) {setWidth(w); setHeight(h); setTitle(t); setFlags(f);}
  int getPosX() const {return posX;}
  int getPosY() const {return posY;}
  int getWidth() const {return width;}
  int getHeight() const {return height;}
  string getTitle() const {return title;}
private:
  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;
  int posX, posY, width, height;
  string title;
  Uint32 flags;
};

#endif //ARCH_H
