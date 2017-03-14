#ifndef OBJECT_H
#define OBJECT_H

#include "image.h"
#include <SDL2/SDL.h>

class Collision;

class Object {
private:
  Image img;
  SDL_Rect frame, dest, pos;
  double angle;
  string name;
  double x, y;
  bool displayable;
public:
  Object();
  ~Object();
  void setDisplayable(bool d) { displayable = d; }
  bool isDisplayable(Object screen) { checkDisplayable(screen); return displayable; }
  virtual void checkDisplayable(Object screen);
  void setCoord(double x, double y) { setX(x); setY(y); }
  void setX(double x) { this->x = x; }
  void setY(double y) { this->y = y; }
  void move(double x, double y) { moveX(x); moveY(y); }
  void moveX(double x) { this->x += x; }
  void moveY(double y) { this->y += y; }
  double getX() const { return x; }
  double getY() const { return y; }
  Image getImage() const { return img; }
  void setImage(string file, SDL_Renderer* ren) { img.loadImage(file, ren); }
  double getAngle() const { return angle; }
  void setAngle(double a) { angle = a; }
  void center(int w, int h);
  SDL_Rect getFrame() const { return frame; }
  SDL_Rect getDest() const { return dest; }
  SDL_Rect getPos() const { return pos; }
  void setFrame(SDL_Rect i) { frame = i; }
  void setDest(SDL_Rect i) { dest = i; }
  void setPos(SDL_Rect i) { pos = i; }
  void setFrame(int x, int y, int w, int h) { setFrameCoord(x, y); setFrameSize(w, h); }
  void setFrameCoord(int x, int y) { setFrameX(x); setFrameY(y); }
  void setFrameSize(int w, int h) { setFrameW(w); setFrameH(h); }
  void setFrameX(int x) { frame.x = x; }
  void setFrameY(int y) { frame.y = y; }
  void setFrameW(int w) { frame.w = w; }
  void setFrameH(int h) { frame.h = h; }
  int getFrameX() const { return frame.x; }
  int getFrameY() const { return frame.y; }
  int getFrameW() const { return frame.w; }
  int getFrameH() const { return frame.h; }
  void setDest(int x, int y, int w, int h) { setDestCoord(x, y); setDestSize(w, h); }
  void setDestCoord(int x, int y) { setDestX(x); setDestY(y); }
  void setDestSize(int w, int h) { setDestW(w); setDestH(h); }
  void setDestX(int x) { dest.x = x; }
  void setDestY(int y) { dest.y = y; }
  void setDestW(int w) { dest.w = w; }
  void setDestH(int h) { dest.h = h; }
  int getDestX() const { return dest.x; }
  int getDestY() const { return dest.y; }
  int getDestW() const { return dest.w; }
  int getDestH() const { return dest.h; }
  void setPos(int x, int y, int w, int h) { setPosCoord(x, y); setPosSize(w, h); }
  void setPosCoord(int x, int y) { setPosX(x); setPosY(y); }
  void setPosSize(int w, int h) { setPosW(w); setPosH(h); }
  void setPosX(int x) { pos.x = x; }
  void setPosY(int y) { pos.y = y; }
  void setPosW(int w) { pos.w = w; }
  void setPosH(int h) { pos.h = h; }
  int getPosX() const { return pos.x; }
  int getPosY() const { return pos.y; }
  int getPosW() const { return pos.w; }
  int getPosH() const { return pos.h; }
  void moveFrame(int x, int y) { moveFrameX(x); moveFrameY(y); }
  void moveFrameX(int x) { frame.x += x; }
  void moveFrameY(int y) { frame.y += y; }
  void moveDest(int x, int y) { moveDestX(x); moveDestY(y); }
  void moveDestX(int x) { dest.x += x; }
  void moveDestY(int y) { dest.y += y; }
  void movePos(int x, int y) { movePosX(x); movePosY(y); }
  void movePosX(int x) { pos.x += x; }
  void movePosY(int y) { pos.y += y; }
  void setName(string s);
  string getName();
};

#endif //OBJECT_H
