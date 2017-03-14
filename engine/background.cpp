#include "background.h"

Background::Background() {

}
Background::~Background() {}

void Background::setBackground(string file, int w, int h, SDL_Renderer* ren) {
  setImage(file, ren);
  setFrame(0, 0, w, h);
  setDest(0, 0, w, h);
}
