#include "stage.h"

Stage::Stage() {

}
Stage::~Stage() {}

void Stage::createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  createStage(filename, 1, name, img, ren, width, height, r, count);
}
void Stage::createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  createStage(filename, 1, name, img, ren, width, height, r, rcount, count);
}
void Stage::createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  createStage(filename, startid, name, img, ren, width, height, r, count, count);
}
void Stage::createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  setMap(filename);
  setTileset(startid, name, img, ren, width, height, r, rcount, count);
}

Tileset Stage::setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  setTileset(1, name, img, ren, width, height, r, count);
  return tileset;
}
Tileset Stage::setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  setTileset(1, name, img, ren, width, height, r, rcount, count);
  return tileset;
}
Tileset Stage::setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count) {
  setTileset(startid, name, img, ren, width, height, r, count, count);
  return tileset;
}
Tileset Stage::setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count) {
  tileset.create(startid, name, img, ren, width, height, r, rcount, count);
  return tileset;
}
