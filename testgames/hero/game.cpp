#include "game.h"

Game::Game() : level(12) {
  input();
  e.bypassSplash(4231998);
  e.init(TITLE, WIDTH, HEIGHT, 0);
  level.setWindowSize(WIDTH, HEIGHT);
  level.loadMaps("wall", "res/level.wall", "res/wall.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, 2, 8);
  level.loadMaps("tile", "res/level.tile", "res/wall.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 8);
  e.setColor(0x00, 0x8f, 0x33);
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
    if(i.checkKey(i.quit)) running = false;
    if(i.checkKey(i.esc)) running = false;
  }
}
