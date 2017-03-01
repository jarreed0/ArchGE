#ifndef OBJECT_H
#define OBJECT_H

#include "image.h"

class Object {
public:
  Object();
  ~Object();
  void setImage(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
  void setSource(double x, double y, int w, int h);
  void setDest(int w, int h);
  void setDest(int w, int h, double x, double y);
  void setDestCoord(double x, double y);
  SDL_Rect getSource();
  SDL_Rect getDest();
  void setSX(double x);
  void setSY(double y);
  void setSW(int w);
  void setSH(int h);
  void setDX(double x);
  void setDY(double y);
  void setDW(int w);
  void setDH(int h);
  double getSX();
  double getSY();
  double getSW();
  double getSH();
  double getDX();
  double getDY();
  double getDW();
  double getDH();
  void setAng(double a);
  double getAng();
  void move(double mx, double my);
  void center(int w, int h);
private:
  Image img;
  SDL_Rect rect;
  SDL_Rect dest;
  double angle;
};

#endif //OBJECT_H
