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
  map.addTile("dirtwall", "res/wall.bmp", engine.renderScreen(), 1, TILE_SIZE);
  map.addTile("rockwall", "res/wall.bmp", engine.renderScreen(), 2, TILE_SIZE);
  map.addTile("stonewall", "res/wall.bmp", engine.renderScreen(), 3, TILE_SIZE);
  map.addTile("brickwall", "res/wall.bmp", engine.renderScreen(), 4, TILE_SIZE);
  map.addTile("woodwall", "res/wall.bmp", engine.renderScreen(), 5, TILE_SIZE);
  map.addTile("sandwall", "res/wall.bmp", engine.renderScreen(), 6, TILE_SIZE);
  map.addTile("snowwall", "res/wall.bmp", engine.renderScreen(), 7, TILE_SIZE);
  map.loadTiles("res/avery.wall", TILE_SIZE, TILE_SIZE);
  map.addTile("grass", "res/blocks.bmp", engine.renderScreen(), 1, TILE_SIZE);
  map.addTile("rock", "res/blocks.bmp", engine.renderScreen(), 2, TILE_SIZE);
  map.addTile("flower", "res/blocks.bmp", engine.renderScreen(), 3, TILE_SIZE);
  map.addTile("water", "res/blocks.bmp", engine.renderScreen(), 4, TILE_SIZE);
  map.addTile("dirt", "res/blocks.bmp", engine.renderScreen(), 5, TILE_SIZE);
  map.addTile("copper", "res/blocks.bmp", engine.renderScreen(), 6, TILE_SIZE);
  map.addTile("iron", "res/blocks.bmp", engine.renderScreen(), 7, TILE_SIZE);
  map.addTile("wood", "res/blocks.bmp", engine.renderScreen(), 8, TILE_SIZE);
  map.addTile("torch", "res/blocks.bmp", engine.renderScreen(), 9, TILE_SIZE);
  map.addTile("table", "res/blocks.bmp", engine.renderScreen(), 10, TILE_SIZE);
  map.addTile("stone", "res/blocks.bmp", engine.renderScreen(), 11, TILE_SIZE);
  map.addTile("brick", "res/blocks.bmp", engine.renderScreen(), 12, TILE_SIZE);
  map.addTile("leaf", "res/blocks.bmp", engine.renderScreen(), 13, TILE_SIZE);
  map.addTile("cobble", "res/blocks.bmp", engine.renderScreen(), 14, TILE_SIZE);
  map.addTile("chamber", "res/blocks.bmp", engine.renderScreen(), 16, TILE_SIZE);
  map.addTile("post", "res/blocks.bmp", engine.renderScreen(), 15, TILE_SIZE);
  map.addTile("workbench", "res/blocks.bmp", engine.renderScreen(), 17, TILE_SIZE);
  map.addTile("plank", "res/blocks.bmp", engine.renderScreen(), 18, TILE_SIZE);
  map.addTile("chickenegg", "res/blocks.bmp", engine.renderScreen(), 19, TILE_SIZE);
  map.addTile("sand", "res/blocks.bmp", engine.renderScreen(), 20, TILE_SIZE);
  map.addTile("cactus", "res/blocks.bmp", engine.renderScreen(), 21, TILE_SIZE);
  map.addTile("snow", "res/blocks.bmp", engine.renderScreen(), 22, TILE_SIZE);
  map.loadTiles("res/avery.map", TILE_SIZE, TILE_SIZE);
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
