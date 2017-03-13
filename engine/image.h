#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include <iostream>

//! Class for loading in SDL Textures.
class Image {
public:
  Image();
  ~Image();
  //! Load in BMP image with the path to the BMP file and the renderer.
  void loadImage(string file, SDL_Renderer* ren);
  //! Load in a PNG image with the path to the PNG file and the renderer.
  void loadPNG(string file, SDL_Renderer* ren);
  //! Load in a BMP image with the path to the BMP file and the renderer.
  void loadBMP(string file, SDL_Renderer* ren);
  //! Get SDL_Texture.
  SDL_Texture* getImage();
  //! Set new, preloaded texture, to Image.
  void setImage(SDL_Texture* t) {tex=t;}
  //! Get path file of the image.
  string getFile() const {return filename;}
  //! Set path file to the image.
  void setFile(string f) {filename=f;}
private:
  //! SDL_Texture for the image.
  SDL_Texture* tex;
  //! Path file to the image.
  string filename;
};

#endif //IMAGE_H
