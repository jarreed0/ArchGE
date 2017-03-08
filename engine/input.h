#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

class Input {
public:
  Input();
  ~Input();
  void logPress();
  bool checkKey(int k);
  void reset();
  int left, right, up, down, q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j,
    k, l, z, x, c, v, b, n, m, lshift, rshift, shift, quit, esc, mouseleft, mousemiddle, mouseright, mouseup, mousedown;
  int mousex, mousey;
private:
  bool keys[50];
};

#endif //INPUT_H
