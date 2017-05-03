#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Collision Testing", WIDTH, HEIGHT, 0);
  e.setFrameRate(FRAMERATE);

  area.setDest(180, 180, 128, 128);
  area.setFrame(area.getDest());
  area.setColor(255, 0, 0);

  block.setDest(0, 0, 64, 64);
  block.setFrame(block.getDest());
  block.setColor(0, 0, 255);
  u=d=l=r=false;
  loop();
}

Game::~Game() {}

void Game::loop() {
  while(e.getRunning()) {
    input();
    update();
    draw();
    e.loop();
  }
}

void Game::draw() {
 e.draw(area);
 e.draw(block);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.a) && !l) {l = true;}
  if(!i.checkKey(i.a) && l) {l = false;}
  if(i.checkKey(i.d) && !r) {r = true;}
  if(!i.checkKey(i.d) && r) {r = false;}
  if(i.checkKey(i.w) && !u) {u = true;}
  if(!i.checkKey(i.w) && u) {u = false;}
  if(i.checkKey(i.s) && !d) {d = true;}
  if(!i.checkKey(i.s) && d) {d = false;}
  if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
}

void Game::update() {
  if(l) {block.setDestX(block.getDestX() - SPEED);}
  if(r) {block.setDestX(block.getDestX() + SPEED);}
  if(u) {block.setDestY(block.getDestY() - SPEED);}
  if(d) {block.setDestY(block.getDestY() + SPEED);}

  if(c.overlaps(area, block)){ block.setColor(0, 255, 255); }
  if(!c.overlaps(area, block)){ block.setColor(0, 0, 255); }
  if(c.contains(area, block)){ block.setColor(255, 0, 255); }
}
