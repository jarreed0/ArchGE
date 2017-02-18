#ifndef OBJECT_H
#define OBJECT_H

#include "image.h"

class Object {
public:
  Object();
  ~Object();
  void setImage(string file, SDL_Renderer* ren);
  SDL_Texture* getImage();
  void setSource(int x, int y, int w, int h);
  void setDest(int w, int h);
  SDL_Rect getSource();
  SDL_Rect getDest();
  void setSX(int x);
  void setSY(int y);
  void setSW(int w);
  void setSH(int h);
  void setDX(int x);
  void setDY(int y);
  void setDW(int w);
  void setDH(int h);
  int getSX();
  int getSY();
  int getSW();
  int getSH();
  int getDX();
  int getDY();
  int getDW();
  int getDH();
  void setAng(int a);
  int getAng();
private:
  Image img;
  SDL_Rect rect;
  SDL_Rect dest;
  int angle;
};

#endif //OBJECT_H
