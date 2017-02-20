#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  running=true;
  bkg.setImage("res/bkg.bmp", engine.renderScreen());
  bkg.setSource(0, 0, WIDTH, HEIGHT);
  bkg.setDest(WIDTH, HEIGHT);
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.setDest(TILE_SIZE, 45);
}
Genesis::~Genesis() {
  engine.deconstruct();
}
void Genesis::start() {
  engine.setColor(0x00, 0x00, 0xff);
  while(running) {
    checkInput();
    engine.preLoop();
    draw();
    engine.endLoop();
  }
}
void Genesis::draw() {
  engine.pushToScreen(bkg);
  engine.pushToScreen(player);
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.quit)) running=false;
  if(input.checkKey(input.esc)) running=false;
}
