#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
using namespace std;
#include <fstream>

class Map {
private:
  vector< vector<int> > map;
  int startX, startY;
public:
  Map();
  ~Map();
  //! Read in map file with given path to the file and width and height of the tiles.
  void loadMap(string filename);
  int getX() const { return startX; }
  int getY() const { return startY; }
  vector< vector<int> > getMap() const { return map; }
};

#endif //MAP_H
