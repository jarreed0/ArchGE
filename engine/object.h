#ifndef OBJECT_H
#define OBJECT_H

#include "image.h"
#include "input-tmp.h"
#include <SDL2/SDL.h>

class Collision;

//! This class stores information for an Object in the game.
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
  //! This sets if you want the Object to visible on the screen by passing in a boolean.
  void setDisplayable(bool d) { displayable = d; }
  //! Check if the Object is displayable by seeing if it is in a given screen.
  bool isDisplayable(Object screen) { checkDisplayable(screen); return displayable; }
  //! Checks if the Object is in the given screen.
  virtual void checkDisplayable(Object screen);
  //! Set the coordinate of the Object with a given x and y.
  void setCoord(double x, double y) { setX(x); setY(y); }
  //! Set the x coordinate with a given x.
  void setX(double sx) { x = sx; }
  //! Set the y coordinate with a given y.
  void setY(double sy) { y = sy; }
  //! Move along the x and y coordinate with a given x and y amount.
  void move(double x, double y) { moveX(x); moveY(y); }
  //! Move along the x coordinate with a given x amount.
  void moveX(double mx) { x += mx; }
  //! Move along the y coordinate with a given y amount.
  void moveY(double my) { y += my; }
  //! Get the current x coordinate.
  double getX() const { return x; }
  //! Get the current y coordinate.
  double getY() const { return y; }
  //! Get the Object's Image.
  Image getImage() const { return img; }
  //! Set the Object's Image with a given Image.
  void setImage(Image i) { img = i; }
  //! Give the path and renderer to create the Object's Image.
  void setImage(string file, SDL_Renderer* ren) { img.loadImage(file, ren); }
  //! Get the Object's angle.
  double getAngle() const { return angle; }
  //! Set the angle.
  void setAngle(double a) { angle = a; }
  //! Center the Object based on a width and height.
  void center(int w, int h);
  //! Get the frame that the Object parses from the Image.
  SDL_Rect getFrame() const { return frame; }
  //! Get the destination for the Object to be displayed on screen.
  SDL_Rect getDest() const { return dest; }
  //! Get the position of the Object in the world.
  SDL_Rect getPos() const { return pos; }
  //! Set the frame with a given SDL_Rect.
  void setFrame(SDL_Rect i) { frame = i; }
  //! Set the destination with a given SDL_Rect.
  void setDest(SDL_Rect i) { dest = i; }
  //! Set the position with a given SDL_Rect.
  void setPos(SDL_Rect i) { pos = i; }
  //! Set the frame with a given x and y coordinate and width and height.
  void setFrame(int x, int y, int w, int h) { setFrameCoord(x, y); setFrameSize(w, h); }
  //! Set the x and y coordinate of the frame.
  void setFrameCoord(int x, int y) { setFrameX(x); setFrameY(y); }
  //! Set the size of the frame with a width and height.
  void setFrameSize(int w, int h) { setFrameW(w); setFrameH(h); }
  //! Set the x coordinate of the frame.
  void setFrameX(int x) { frame.x = x; }
  //! Set the y coordinate of the frame.
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
  void centerOnMouse(Input i);
};

#endif //OBJECT_H
