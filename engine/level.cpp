#include "level.h"

Level::Level() {
  screen.setPos(0, 0, 1000, 1000);
}
Level::~Level() {}

void Level::create() {
  vector<Tile> row;
  tilewidth=stage.getTileset().getTileset()[stage.getMap().getMap()[0][0]].getPosW();
  tileheight=stage.getTileset().getTileset()[stage.getMap().getMap()[0][0]].getPosH();
  for(int r=0; r<stage.getMap().getMap().size(); r++) {
    row.empty(); row.clear();
    for(int c=0; c<stage.getMap().getMap()[r].size(); c++) {
      if(stage.getMap().getMap()[r][c] != 0) {
        row.push_back(stage.getTileset().getTileset()[stage.getMap().getMap()[r][c]]);
        row[row.size()-1].setPosCoord(r*row[c].getPosW(), c*row[c].getPosH());
        row[row.size()].setCoord(r, c);
      }
    }
    tiles.push_back(row);
  }
}

void Level::setScale(int w, int h) {
  tilewidth = w;
  tileheight = h;
  for(int r=0; r<tiles.size(); r++) {
    for(int c=0; c<tiles[r].size(); c++) {
      tiles[r][c].setDestSize(w, h);
      tiles[r][c].setPos(r*tiles[r][c].getPosW(), c*tiles[r][c].getPosH(), w, h);
      tiles[r][c].setPosCoord(r*tiles[r][c].getPosW(), c*tiles[r][c].getPosH());
      tiles[r][c].setCoord(r, c);
    }
  }
}

void Level::move(int mx, int my) {
  setCoord(getX()+mx, getY()+my);
}

vector<Tile> Level::getTilesToRender() {
  vector<Tile> tilesToRender;
  for(int r=0; r<tiles.size(); r++) {
    for(int c=0; c<tiles[r].size(); c++) {
      //tiles[r][c].setCoord(x, y);
      if(col.isTouching(screen, tiles[r][c])) {
        tiles[r][c].setDisplayable(true);
        //tiles[r][c].setDestCoord(, y);
        tiles[r][c].setDestCoord(tiles[r][c].getPosX()-screen.getPosX(), tiles[r][c].getPosY()-screen.getPosY());
        tilesToRender.push_back(tiles[r][c]);
      } else {
        tiles[r][c].setDisplayable(false);
      }
    }
  }
  return tilesToRender;
}
