#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include <iostream>

class Image {
public:
  Image();
  ~Image();
  void loadImage(string file, SDL_Renderer* ren);
  void loadPNG(string file, SDL_Renderer* ren);
  void loadBMP(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
  void setImage(SDL_Texture* t) {tex=t;}
  string getFile() const {return filename;}
  void setFile(string f) {filename=f;}
private:
  SDL_Texture* tex;
  string filename;
};

#endif //IMAGE_H
