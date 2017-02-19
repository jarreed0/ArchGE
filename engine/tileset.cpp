#include "tileset.h"

Tileset::Tileset(int amount) {
  tiles[amount];
  layersize = xsize = ysize = 0;
}
Tileset::~Tileset() {}
void Tileset::setAng(int ang) {
  angle = ang;
}
void Tileset::pushAng() {
  for(int i = 0; i<sizeof(tiles); i++) {
    //if(tiles[i]!=NULL)
    tiles[i].setAng(angle);
  }
}
void Tileset::setCoord(int ix, int iy) {
  x = ix;
  y = iy;
}
void Tileset::setWindowSize(int ww, int wh) {
  winWidth = ww;
  winHeight = wh;
}
int Tileset::getX() {
  return x;
}
int Tileset::getY() {
  return y;
}
void Tileset::loadTiles(string filename) {
  ifstream in(filename.c_str());
  if(!in.is_open()) {
          cout << "Problem with loading the file" << endl;
          return;
  }
  int w, h;
  in >> w;
  in >> h;
  width.push_back(w);
  height.push_back(h);
  int current;
  vector < vector <int> > tilevec;
  for(int i=0;i<h;i++) {
          vector<int> vec;
          for(int j=0;j<w;j++) {
                  if(in.eof()) {
                          cout << "File end reached too soon" << endl;
                          return;
                  }
                  in >> current;
                  if(current>=1 && current<=23) {
                    vec.push_back(current);
                  }else{
                    vec.push_back(0);
                  }
          }
          tilevec.push_back(vec);
  }
  if(!in.eof()) {
    int setX, setY;
    in >> setX;
    in >> setY;
    x = setX*25;
    y = setY*25;
  }
  in.close();
  tileset.push_back(tilevec);
}
void Tileset::addTile(Tile t) {
  tiles[t.getValue()] = t;
}
vector<Tile> Tileset::getTilesToRender() {
//  for(int i = 0; tileset; i++) {  }
}
