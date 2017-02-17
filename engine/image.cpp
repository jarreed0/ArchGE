#include "image.h"

Image::Image() {}
Image::~Image() {}
void Image::loadImage(string file, SDL_Renderer* ren) {
  filename = file;
  SDL_Surface* surface = SDL_LoadBMP(file.c_str());
  SDL_CHECK(surface, "SDL_LoadBMP(\"file.c_str()\")");
  tex = SDL_CreateTextureFromSurface(ren, surface);
  SDL_CHECK(tex, "SDL_CreateTextureFromSurface");
  SDL_FreeSurface(surface);
}
SDL_Texture* Image::getImage() {
  return tex;
}
