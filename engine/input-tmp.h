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
  bool reset();
  int left; //!< Log ID for left
  int right; //!< Log ID for right
  int up; //!< Log ID for up
  int down; //!< Log ID for down
  int q; //!< Log ID for q
  int w; //!< Log ID for w
  int e; //!< Log ID for e
  int r; //!< Log ID for r
  int t; //!< Log ID for t
  int y; //!< Log ID for y
  int u; //!< Log ID for u
  int i; //!< Log ID for i
  int o; //!< Log ID for o
  int p; //!< Log ID for p
  int a; //!< Log ID for a
  int s; //!< Log ID for s
  int d; //!< Log ID for d
  int f; //!< Log ID for f
  int g; //!< Log ID for g
  int h; //!< Log ID for h
  int j; //!< Log ID for j
  int k; //!< Log ID for k
  int l; //!< Log ID for l
  int z; //!< Log ID for z
  int x; //!< Log ID for x
  int c; //!< Log ID for c
  int v; //!< Log ID for v
  int b; //!< Log ID for b
  int n; //!< Log ID for n
  int m; //!< Log ID for m
  int lshift; //!< Log ID for left shift
  int rshift; //!< Log ID for right shift
  int shift; //!< Shift ID for shift
  int quit; //!< Log ID for quit
  int esc; //!< Log ID for esc
  int mouseleft; //!< Log ID for left mouse click
  int mousemiddle; //!< Log ID for middle mouse click
  int mouseright; //!< Log ID for right mouse click
  int mouseup; //!< Log ID for scroll up on mouse wheel
  int mousedown; //!< Log ID for scroll down on mouse wheel
  int mousex; //!< Log ID for mouse x coordinate
  int mousey; //!< Log ID for mouse y coordinate
private:
  //! Array that stores what buttons are down.
  bool keys[51];
};

#endif //INPUT_H
