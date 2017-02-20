#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  running=true;
  background.setImage("res/bkg.bmp", engine.renderScreen());
  background.setSource(0, 0, WIDTH, HEIGHT);
  background.setDest(WIDTH, HEIGHT, 0, 0);
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.setDest(TILE_SIZE, 45, 50, 50);
  engine.setColor(0x00, 0x00, 0xff);
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
  map.setWindowSize(WIDTH, HEIGHT);
  map.loadTiles("res/map.map", TILE_SIZE, TILE_SIZE);
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
  engine.pushToScreen(player);
  tiles = map.getTilesToRender();
  for(int i = 0; i<tiles.size(); i++) {
    //tiles[i].setDest(TILE_SIZE, TILE_SIZE);
    //tiles[i].setDX(50);
    //tiles[i].setDY(50);
    engine.pushToScreen(tiles[i]);
  }
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.quit)) running=false;
  if(input.checkKey(input.esc)) running=false;
}
