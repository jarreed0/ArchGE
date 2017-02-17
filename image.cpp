#include "H/image.h"

/*
Created by: Avery Reed on 2/16/17
Last Edited by: Avery Reed 2/16/17
*/

Image::Image() {

}

Image::~Image() {
  SDL_FreeSurface(img);
}

SDL_Surface* Image::loadImage(const char* filename) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
    if((Surf_Temp = IMG_Load(filename)) == NULL) return NULL;
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
    return Surf_Return;
}

void Image::parseImage() {

}
