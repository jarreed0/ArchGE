#include "tileset.h"

Tileset::Tileset() {

}
Tileset::~Tileset() {}

vector<Tile> Tileset::create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp = create(1, name, img, ren, width, height, r, count);
  return tmp;
}
vector<Tile> Tileset::create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  vector<Tile> tmp  = create(1, name, img, ren, width, height, r, rcount, count);
  return tmp;
}
vector<Tile> Tileset::create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  vector<Tile> tmp = create(startid, name, img, ren, width, height, r, count, count);
  return tmp;
}
vector<Tile> Tileset::create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  vector<Tile> tmp;
  int tag = 0;
  for(int i=0; i<r; i++) {
    for(int j=0; j<rcount; j++) {
      tmp.push_back(addTile(name, img, ren, tag+startid, i+1, j+1, width, height));
      tag++;
      if(tag>count) { break; }
    }
    if(tag>count) break;
  }
  return tmp;
}

void Tileset::addTile(Tile t) {
  tiles.push_back(t);
}
Tile Tileset::addTile(string name, string file, SDL_Renderer* ren, int value, int c, int r, int width, int height) {
  Tile tmp;
  setName(name, value);
  tmp.setFrame(((r-1)*width), ((c-1)*height), width, height);
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
  tiles[t-1].setSolid();
}
void Tileset::setSolid(int s, int e) {
  for(int i=s; i<e; i++) {
    setPassable(i);
  }
}

void Tileset::setPassable() {
  setPassable(1, tiles.size()+1);
}
void Tileset::setPassable(int t) {
  tiles[t-1].setPassable();
}
void Tileset::setPassable(int s, int e) {
  for(int i=s; i<e; i++) {
    setPassable(i);
  }
}

void Tileset::setName(string n, int id) {
  tiles[id-1].setName(n);
}
