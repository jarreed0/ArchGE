#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
using namespace std;
#include <fstream>

//! This class takes in a file and loads it in for the map
class Map {
private:
  vector< vector<int> > map;
  int startX, startY;
public:
  Map();
  ~Map();
  //! Read in map file with given path to the file.
  void loadMap(string filename);
  //! Get the start x coordinate found in the file.
  int getX() const { return startX; }
  //! Get the start y coordinate found in the file.
  int getY() const { return startY; }
  //! Get the vector of integers found in the file.
  vector< vector<int> > getMap() const { return map; }
};

#endif //MAP_H
