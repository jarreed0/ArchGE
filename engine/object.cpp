#include "object.h"

Object::Object() {
  setAng(0);
}
Object::~Object() {}
void Object::setImage(string file, SDL_Renderer* ren) {img.loadImage(file, ren);}
SDL_Texture* Object::getTexture() {return img.getImage();}
void Object::setSource(double x, double y, int w, int h) {
  setSX(x);
  setSY(y);
  setSW(w);
  setSH(h);
}
void Object::setDest(int w, int h) {
  setDW(w);
  setDH(h);
}
void Object::setDest(int w, int h, double x, double y) {
  setDest(w, h);
  setDestCoord(x, y);
}
void Object::setDestCoord(double x, double y) {
   setDX(x);
   setDY(y);
}
SDL_Rect Object::getSource() {
  return rect;
}
SDL_Rect Object::getDest() {
  return dest;
}
void Object::setSX(double x) {rect.x = x;}
void Object::setSY(double y) {rect.y = y;}
void Object::setSW(int w) {rect.w = w;}
void Object::setSH(int h) {rect.h = h;}
void Object::setDX(double x) {buff.x = dest.x; dest.x = x;}
void Object::setDY(double y) {buff.y = dest.y; dest.y = y;}
void Object::setDW(int w) {buff.w = dest.w; dest.w = w;}
void Object::setDH(int h) {buff.h = dest.h; dest.h = h;}
double Object::getSX() {return rect.x;}
double Object::getSY() {return rect.y;}
double Object::getSW() {return rect.w;}
double Object::getSH() {return rect.h;}
double Object::getDX() {return dest.x;}
double Object::getDY() {return dest.y;}
double Object::getDW() {return dest.w;}
double Object::getDH() {return dest.h;}
SDL_Rect Object::getBuff() {
  return buff;
}
void Object::setAng(double a) {
  angle = a;
}
double Object::getAng() {
  return angle;
}
void Object::move(double mx, double my) {
  setDX(getDX()+mx);
  setDY(getDY()-my);
}
void Object::center(int w, int h) {
  setDest(getSW(), getSH(), (w/2)-(getSW()/2), (h/2)-(getSH()/2));
}
int Object::createNewFrameSet(int fCount, int r, int c, int w, int h) {
  vector <SDL_Rect> tmp;
  for(int i=0; i<fCount; i++) {
    tmp.push_back(createNewFrame(i+c, r, w, h));
  }
  frameset.push_back(tmp);
  return frameset.size();
}
SDL_Rect Object::createNewFrame(int x, int y, int w, int h) {
  SDL_Rect tmp;
  tmp.x = (x-1)*w;
  tmp.y = (y-1)*h;
  tmp.w = w;
  tmp.h = h;
  return tmp;
}
void Object::setCurFrameSet(int fs) {
  curFrameSet = fs;
  //setCurFrame(0);
  nextFrame();
}
void Object::setCurFrame(int f) {
  curFrame = f;
}
void Object::nextFrame() {
  if(curFrame = frameset[curFrameSet-1].size()) {
    resetFrameSet();
  }
  curFrame++;
  setSource(frameset[curFrameSet-1][curFrame-1].x, frameset[curFrameSet-1][curFrame-1].y, frameset[curFrameSet-1][curFrame-1].w, frameset[curFrameSet-1][curFrame-1].h);
}
void Object::resetFrameSet() {
  curFrame = 0;
}
