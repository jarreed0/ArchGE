#include "tileset.h"

Tileset::Tileset(int amount) {
  tiles = new Tile[amount+1];
  layersize = xsize = ysize = 0;
  set=false;
}
Tileset::~Tileset() {
  delete[]tiles;
}
void Tileset::setAng(int ang) {
  angle = ang;
  pushAng();
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
  set=true;
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
void Tileset::loadTiles(string filename, int iw, int ih) {
  ifstream in(filename.c_str());
  if(!in.is_open()) {
          cout << "Problem with loading the file" << endl;
          return;
  }
  int w, h;
  in >> w;
  in >> h;
  int current;
  //vector < vector <Tile> > tilevec;
  layer cur;
  cur.tw = iw;
  cur.tw = ih;
  cur.width = w;
  cur.height = h;
  for(int i=0;i<h;i++) {
    tile tmp;
    tmp.x=i;
          for(int j=0;j<w;j++) {
                  if(in.eof()) {
                          cout << "File end reached too soon" << endl;
                          return;
                  }
                  in >> current;
                  tmp.y=current;
          }
          tmp.tile = tiles[current];
          cur.tiles.push_back(tmp);
  }
  if(!in.eof()) {
    int setX, setY;
    in >> setX;
    in >> setY;
    cur.x = setX;
    cur.y = setY;
  }
  in.close();
  if(!set) {
    setCoord(cur.x, cur.y);
  }
  tileset.push_back(cur);
}
void Tileset::addTile(Tile t) {
  tiles[t.getValue()] = t;
}
vector<Tile> Tileset::getTilesToRender() {
  vector <Tile> vec;
  for(int i = 0; i<tileset.size(); i++) {
    int ttw = winWidth/tileset[i].tw;
    int tth = winHeight/tileset[i].tw;
    int startx = tileset[i].x-(ttw/2)-1;
    int starty = tileset[i].y-(tth/2)-1;
    int endx = ttw+1;
    int endy = tth+1;
    if(startx < 0) startx = 0;
    if(starty < 0) starty = 0;
    for(int j = 0; j<tileset[i].tiles.size(); j++) {
      if(startx <= tileset[i].tiles[j].x <= endx ) {
        if(starty <= tileset[i].tiles[j].y <= endy) {
          vec.push_back(tileset[i].tiles[j].tile);
        }
      }
    }
  }
  return vec;
}
void Tileset::move(int mx, int my) {
  x = x + mx;
  y = y = my;
}
