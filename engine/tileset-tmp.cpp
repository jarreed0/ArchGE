#include "tileset-tmp.h"
#include "engine.h"

Tilesettmp::Tilesettmp(int amount) {
  tiles = new Tile[amount+1];
  layersize = xsize = ysize = x = y = 0;
  set=false;
  activeCam = activeLens = 0;
}
Tilesettmp::~Tilesettmp() {
  delete[]tiles;
}
void Tilesettmp::setAng(int ang) {
  angle = ang;
  pushAng();
}
void Tilesettmp::pushAng() {
  for(int i = 0; i<tileset.size(); i++) {
    //for(int j = 0; i<tileset[i].tiles.size(); j++) {
      //tileset[i].tiles[j].tile.setAng(angle);
    //}
  }
}
void Tilesettmp::setCoord(double ix, double iy) {
  move(ix-x, iy-y);
}
void Tilesettmp::setCoord(double ix, double iy, double mx, double my) {
  x = ix;
  y = iy;
  calcPos(mx, my);
  set=true;
}
void Tilesettmp::setWindowSize(int ww, int wh) {
  winWidth = ww;
  winHeight = wh;
}
double Tilesettmp::getX() {
  return x;
}
double Tilesettmp::getY() {
  return y;
}
vector<Tile> Tilesettmp::loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp;
  tmp = genMap(name, map, img, ren, width, height, r, count);
  return tmp;
}
vector<Tile> Tilesettmp::loadMaps(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  vector<Tile> tmp;
  tmp = genMap(name, map, img, ren, width, height, r, rcount, count);
  return tmp;
}
vector<Tile> Tilesettmp::genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp;
  for(int i=0; i<(count-1); i++) {
    tmp.push_back(addTile(name, img, ren, i, r, i, width, height));
  }
  loadTiles(map, width, height);
  return tmp;
}
vector<Tile> Tilesettmp::genMap(string name, string map, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  vector<Tile> tmp;
  int tag = 1;
  for(int i=0; i<r; i++) {
    for(int j=0; j<rcount; j++) {
      tmp.push_back(addTile(name, img, ren, tag, i+1, j+1, width, height));
      //cout << "loaded Tile " << tag << " at (" << j << ", " << i << ")\n";
      tag++;
      if(tag>count) { break; }
    }
    if(tag>count) break;
  }
  /*for(int i=0; i<tmp.size(); i++) {
    cout << "Tile " << tmp[i].getValue() << " at (" << tmp[i].getSX()/width << ", " << tmp[i].getSY()/height << ")\n";
  }*/
  loadTiles(map, width, height);
  return tmp;
}
void Tilesettmp::loadTiles(string filename, int iw, int ih) {
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
    if(!set) {
      setCoord(-cur.x, -cur.y);
    } else {
      setCoord(0, 0);
    }
  }
  in.close();
  tileset.push_back(cur);
  setCoord(-cur.x, -cur.y);
  move(-cur.x, -cur.y);
}
void Tilesettmp::addTile(Tile t) {
  tiles[t.getValue()] = t;
}
Tile Tilesettmp::addTile(string name, string file, SDL_Renderer* ren, int value, int c, int r, int width, int height) {
  Tile tmp;
  tmp.setName(name);
  tmp.setFrame(((r-1)*width), ((c-1)*height), width, height);
  tmp.setImage(file, ren);
  tmp.setValue(value);
  tiles[value] = tmp;
  return tmp;
}
Tile Tilesettmp::addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height) {
  Tile tmp = addTile(name, file, ren, value, 1, value, width, height);
  return tmp;
}
Tile Tilesettmp::addTile(string name, string file, SDL_Renderer* ren, int value, int size) {
  Tile tmp = addTile(name, file, ren, value, 1, value, size, size);
  return tmp;
}
vector<Tile> Tilesettmp::getTilesToRender() {
  vector <Tile> vec;
  pushAng();
  for(int i = 0; i<tileset.size(); i++) {
    int ttw = winWidth/tileset[i].tw/2+2;
    int tth = winHeight/tileset[i].tw/2+2;
    tileset[i].x = 0;
    tileset[i].y = 0;
    int startx = tileset[i].x-(ttw/2)-tileset[i].tw;
    int starty = tileset[i].y-(tth/2)-tileset[i].th;
    int enDestX = ttw+tileset[i].tw;
    int enDestY = tth+tileset[i].th;
    //cout << "SX: " << startx << ", EX: " << enDestX << "\nSY: " << starty << ", EY: " << enDestY << endl;
    for(int j = 0; j<tileset[i].tiles.size(); j++) {
      if(tileset[i].tiles[j].x <= enDestX && (tileset[i].tiles[j].x > startx)) {
        if(tileset[i].tiles[j].y <= enDestY && (tileset[i].tiles[j].y > starty)) {
          tileset[i].tiles[j].tile.setDest(tileset[i].tw, tileset[i].th,tileset[i].tw*tileset[i].tiles[j].x, tileset[i].th*tileset[i].tiles[j].y);
          vec.push_back(tileset[i].tiles[j].tile);
        }
      }
    }
  }
  return vec;
}
vector<Tile> Tilesettmp::getTilesToRender(int w, int h) {
  vector <Tile> vec;
  pushAng();
  for(int i = 0; i<tileset.size(); i++) {
    int ttw = winWidth/w/2+2;
    int tth = winHeight/w/2+2;
    tileset[i].x = 0;
    tileset[i].y = 0;
    int startx = tileset[i].x-(ttw/2)-w;
    int starty = tileset[i].y-(tth/2)-h;
    int enDestX = ttw+w;
    int enDestY = tth+h;
    //cout << "SX: " << startx << ", EX: " << enDestX << "\nSY: " << starty << ", EY: " << enDestY << endl;
    for(int j = 0; j<tileset[i].tiles.size(); j++) {
      if(tileset[i].tiles[j].x <= enDestX*2 && (tileset[i].tiles[j].x > startx*2)) {
        if(tileset[i].tiles[j].y <= enDestY && (tileset[i].tiles[j].y > starty)) {
          tileset[i].tiles[j].tile.setDest(w, h, w*tileset[i].tiles[j].x, h*tileset[i].tiles[j].y);
          vec.push_back(tileset[i].tiles[j].tile);
        }
      }
    }
  }
  return vec;
}
void Tilesettmp::move(double mx, double my) {
  setCoord(x-=(mx/10), y-=(my/10), mx, my);
}
void Tilesettmp::calcPos(double mx, double my) {
  for(int i=0; i<tileset.size(); i++) {
    calcSetPos(i, mx, my);
  }
}
void Tilesettmp::calcSetPos(int i, double mx, double my) {
  tileset[i].x -= (mx/10);
  tileset[i].y -= (my/10);
  calcTilesPos(i, mx, my);
}
void Tilesettmp::calcTilesPos(int i, double mx, double my) {
  for(int j=0; j<tileset[i].tiles.size(); j++) {
    tileset[i].tiles[j].x -= (mx/10);
    tileset[i].tiles[j].y += (my/10);
  }
}
Object Tilesettmp::move(double mx, double my, Object p) {
  double pr = 1, r = 1;
  int pxs = 0, pys = 0, xs = 0, ys = 0;
  if(mx > 0) {
    if(colCheck.outOfBoundsOf(p, camera) && activeCam) {
      if(colCheck.isRightOf(p, camera) && activeCam) {
        xs = mx;
      } else {
        pxs = mx;
      }
    } else {
      if(colCheck.outOfBoundsOf(p, lens) && activeLens) {
        pxs = mx*pr;
        xs = mx*r;
      } else {
        pxs = mx;
      }
    }
  } else if(mx < 0) {
    if(colCheck.outOfBoundsOf(p, camera) && activeCam) {
      if(colCheck.isLeftOf(p, camera)) {
        xs = mx;
      } else {
        pxs = mx;
      }
    } else {
      if(colCheck.outOfBoundsOf(p, lens) && activeLens) {
        pxs = mx*pr;
        xs = mx*r;
      } else {
        pxs = mx;
      }
    }
  }
  if(my > 0) {
    if(colCheck.outOfBoundsOf(p, camera) && activeCam) {
      if(colCheck.isAbove(p, camera)) {
        ys = my;
      } else {
        pys = my;
      }
    } else {
      if(colCheck.outOfBoundsOf(p, lens) && activeLens) {
        pys = my*pr;
        ys = my*r;
      } else {
        pys = my;
      }
    }
  } else if(my < 0) {
    if(colCheck.outOfBoundsOf(p, camera) && activeCam) {
      if(colCheck.isBelow(p, camera)) {
        ys = my;
      } else {
        pys = my;
      }
    } else {
      if(colCheck.outOfBoundsOf(p, lens) && activeLens) {
        pys = my*pr;
        ys = my*r;
      } else {
        pys = my;
      }
    }
  }
  if(!activeLens && !activeLens) {
    pxs = pys = 0;
    xs = mx;
    ys = my;
  }
  p.move(pxs, pys);
  move(xs, ys);
  return p;
}
void Tilesettmp::setCameraMargin(int wm, int hm) {
  camera.setDest(winWidth-wm-wm, winHeight-hm-hm, wm, hm);
  activeCam = true;
}
void Tilesettmp::centerCamera(int percentage) {
  int wsize = ((percentage/2)*winWidth)/100;
  int hsize = ((percentage/2)*winHeight)/100;
  setCameraMargin(wsize, hsize);
}
Object Tilesettmp::getCamera() {
  return camera;
}
void Tilesettmp::setLensMargin(int wm, int hm) {
  lens.setDest(camera.getDestW()-wm-wm, camera.getDestH()-hm-hm, camera.getDestX()+wm, camera.getDestY()+hm);
  activeLens = true;
}
void Tilesettmp::centerLens(int percentage) {
  int wsize = ((percentage/2)*camera.getDestW())/100;
  int hsize = ((percentage/2)*camera.getDestH())/100;
  setLensMargin(wsize, hsize);
}
Object Tilesettmp::getLens() {
  return lens;
}vector<Tile> Tilesettmp::renderTiles(Engine e) {
  vector<Tile> rt = getTilesToRender();
  for(int i = 0; i < rt.size(); i++) {
    e.draw(rt[i]);
  }
  return rt;
}
vector<Tile> Tilesettmp::renderTiles(int w, int h, Engine e) {
  vector<Tile> rt = getTilesToRender(w, h);
  for(int i = 0; i < rt.size(); i++) {
    e.draw(rt[i]);
  }
  return rt;
}
