#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include <iostream>

//! Class for loading in SDL Textures.
class Image {
private:
  SDL_Texture* tex; //!< SDL_Texture for the image.
  string filename; //!< Path file to the image.
public:
  Image();
  ~Image();
  //! Load in either a BMP or PNG file with the path and renderer.
  void loadImage(string file, SDL_Renderer* ren);
  //! Load in a PNG image with the path to the PNG file and the renderer.
  void loadPNG(string file, SDL_Renderer* ren);
  //! Load in a BMP image with the path to the BMP file and the renderer.
  void loadBMP(string file, SDL_Renderer* ren);
  //! Get SDL_Texture.
  SDL_Texture* getTexture();
  //! Set new, preloaded texture, to Image.
  void setImage(SDL_Texture* t) {tex=t;}
  //! Get path file of the image.
  string getFile() const {return filename;}
  //! Set path file to the image.
  void setFile(string f) {filename=f;}
  //! Set texture
  void setTexture(SDL_Texture* t) {tex=t;}
  void setSurface(SDL_Surface* s, SDL_Renderer* ren) {tex=SDL_CreateTextureFromSurface(ren, s); SDL_FreeSurface(s);}
};

#endif //IMAGE_H
