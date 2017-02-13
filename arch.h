#ifndef ARCH_H
#define ARCH_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

/*
This is the main header file for the engine that will have most classes underneath.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/12/17
*/

class Arch {
public:
  Arch();
  ~Arch();

  void createWindow();
  bool loopCall();

  void setPosX(int x) {posX = x;}
  void setPosY(int y) {posY = y;}
  void setWidth(int w) {width = w;}
  void setHeight(int h) {height = h;}
  void setTitle(string t) {title = t;}
  void declareWindow(int w, int h, string t) {setWidth(w); setHeight(h); setTitle(t);}
  void declareWindow(int w, int h, string t, int x, int y) {setWidth(w); setHeight(h); setTitle(t); setPosX(x); setPosY(y);}
  int getPosX() const {return posX;}
  int getPosY() const {return posY;}
  int getWidth() const {return width;}
  int getHeight() const {return height;}
  string getTitle() const {return title;}
private:
  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;
  int posX = 100, posY = 100, width = 320, height = 240;
  string title;
};

#endif //ARCH_H
