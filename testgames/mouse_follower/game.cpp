#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Mouse Follower", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);
  running = true;

  o.setImage("res/object.png", e.getRenderer());
  o.setFrame(0, 0, 16, 16);
  o.setSpeed(3);
  o.setDest(100, 100, 16, 16);

  o2=o;

  loop();
}
Game::~Game() {}

void Game::loop() {
  while(running) {
    e.loopStart();
    bool frame = true;
    while(frame) {
      e.update();
      input();
      update();
      draw();
      if(!e.FPS()) { frame=false; }
    }
    e.render();
  }
}

void Game::draw() {
  e.draw(o);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) running = false;
  if(i.checkKey(i.mouseleft)) {cout << o.getVelX();cout << " ,";cout << o.getVelY();cout << "\n";}
}

void Game::update() {
  o2.setDest(i.getMouseX(), i.getMouseY(), 16, 16);
  if(o2.getDestX() > (WIDTH-o2.getDestW())) o2.setDestX(WIDTH-o2.getDestW());
  if(o2.getDestY() > (HEIGHT-o2.getDestH())) o2.setDestY(HEIGHT-o2.getDestH());
  if(timeToMove) { o.setVelTo(o2); o.moveDest(o.getVelX(), o.getVelY()); }

  mcount++;
  if(mcount >= vel) {
    mcount = 0;
    timeToMove = true;
  }
}
