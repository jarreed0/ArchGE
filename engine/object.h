#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <iostream>
#include "image.h"


//! Class for storing an image and the source and distination to display.
class Object {
public:
  Object();
  ~Object();
  //! Set the Objects image with a BMP image path and the renderer.
  void setImage(string file, SDL_Renderer* ren);
  //void setImage(Image i) const {img = i;}
  //! Get the Object's Image.
  Image getImage() const {return img;}
  //! Get the Image's texture.
  SDL_Texture* getTexture();
  //! Set the images source with the width, height, and x and y coordinates.
  void setSource(double x, double y, int w, int h);
  //! Set the display destinations width and height.
  void setDest(int w, int h);
  //! Set the display destinations width, height, and x and y coordinates.
  void setDest(int w, int h, double x, double y);
  //! Set the display destinations x and y coordinates.
  void setDestCoord(double x, double y);
  //! Get the SDL_Rect of the Objects image source.
  SDL_Rect getSource();
  //! Get the current SDL_Rect for the Objects destination.
  SDL_Rect getDest();
  //! Get the previous display destination.
  SDL_Rect getBuff();
  //! Set the image source destination with an SDL_Rect.
  void setSource(SDL_Rect s) {rect = s;}
  //! Set the Object's display destination with an SDL_Rect.
  void setDest(SDL_Rect d) {dest = d;}
  //! Set the object's previous display destination with an SDL_Rect.
  void setBuff(SDL_Rect b) {buff = b;}
  //! Set the image sources x coordinate.
  void setSX(double x);
  //! Set the image sources y coordinate.
  void setSY(double y);
  //! Set the image sources width.
  void setSW(int w);
  //! Set the image sources height.
  void setSH(int h);
  //! Set the display destinations x coordinate.
  void setDX(double x);
  //! Set the display destinations y coordinate.
  void setDY(double y);
  //! Set the display destinations width.
  void setDW(int w);
  //! Set the display destinations height.
  void setDH(int h);
  //! Get the image sources x coordinate.
  double getSX();
  //! Get the image sources y coordinate.
  double getSY();
  //! Get the image sources width.
  double getSW();
  //! Get the image sources height.
  double getSH();
  //! Get the display destinations x coordinate.
  double getDX();
  //! Get the display destinations y coordinate.
  double getDY();
  //! Get the display destinations width.
  double getDW();
  //! Get the display destinations height.
  double getDH();
  //! Set the Objects angle.
  void setAng(double a);
  //! Get the Objects angle.
  double getAng();
  //! Move the Object x and y amount.
  void move(double mx, double my);
  //! Center the Object's destination by the given screens (or anythings) width and height.
  void center(int w, int h);
  //! Check if the Object is solid, or collidable.
  bool collidable() {return solid;}
  //! Set the Object to be collidable/solid.
  void setSolid(bool s) {solid=s;}
  //! Check if the Object is solid.
  bool getSolid() const {return solid;}
  //! Create a new frameset with the given framecount for the set, the row to get the frameset from, the column to start at, and the width and height of each frame. Returns an int ID for the frameset.
  int createNewFrameSet(int fCount, int r, int c, int w, int h);
  //! Create a new frame with a given x and y coordinate and width and height. Automatically called from createNewFrameSet().
  SDL_Rect createNewFrame(int x, int y, int w, int h);
 //! Set the current frameset with the given frameset ID from calling createNewFrameSet().
  void setCurFrameSet(int fs);
  //! Set current frame in the frameset.
  void setCurFrame(int f);
  //! Change to the next frame. If it reaches its end, it restarts. Called in setCurFrameSet().
  void nextFrame();
  //! Set current frame to the beginning. Called in nextFrame() when it has reached its end.
  void resetFrameSet();
  //! Get the current frameset.
  int getCurFrameSet() const {return curFrameSet;}
  //! Get the current frame.
  int getCurFrame() const {return curFrame;}
private:
  //! The Objects image.
  Image img;
  //! The images source.
  SDL_Rect rect;
  //! The display destination.
  SDL_Rect dest;
  //! Previous display destination.
  SDL_Rect buff;
  //! Angle to be displayed.
  double angle;
  //! Boolean for if the Object is collidable/solid.
  bool solid;
  //! 2D vector of framesets that store frames.
  vector< vector <SDL_Rect> > frameset;
  //! Current frameset.
  int curFrameSet;
  //! Current frame.
  int curFrame;
};

#endif //OBJECT_H
