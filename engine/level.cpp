#include "level.h"

Level::Level() {
  screen.setPos(0, 0, 1000, 1000);
  precise = false;
}
Level::~Level() {}

void Level::create() {
  setScale(stage.getTileset().getTileset()[stage.getMap().getMap()[0][0]].getPosW(), stage.getTileset().getTileset()[stage.getMap().getMap()[0][0]].getPosH());
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
  setCoord(stage.getMap().getX(), stage.getMap().getY());
  if(precise) setCoord(stage.getMap().getX()*tilewidth, stage.getMap().getY()*tileheight);
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
