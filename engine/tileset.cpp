#include "tileset.h"

Tileset::Tileset() {
}
Tileset::~Tileset() {}

vector<Tile> Tileset::create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  create(1, name, img, ren, width, height, r, count);
  return tiles;
}
vector<Tile> Tileset::create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  create(1, name, img, ren, width, height, r, rcount, count);
  return tiles;
}
vector<Tile> Tileset::create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  create(startid, name, img, ren, width, height, r, count, count);
  return tiles;
}
vector<Tile> Tileset::create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  int tag = 0;
  for(int i=0; i<r; i++) {
    for(int j=0; j<rcount; j++) {
      addTile(name, img, ren, tag+startid, i+1, j+1, width, height);
      tag++;
      if(tag>count) { break; }
    }
    if(tag>count) break;
  }
  return tiles;
}

void Tileset::addTile(Tile t) {
  tiles.push_back(t);
}
Tile Tileset::addTile(string name, string file, SDL_Renderer* ren, int value, int c, int r, int width, int height) {
  Tile tmp;
  tmp.setName(name);
  tmp.setFrame(((r-1)*width), ((c-1)*height), width, height);
  tmp.setDestSize(width, height);
  tmp.setPosSize(width, height);
  tmp.setImage(file, ren);
  tmp.setValue(value);
  addTile(tmp);
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

void Tileset::setAngle(int ang) {
  for(int i=0; i<tiles.size(); i++) {
    tiles[i].setAngle(ang);
  }
}

void Tileset::setSolid() {
  setSolid(1, tiles.size()+1);
}
void Tileset::setSolid(int t) {
  tiles[t].setSolid();
  cout << tiles[t].getName() << " (id: " << t << ") is now solid" << endl;
}
void Tileset::setSolid(int s, int e) {
  for(int i=s; i<(e+1); i++) {
    setSolid(i);
  }
}

void Tileset::setPassable() {
  setPassable(1, tiles.size()+1);
}
void Tileset::setPassable(int t) {
  tiles[t].setPassable();
  cout << tiles[t].getName() << " (id: " << t << ") is now passable" << endl;
}
void Tileset::setPassable(int s, int e) {
  for(int i=s; i<(e+1); i++) {
    setPassable(i);
  }
}

void Tileset::setName(string n, int id) {
  tiles[id].setName(n);
}
