#include "H/image.h"

/*
Created by: Avery Reed on 2/16/17
Last Edited by: Avery Reed 2/16/17
*/

Image::Image() {
  tex = NULL;
  surface = NULL;
}

Image::Image(string n, string file, SDL_Renderer* ren) {
  tex = NULL;
  surface = NULL;
  setName(n);
  loadImage(file, ren);
}

Image::~Image() {
  //SDL_DestroyTexture(img);
  SDL_DestroyTexture(tex);
}

void Image::loadImage(const string &file, SDL_Renderer* r) {
  surface = SDL_LoadBMP("img/hello.bmp");
  tex = SDL_CreateTextureFromSurface(r, surface);
  SDL_FreeSurface(surface);
}

SDL_Renderer* Image::draw(SDL_Renderer *r) {
  SDL_RenderCopy(r, tex, NULL, NULL);
  return r;
}

/*void Image::loadImage(const std::string &file, SDL_Renderer* ren) {
  	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
  	if (texture == NULL){
  		cout << name << ": Image doesn't exist" << endl;
  	}
    img = texture;
}

void Image::parseImage() {

}

SDL_Renderer* Image::drawToScale(SDL_Renderer* ren, int x, int y, int w, int h) {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(ren, img, NULL, &dst);
  return ren;
}

SDL_Renderer* Image::draw(SDL_Renderer* ren, int x, int y) {
	int w, h;
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	ren = drawToScale(ren, x, y, w, h);
  return ren;
}*/
