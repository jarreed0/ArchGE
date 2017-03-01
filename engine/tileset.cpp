#include "tileset.h"

Tileset::Tileset(int amount) {
  tiles = new Tile[amount+1];
  layersize = xsize = ysize = x = y = 0;
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
vector<Tile> Tileset::loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp;
  tmp = genMap(name, map, img, ren, width, height, r, count);
  return tmp;
}
vector<Tile> Tileset::genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp;
  for(int i=0; i<(count-1); i++) {
    tmp.push_back(addTile(name, img, ren, i, r, i, width, height));
  }
  loadTiles(map, width, height);
  return tmp;
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
  layer cur;
  cur.tw = iw;
  cur.th = ih;
  cur.width = w;
  cur.height = h;
  for(int i=0;i<h;i++) {
          for(int j=0;j<w;j++) {
                  if(in.eof()) {
                          cout << "File end reached too soon" << endl;
                          return;
                  }
                  in >> current;
                  if(current != 0) {
                    tile tmp;
                    tmp.tile = tiles[current];
                    tmp.x=j;
                    tmp.y=i;
                    cur.tiles.push_back(tmp);
                  }
          }
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
Tile Tileset::addTile(string name, string file, SDL_Renderer* ren, int value, int c, int r, int width, int height) {
  Tile tmp;
  tmp.setName(name);
  tmp.setSource(((r-1)*width), ((c-1)*height), width, height);
  tmp.setImage(file, ren);
  tmp.setValue(value);
  tiles[value] = tmp;
  return tmp;
}
Tile Tileset::addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height) {
  Tile tmp = addTile(name, file, ren, value, 1, value, width, height);
  return tmp;
}
Tile Tileset::addTile(string name, string file, SDL_Renderer* ren, int value, int size) {
  Tile tmp = addTile(name, file, ren, value, 1, value, size, size);
  return tmp;
}
vector<Tile> Tileset::getTilesToRender() {
  vector <Tile> vec;
  for(int i = 0; i<tileset.size(); i++) {
    int ttw = winWidth/tileset[i].tw/2+2;
    int tth = winHeight/tileset[i].tw/2+2;
    tileset[i].x = 0;
    tileset[i].y = 0;
    int startx = tileset[i].x-(ttw/2)-tileset[i].tw;
    int starty = tileset[i].y-(tth/2)-tileset[i].th;
    int endx = ttw+tileset[i].tw;
    int endy = tth+tileset[i].th;
    //cout << "SX: " << startx << ", EX: " << endx << "\nSY: " << starty << ", EY: " << endy << endl;
    for(int j = 0; j<tileset[i].tiles.size(); j++) {
      if(tileset[i].tiles[j].x <= endx && (tileset[i].tiles[j].x > startx)) {
        if(tileset[i].tiles[j].y <= endy && (tileset[i].tiles[j].y > starty)) {
          tileset[i].tiles[j].tile.setDest(tileset[i].tw, tileset[i].th,tileset[i].tw*tileset[i].tiles[j].x, tileset[i].th*tileset[i].tiles[j].y);
          vec.push_back(tileset[i].tiles[j].tile);
        }
      }
    }
  }
  return vec;
}
void Tileset::move(double mx, double my) {
  for(int i=0; i<tileset.size(); i++) {
    for(int j=0; j<tileset[i].tiles.size(); j++) {
      tileset[i].tiles[j].x -= (mx/10);
      tileset[i].tiles[j].y += (my/10);
    }
  }
}
Object Tileset::move(double mx, double my, Object p) {
  double pr = .5, r = .5;
  int pxs = 0, pys = 0, xs = 0, ys = 0;
  if(mx > 0) {
    if(colCheck.isRightOf(p, lens)) {
      if(colCheck.isRightOf(p, camera)) {
        //outside of camera
        xs = mx;
      } else {
        //outside of lens but in camera
        pxs = mx*pr/2;
        xs = mx*r/2;
      }
    } else {
      //in lens
      pxs = mx;
    }
  } else if(mx < 0) {
    if(colCheck.isLeftOf(p, lens)) {
      if(colCheck.isLeftOf(p, camera)) {
        //outside of camera
        xs = mx;
      } else {
        //outside of lens but in camera
        pxs = mx*pr/2;
        xs = mx*r/2;
      }
    } else {
      //in lens
      pxs = mx;
    }
  }
  if(my > 0) {
    if(colCheck.isAbove(p, lens)) {
      if(colCheck.isAbove(p, camera)) {
        //outside of camera
        ys = my;
      } else {
        //outside of lens but in camera
        pys = my*pr/2;
        ys = my*r/2;
      }
    } else {
      //in lens
      pys = my;
    }
  } else if(my < 0) {
    if(colCheck.isBelow(p, lens)) {
      if(colCheck.isBelow(p, camera)) {
        //outside of camera
        ys = my;
      } else {
        //outside of lens but in camera
        pys = my*pr/2;
        ys = my*r/2;
      }
    } else {
      //in lens
      pys = my;
    }
  }
  p.move(pxs, pys);
  move(xs, ys);
  return p;
}
void Tileset::setCameraMargin(int wm, int hm) {
  camera.setDest(winWidth-wm-wm, winHeight-hm-hm, wm, hm);
}
void Tileset::centerCamera(int percentage) {
  int wsize = (percentage/winWidth)*winWidth;
  int hsize = (percentage/winHeight)*winHeight;
  setCameraMargin(wsize, hsize);
}
Object Tileset::getCamera() {
  return camera;
}
void Tileset::setLensMargin(int wm, int hm) {
  lens.setDest(camera.getDW()-wm-wm, camera.getDH()-hm-hm, camera.getDX()+wm, camera.getDY()+hm);
}
void Tileset::centerLens(int percentage) {
  int wsize = (percentage/camera.getDW())*camera.getDW();
  int hsize = (percentage/camera.getDH())*camera.getDH();
  setLensMargin(wsize, hsize);
}
Object Tileset::getLens() {
  return lens;
}
