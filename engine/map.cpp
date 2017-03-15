#include "map.h"

Map::Map() {
  startX = startY = 0;
}
Map::~Map() {}

void Map::loadMap(string filename) {
  ifstream in(filename.c_str());
  if(!in.is_open()) {
          cout << "Problem with loading the file" << endl;
          return;
  }
  int w, h;
  in >> w;
  in >> h;
  int current;
  for(int i=0;i<h;i++) {
    vector<int> row;
    for(int j=0;j<w;j++) {
      if(in.eof()) {
        cout << "File end reached too soon" << endl;
        return;
      }
      in >> current;
      row.push_back(current);
    }
    map.push_back(row);
  }
  if(!in.eof()) {
    in >> startX;
    in >> startY;
  }
  in.close();
}
