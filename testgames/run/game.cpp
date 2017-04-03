#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("RUN!", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);

  o.setImage("res/object.png", e.getRenderer());
  o.setFrame(0, 0, 16, 16);
  o.setSpeed(3);
  o.setDest(100,100,16,16);
  o.center(WIDTH, HEIGHT);

  u=d=l=r=0;

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
  e.draw(o);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) e.setRunning(false);
  u=d=l=r=0;
  if(i.checkKey(i.w) && !u) u=true;
  if(i.checkKey(i.s) && !d) d=true;
  if(i.checkKey(i.a) && !l) l=true;
  if(i.checkKey(i.d) && !r) r=true;
}

void Game::update() {
  //o.lookAt(i);
  if(l) o.rotateAngle(-ROTATE);
  if(r) o.rotateAngle(ROTATE);
  int dx = cos(get_degrees(o.getAngle()))*SPEED;
  int dy = sin(get_degrees(o.getAngle()))*SPEED;
  if(u) o.moveDest(dx,dy);
  if(d) o.moveDest(-dx,-dy);
}

double Game::get_degrees(double input) {
    const double halfC = M_PI / 180;
    return input * halfC;
}

