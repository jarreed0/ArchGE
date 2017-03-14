#include "level.h"

Level::Level() {

}
Level::~Level() {}

void Level::createLevel(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  createLevel(filename, 1, name, img, ren, width, height, r, count);
}
void Level::createLevel(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  createLevel(filename, 1, name, img, ren, width, height, r, rcount, count);
}
void Level::createLevel(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  createLevel(filename, startid, name, img, ren, width, height, r, count, count);
}
void Level::createLevel(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  setMap(filename);
  setTileset(startid, name, img, ren, width, height, r, rcount, count);
}

Tileset Level::setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  setTileset(1, name, img, ren, width, height, r, count);
  return tileset;
}
Tileset Level::setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  setTileset(1, name, img, ren, width, height, r, rcount, count);
  return tileset;
}
Tileset Level::setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  setTileset(startid, name, img, ren, width, height, r, count, count);
  return tileset;
}
Tileset Level::setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  tileset.create(startid, name, img, ren, width, r, rcount, count);
  return tileset;
}
