#include "game.h"

Game::Game() : level(12) {
  i.logPress();
  e.bypassSplash(4231998);
  e.init(TITLE, WIDTH, HEIGHT, 0);
  level.setWindowSize(WIDTH, HEIGHT);
  loadLevel();
  e.setColor(0xff, 0x8f, 0x33);
  running = true;
  loop();
}

Game::~Game() {
  e.deconstruct();
}

void Game::loop() {
  while(running) {
    input();
    e.preLoop();
    draw();
    e.endLoop();
  }
}

void Game::draw() {
  disp = level.getTilesToRender();
  for(int i = 0; i < disp.size(); i++) e.pushToScreen(disp[i]);
}

void Game::input() {
  i.logPress();
  if(running) {
    if(i.checkKey(i.left)) level.move(-SPEED, 0);
    if(i.checkKey(i.right)) level.move(SPEED, 0);
    if(i.checkKey(i.up)) level.move(0, SPEED);
    if(i.checkKey(i.down)) level.move(0, -SPEED);
    if(i.checkKey(i.quit)) running = false;
    if(i.checkKey(i.esc)) running = false;
    if(i.checkKey(i.r)) {
      loadLevel();
    }
  }
}

void Game::loadLevel() {
  level.loadMaps("tile", "res/level.tileset", "res/wall.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, 2, 6, 12);
}
