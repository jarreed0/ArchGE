#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  running=true;
  background.setImage("res/bkg.bmp", engine.renderScreen());
  background.setSource(0, 0, WIDTH, HEIGHT);
  background.setDest(WIDTH, HEIGHT, 0, 0);
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.setDest(TILE_SIZE, 45,(WIDTH/2)-(TILE_SIZE/2), (HEIGHT/2)-(45/2));
  engine.setColor(0x00, 0x00, 0xff);
  map.setWindowSize(WIDTH, HEIGHT);
  map.setCameraMargin(75, 75, WIDTH, HEIGHT);
  map.centerLens(40);
  vector<Tile> tmp;
  tmp = map.loadMaps("wall", "res/avery.wall", "res/wall.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 7);
  tmp = map.loadMaps("blocks", "res/avery.map", "res/blocks.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 22);
  speed = 5;
  int tick = 0;
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
  for(int i = 0; i<tiles.size(); i++) {
    engine.pushToScreen(tiles[i]);
  }
  engine.pushToScreen(player);
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.right)) {
    map.move(speed, 0);
  }
  if(input.checkKey(input.left)) {
    map.move(-speed, 0);
  }
  if(input.checkKey(input.up)) {
    map.move(0, speed);
  }
  if(input.checkKey(input.down)) {
    map.move(0, -speed);
  }
  if(input.checkKey(input.quit)) running=false;
  if(input.checkKey(input.esc)) running=false;
}
