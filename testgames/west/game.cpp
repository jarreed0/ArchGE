#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.setGLMode(true);
  e.init("West", WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  bkg.setDest(0, 0, WIDTH, HEIGHT);
  bkg.setFrame(bkg.getDest());
  bkg.setColor(bkg.red);
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
 e.draw(bkg);
}

void Game::input() {
 i.logPress();
 if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
}

void Game::update() {

}
