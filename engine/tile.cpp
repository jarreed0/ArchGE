#include "tile.h"

Tile::Tile() {}
Tile::~Tile() {}
void Tile::setValue(int v) {
  value = v;
}
int Tile::getValue() {
  return value;
}
void Tile::setName(string s) {
  name = s;
}
string Tile::getName() {
  return name;
}
