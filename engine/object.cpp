#include "object.h"

Object::Object() {
  angle = 0;
}
Object::~Object() {}
void Object::setImage(string file, SDL_Renderer* ren) {img.loadImage(file, ren);}
SDL_Texture* Object::getImage() {return img.getImage();}
void Object::setSource(int x, int y, int w, int h) {
  setSX(x);
  setSY(y);
  setSW(w);
  setSH(h);
}
void Object::setDest(int w, int h) {
  setDW(w);
  setDH(h);
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
int Object::getSX() {return rect.x;}
int Object::getSY() {return rect.y;}
int Object::getSW() {return rect.w;}
int Object::getSH() {return rect.h;}
int Object::getDX() {return dest.x;}
int Object::getDY() {return dest.w;}
int Object::getDW() {return dest.h;}
int Object::getDH() {return dest.h;}
void Object::setAng(int a) {
  angle = a;
}
int Object::getAng() {
  return angle;
}
