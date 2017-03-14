#include "image.h"

Image::Image() {}
Image::~Image() {}
void Image::loadImage(string file, SDL_Renderer* ren) {
  if(file.substr(file.length() - 3) == "bmp") loadBMP(file, ren);
  if(file.substr(file.length() - 3) == "png") loadPNG(file, ren);
}
SDL_Texture* Image::getTexture() {
  return tex;
}
void Image::loadBMP(string file, SDL_Renderer* ren) {
  filename = file;
  SDL_Surface* surface = SDL_LoadBMP(file.c_str());
  SDL_CHECK(surface, "SDL_LoadBMP(\"file.c_str()\")");
  tex = SDL_CreateTextureFromSurface(ren, surface);
  SDL_CHECK(tex, "SDL_CreateTextureFromSurface");
  SDL_FreeSurface(surface);
}
void Image::loadPNG(string file, SDL_Renderer* ren) {
  filename = file;
  SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
  if(loadedSurface == NULL) {
     printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
  } else {
  tex = SDL_CreateTextureFromSurface(ren, loadedSurface);
  if(tex == NULL) {
     printf("Unable to create texture from %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
  }
  SDL_FreeSurface(loadedSurface);
  }
}
