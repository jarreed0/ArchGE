#include "level.h"

Level::Level() {
  screen.setPos(0, 0, 1000, 1000);
  precise = false;
  mainEntitySet = false;
  activeCam = activeLens = 0;
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
  if(mainEntitySet) {
    if(activeCam && col.outOfBoundsOf(entities[mainEntityID], camera)) {
      cout << "out of camera" << endl;
      if(activeCam) cout << "active" << endl;
      if(col.outOfBoundsOf(entities[mainEntityID], camera)) cout << "out" << endl;
      setCoord(getX()+mx, getY()-my);
    } else {
      entities[mainEntityID].setPosCoord(entities[mainEntityID].getPosX()+mx, entities[mainEntityID].getPosY()-my);
      vector<Tile> tilesToCol = getTilesToRender();
      for(int i=0; i<tilesToCol.size(); i++) {
        if(tilesToCol[i].isSolid()) {
          if(col.isTouching(entities[mainEntityID], tilesToCol[i])) {
            entities[mainEntityID].setPosCoord(entities[mainEntityID].getPosX()-mx, entities[mainEntityID].getPosY()+my);
            setCoord(getX()+mx, getY()-my);
          }
        }
      }
    }
  } else {
    setCoord(getX()+mx, getY()-my);
  }
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

vector<Object> Level::getObjectsToRender() {
  vector<Object> objectsToRender;
  for(int i=0; i<objects.size(); i++) {
    if(col.isTouching(screen, objects[i])) {
      objects[i].setDisplayable(true);
      objects[i].setDestCoord(objects[i].getPosX()-screen.getPosX(), objects[i].getPosY()-screen.getPosY());
      objectsToRender.push_back(objects[i]);
    } else {
      objects[i].setDisplayable(false);
    }
  }
  return objectsToRender;
}

vector<Entity> Level::getEntitiesToRender() {
  vector<Entity> entitiesToRender;
  for(int i=0; i<entities.size(); i++) {
    if(col.isTouching(screen, entities[i])) {
      entities[i].setDisplayable(true);
      entities[i].setDestCoord(entities[i].getPosX()-screen.getPosX(), entities[i].getPosY()-screen.getPosY());
      entitiesToRender.push_back(entities[i]);
    } else {
      entities[i].setDisplayable(false);
    }
  }
  return entitiesToRender;
}

void Level::addObject(Object o) {
  objects.push_back(o);
}
void Level::addObject(vector<Object> o) {
  objects.insert(objects.end(), o.begin(), o.end());
}

int Level::addEntity(Entity e) {
  entities.push_back(e);
  return entities.size()-1;
}
void Level::addEntity(vector<Entity> e) {
  entities.insert(entities.end(), e.begin(), e.end());
}

int Level::setMainEntity(Entity e) {
  return setMainEntity(addEntity(e));
}
int Level::setMainEntity(int m) {
  mainEntityID = m;
  mainEntitySet = true;
  return m;
}

void Level::setCameraMargin(int wm, int hm) {
  camera.setPos(wm, hm, screen.getPosW()-wm-wm, screen.getPosH()-hm-hm);
  activeCam = true;
}
void Level::centerCamera(int percentage) {
  int wsize = ((percentage/2)*screen.getPosW())/100;
  int hsize = ((percentage/2)*screen.getPosH())/100;
  setCameraMargin(wsize, hsize);
}
Object Level::getCamera() {
  return camera;
}
void Level::setLensMargin(int wm, int hm) {
  lens.setPos(camera.getPosX()+wm, camera.getPosY()+hm, camera.getPosW()-wm-wm, camera.getPosH()-hm-hm);
  activeLens = true;
}
void Level::centerLens(int percentage) {
  int wsize = ((percentage/2)*camera.getPosW())/100;
  int hsize = ((percentage/2)*camera.getPosH())/100;
  setLensMargin(wsize, hsize);
}
Object Level::getLens() {
  return lens;
}
