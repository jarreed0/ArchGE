#include "force.h"

Force::Force() : level(TOTAL_TILES) {
  e.bypassSplash(4231998);
  e.init(TITLE, WIDTH, HEIGHT, 0);
  i.logPress();
  loadLevels();
  level.setWindowSize(WIDTH, HEIGHT);
  e.setColor(0x10, 0x01, 0x88);
  running = true;
  player.setSource(0, 0, 24, 32);
  player.setImage("res/player.bmp", e.renderScreen());
  player.setDest(24, 32);
  player.center(WIDTH, HEIGHT);
  pRight = player.createNewFrameSet(2, 1, 1, 24, 32);
  pLeft  = player.createNewFrameSet(2, 2, 1, 24, 32);
  player.setCurFrameSet(pLeft);
  i.logPress();
  i.reset();
  falling = false;
  loop();
}

Force::~Force() {
  e.deconstruct();
}

void Force::loop() {
  while(running) {
    input();
    if(falling) {
      level.move(0, -SPEED);
    }
    e.preLoop();
    draw();
    e.endLoop();
  }
}

void Force::draw() {
  disp = level.getTilesToRender();
  bool colliding = false;
  for(int i = 0; i < disp.size(); i++) {
    e.pushToScreen(disp[i]);
    if(col.isTouching(player, disp[i])) {
      colliding = true;
    }
    if(moveRight) {
      Entity p = player;
      p.move(SPEED, 0);
      if(col.isLeftOf(p, disp[i]) && !col.isAbove(p, disp[i])) {
        moveRight=false;
      }
    }
    if(moveLeft) {
      Entity p = player;
      p.move(-SPEED, 0);
      if(col.isRightOf(p, disp[i]) && !col.isAbove(p, disp[i])) {
        moveLeft=false;
      }
    }
  }
  falling = false;
  if(!colliding) {
    falling=true;
  }
  if(moveRight) level.move(SPEED, 0);
  if(moveLeft) level.move(-SPEED, 0);
  e.pushToScreen(player);
}

void Force::input() {
  i.logPress();
  i.reset();
  moveLeft=moveRight=false;
  if(running) {
    if(i.checkKey(i.left)) {
      moveLeft = true;
      player.setCurFrameSet(pLeft);
    }
    if(i.checkKey(i.right)) {
      moveRight = true;
      player.setCurFrameSet(pRight);
    }
    if(i.checkKey(i.up)) { level.move(0, SPEED); }
    if(i.checkKey(i.down)) { level.move(0, -SPEED); }
    if(i.checkKey(i.quit)) { running = false; cout << "quit\n"; }
    if(i.checkKey(i.esc)) { running = false; cout << "esc\n"; }
  }
}

void Force::loadLevels() {
  disp.clear();
  level.loadMaps("tile", "res/1.level", "res/tiles.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES); //
}
