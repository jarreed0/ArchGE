#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

class Image {
public:
  Image();
  ~Image();
  void loadImage(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
private:
  SDL_Texture* tex;
  string filename;
};

#endif //IMAGE_H
