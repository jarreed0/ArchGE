#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <iostream>
#include "image.h"

class Object {
public:
  Object();
  ~Object();
  void setImage(string file, SDL_Renderer* ren);
  //void setImage(Image i) const {img = i;}
  Image getImage() const {return img;}
  SDL_Texture* getTexture();
  void setSource(double x, double y, int w, int h);
  void setDest(int w, int h);
  void setDest(int w, int h, double x, double y);
  void setDestCoord(double x, double y);
  SDL_Rect getSource();
  SDL_Rect getDest();
  SDL_Rect getBuff();
  void setSource(SDL_Rect s) {rect = s;}
  void setDest(SDL_Rect d) {dest = d;}
  void setBuff(SDL_Rect b) {buff = b;}
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
  bool collidable() {return solid;}
  void setSolid(bool s) {solid=s;}
  bool getSolid() const {return solid;}
  int createNewFrameSet(int fCount, int r, int c, int w, int h);
  SDL_Rect createNewFrame(int x, int y, int w, int h);
  void setCurFrameSet(int fs);
  void setCurFrame(int f);
  void nextFrame();
  void resetFrameSet();
  int getCurFrameSet() const {return curFrameSet;}
  int getCurFrame() const {return curFrame;}
private:
  Image img;
  SDL_Rect rect;
  SDL_Rect dest;
  SDL_Rect buff;
  double angle;
  bool solid;
  vector< vector <SDL_Rect> > frameset;
  int curFrameSet;
  int curFrame;
};

#endif //OBJECT_H
