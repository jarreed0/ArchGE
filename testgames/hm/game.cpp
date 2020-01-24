#include "game.h"

Game::Game() {
 NAME = "HM";
 e.debugMode(true);
 e.init(NAME, WIDTH, HEIGHT, 0);
 loop();
}
Game::~Game() {}
void Game::loop() {
  while(e.getRunning()) {
    e.loopStart();
    e.update();
    //input();
    //update();
    //draw();
    e.render();
  }
}

