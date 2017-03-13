#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

//! Class for checking and storing keyboard and mouse input.
class Input {
public:
  Input();
  ~Input();
  //! Log all current keys and buttons being pressed.
  void logPress();
  //! Check if a key has been pressed using a given key from this class. Ex: Input i; i.checkKey(i.up);
  bool checkKey(int k);
  //! Reset all pressed keystrokes and other inputs to false. Automatically down at the beginning of each logPress().
  void reset();
  //! All IDs for each button that is logged.
  int left, right, up, down, q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j,
    k, l, z, x, c, v, b, n, m, lshift, rshift, shift, quit, esc, mouseleft, mousemiddle, mouseright, mouseup, mousedown;
  int mousex, mousey; //! Coordinates for the mouses location.
private:
  //! Array that stores what buttons are down.
  bool keys[50];
};

#endif //INPUT_H
