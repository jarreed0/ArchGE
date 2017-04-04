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
  pu=pd=0;

  vel=0;

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
  if(u) pu=1;
  if(d) pd=1;
  u=d=l=r=0;
  if(i.checkKey(i.w) && !u) u=true;
  if(i.checkKey(i.s) && !d) d=true;
  if(i.checkKey(i.a) && !l) l=true;
  if(i.checkKey(i.d) && !r) r=true;
}

void Game::update() {
  //o.lookAt(i);
  if(l) o.rotateAngle(-ROTATE-(vel/2));
  if(r) o.rotateAngle(ROTATE+(vel/2));
  cout << vel << endl;
  if(!u && !d) {
    vel-=(vel*.0);
    if(vel<0) { vel=0;
    pu=pd=0;}
  } else {
    if(vel==0) vel=1;
    vel+=(vel*.05);
  }
  if(vel>SPEED) vel=SPEED;
  int dx = cos(get_degrees(o.getAngle()))*vel;
  int dy = sin(get_degrees(o.getAngle()))*vel;
  if(pu) o.moveDest(dx,dy);
  if(pd) o.moveDest(-dx,-dy);

  if(o.getDestX() < 0) { o.setDestX(0); vel=vel/2; }
  if(o.getDestX() > WIDTH-o.getDestW()) { o.setDestX(WIDTH-o.getDestW()); vel=vel/2; }
  if(o.getDestY() < 0) { o.setDestY(0); vel=vel/2; }
  if(o.getDestY() > HEIGHT-o.getDestH()) { o.setDestY(HEIGHT-o.getDestH()); vel=vel/2; }
}

double Game::get_degrees(double input) {
    const double halfC = M_PI / 180;
    return input * halfC;
}

