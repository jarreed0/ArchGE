#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "object.h"

//! Object that is a background image that covers the screen.
class Background : public Object {
private:
public:
  Background();
  ~Background();
  //! Sets the background with a path to the file name, the width and height of the screen, and the renderer.
  void setBackground(string file, int w, int h, SDL_Renderer* ren);
};

#endif //BACKGROUND_H
