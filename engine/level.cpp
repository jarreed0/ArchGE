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
        Tile tmp = stage.getTileset().getTileset()[stage.getMap().getMap()[r][c]];
        tmp.setValue(stage.getMap().getMap()[r][c]);
        tmp.setFrame(stage.getTileset().getFrame(tmp.getValue()));
        tmp.setPosCoord(c*tmp.getPosW(), r*tmp.getPosH());
        tmp.setCoord(c, r);
        row.push_back(tmp);
      }
    }
    tiles.push_back(row);
  }
}

void Level::setScale(int w, int h) {
  tilewidth = w;
  tileheight = h;
  tiles.empty(); tiles.clear();
  vector<Tile> row;
  for(int r=0; r<stage.getMap().getMap().size(); r++) {
    row.empty(); row.clear();
    for(int c=0; c<stage.getMap().getMap()[r].size(); c++) {
      if(stage.getMap().getMap()[r][c] != 0) {
        Tile tmp = stage.getTileset().getTileset()[stage.getMap().getMap()[r][c]];
        tmp.setValue(stage.getMap().getMap()[r][c]);
        tmp.setFrame(stage.getTileset().getFrame(tmp.getValue()));
        tmp.setPos(c*w, r*h, w, h);
        tmp.setDestSize(w, h);
        tmp.setCoord(c, r);
        row.push_back(tmp);
      }
    }
    tiles.push_back(row);
  }
}

void Level::move(int mx, int my) {
  setCoord(getX()+mx, getY()+my);
}

vector<Tile> Level::getTilesToRender() {
  vector<Tile> tilesToRender;
  for(int r=0; r<tiles.size(); r++) {
    for(int c=0; c<tiles[r].size(); c++) {
      if(col.isTouching(screen, tiles[r][c])) {
        tiles[r][c].setDisplayable(true);
        tiles[r][c].setDestCoord(tiles[r][c].getPosX()-screen.getPosX(), tiles[r][c].getPosY()-screen.getPosY());
        tilesToRender.push_back(tiles[r][c]);
      } else {
        tiles[r][c].setDisplayable(false);
      }
    }
  }
  return tilesToRender;
}
