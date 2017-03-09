#include "object.h"

Object::Object() {
  setAng(0);
  changeFrameOnMove(0);
}
Object::~Object() {}
void Object::setImage(string file, SDL_Renderer* ren) {img.loadImage(file, ren);}
SDL_Texture* Object::getImage() {return img.getImage();}
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
  if(frameonmove) nextFrame();
}
void Object::center(int w, int h) {
  setDest(getSW(), getSH(), (w/2)-(getSW()/2), (h/2)-(getSH()/2));
}
void Object::createFrameSet(string n, int count, int x, int y, int w, int h) {
  frameset tmp;
  tmp.name = n;
  for(int i=0; i<(count-1); i++) {
    tmp.frame.push_back(createFrame(x*i, y, w, h));
  }
  tmp.cur = 0;
  set.push_back(tmp);
}
SDL_Rect Object::createFrame(int x, int y, int w, int h) {
  SDL_Rect tmp;
  tmp.x = x;
  tmp.y = y;
  tmp.w = w;
  tmp.h = h;
  return tmp;
}
void Object::nextFrame() {
  for(int i=0; i<set.size(); i++) {
    if(set[i].name == activeFrameSet) {
      if(set[i].cur = set[i].frame.size()) {
        set[i].cur=0;
      } else {
        set[i].cur++;
      }
      setSource(set[i].frame[set[i].cur].x, set[i].frame[set[i].cur].y, set[i].frame[set[i].cur].w, set[i].frame[set[i].cur].h);
      break;
    }
  }
}
void Object::setCurFrame(int f) {
  for(int i=0; i<set.size(); i++) {
    if(set[i].name == activeFrameSet) {
      set[i].cur = f;
      break;
    }
  }
}
