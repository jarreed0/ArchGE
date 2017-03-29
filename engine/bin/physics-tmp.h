#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <math.h> //This library has functions for math, like cos() thought I don't know exactly how to use it all, nonetheless it should be simple

#include "object.h"
//Use this class to create and load in objects
//As of now (for things that can help you) this class stores an objects coordinates and size
//It stores other things, like its image, but those don't help you
//Eventually there will be other things added on or new classes that inherit it that can pass more variables to you
//The class has a function called getDest() which will return a SDL_Rect that stores its coordinates
//It also has setDX(int x) and setDY(int y) for setting its coordinates
//There is also setAng(int ang) and getAng() that you can use to figure out the objects angle/direction
//But like I said, soon it will hold other variables, such as weight, speed, etc. for physics
//I don't have any example functions that need to be created so just have at it and create whatever functions you want
//Below and in the .cpp file I have an example function that moves an object towards another object


//! Class for doing physics functions.
class Physics {
public:
  Physics();
  ~Physics();
  //This function will take two sets of points, and return the next of coordinates based on a set speed that head towards the second coordinate (des)
  //! Returns modified first Object that is moving towards the second object (I THINK).
  Object moveTowards(Object cur, Object des);
  //this function can be remade with different parameters
  //for example say you want an object to just move towards coordinates instead of an object you could do this:
  //SDL_Rect moveTowards(Object cur, int x, int y);
private:
};

#endif //PHYSICS_H
