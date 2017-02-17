#include "object.h"

Object::Object() {}
Object::~Object() {}
void Object::setImage(string file, SDL_Renderer* ren) {img.loadImage(file, ren);}
SDL_Texture* Object::getImage() {return img.getImage();}
void Object::setSource(int x, int y, int w, int h) {
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;
}
void Object::setDest(int w, int h) {
  dest.w = w;
  dest.h = h;
}
SDL_Rect Object::getSource() {
  return rect;
}
SDL_Rect Object::getDest() {
  return dest;
}
void Object::setSX(int x) {rect.x = x;}
void Object::setSY(int y) {rect.y = y;}
void Object::setSW(int w) {rect.w = w;}
void Object::setSH(int h) {rect.h = h;}
void Object::setDX(int x) {dest.x = x;}
void Object::setDY(int y) {dest.y = y;}
void Object::setDW(int w) {dest.w = w;}
void Object::setDH(int h) {dest.h = h;}
void Object::setAng(int a) {
  angle = a;
}
int Object::getAng() {
  return angle;
}
