#ifndef COORD_H
#define COORD_H

using namespace std;
#include <iostream>

/*
This class stores coordinates.
Created by: Avery Reed on 2/14/17
Last Edited by: Avery Reed 2/16/17
*/

class Coord {
public:
  Coord();
  Coord(int sx, int sy);
  ~Coord();
  int getX() const {return x;}
  int getY() const {return y;}
  void setX(int sx) {x = sx;}
  void setY(int sy) {y = sy;}
  void setCoord(int sx, int sy) {setX(sx); setY(sy);}
private:
  int x;
  int y;
};

#endif //COORD_H
