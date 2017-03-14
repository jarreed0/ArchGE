#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "object.h"

class Background : public Object {
private:
public:
  Background();
  ~Background();
  void setBackground(string file, int w, int h, SDL_Renderer* ren);
};

#endif //BACKGROUND_H
