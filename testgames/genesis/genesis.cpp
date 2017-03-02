#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  engine.bypassSplash(4231998);
  running=true;
  vector<Tile> tmp1, tmp2;
  tmp1 = map.loadMaps("wall", "res/avery.wall", "res/wall.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 7);
  tmp2 = map.loadMaps("blocks", "res/avery.map", "res/blocks.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 22);
  map.setPassable(3, 4, 2);
  map.setPassable(8, 10, 2);
  map.setPassable(13, 2);
  map.setPassable(15, 2);
  map.setPassable(17, 2);
  map.setPassable(19, 2);
  map.setPassable(21, 2);
  engine.setBackground("res/bkg.bmp");
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.center(WIDTH, HEIGHT);
  engine.setColor(0x9f, 0x9f, 0x9f);
  map.setWindowSize(WIDTH, HEIGHT);
  map.centerCamera(50);
  map.centerLens(50);
  engine.preLoop();
  input.reset();
  map.setSolid(1);
  map.setAng(45);
  speed = 5;
  start();
}
Genesis::~Genesis() {
  engine.deconstruct();
}
void Genesis::start() {
  while(running) {
    checkInput();
    engine.preLoop();
    draw();
    engine.endLoop();
  }
}
void Genesis::draw() {
  engine.pushToScreen(background);
  tiles = map.getTilesToRender();
  for(int i = 0; i<tiles.size(); i++) {engine.pushToScreen(tiles[i]);}// player=colCheck.calibrate(player, tiles[i], 0);}
  engine.pushToScreen(player);
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.right)) {
    player = map.move(speed, 0, player);
  }
  if(input.checkKey(input.left)) {
    player = map.move(-speed, 0, player);
  }
  if(input.checkKey(input.up)) {
    player = map.move(0, speed, player);
  }
  if(input.checkKey(input.down)) {
    player = map.move(0, -speed, player);
  }
  if(input.checkKey(input.quit)) { running=false; }
  if(input.checkKey(input.esc)) { running=false; }
}
