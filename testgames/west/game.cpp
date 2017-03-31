#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.exitOnEscape(true);
  e.setGLMode(true);
  e.init("West", WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  e.setColor(0x00, 0x08, 0x99);
  loop();
}

Game::~Game() {
}

void Game::loop() {
  while(e.getRunning()) {
    input();
    update();
    draw();
    e.loop();
  }
}

void Game::draw() {
}

void Game::input() {

}

void Game::update() {

}
