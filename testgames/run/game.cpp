#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("RUN!", WIDTH, HEIGHT, 0);
  e.setColor(194, 177, 128);

  car.setImage("res/car.png", e.getRenderer());
  car.setFrame(0, 0, 57, 35);
  car.setSpeed(3);
  car.setDestSize(57*SCALE,35*SCALE);
  car.center(WIDTH, HEIGHT);
  u=d=l=r=0;
  vel=0;
  inCar=true;

  c1.setBounds(WIDTH, HEIGHT);
  c1.setCar(car);
  c1.setSpeed(SPEED);
  c1.setVel(vel);
  c1.setRotate(ROTATE);
  c1.setScale(SCALE);

  c2.setBounds(WIDTH, HEIGHT);
  car.setDestCoord(WIDTH-200,HEIGHT-200);
  car.setFrameX(57);
  c2.setCar(car);
  c2.setSpeed(SPEED);
  c2.setVel(vel);
  c2.setRotate(ROTATE);
  c2.setScale(SCALE);

  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(0,0,50,50);
  player.setDest(10, 10, 25, 25);

  bullet.setColor(20,30,40);
  bullet.setDestSize(3,3);

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
  e.draw(c1.getBurns());
  e.draw(c2.getBurns());
  e.draw(bullets);
  e.draw(c1.getCar());
  e.draw(c2.getCar());
  e.draw(player);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) e.setRunning(false);
  u=d=l=r=0;
  if(i.checkKey(i.w)) u=true;
  if(i.checkKey(i.s)) d=true;
  if(i.checkKey(i.a)) l=true;
  if(i.checkKey(i.d)) r=true;

  u2=d2=l2=r2=0;
  if(i.checkKey(i.up)) u2=true;
  if(i.checkKey(i.down)) d2=true;
  if(i.checkKey(i.left)) l2=true;
  if(i.checkKey(i.right)) r2=true;

  u3=d3=l3=r3=0;
  if(i.checkKey(i.i)) u3=true;
  if(i.checkKey(i.k)) d3=true;
  if(i.checkKey(i.j)) l3=true;
  if(i.checkKey(i.l)) r3=true;

  if(i.checkKey(i.mouseleft)) click=1;
}

void Game::update() {
  walk();

  c1.move(l3,r3,u3,d3);
  c1.drive();

  c2.move(l2,r2,u2,d2);
  c2.drive();

  if(click) fire();

  for(int i=0; i<bullets.size(); i++) {
    bullets[i].setDestCoord(bullets[i].getDestX()+bullets[i].getVelX(), bullets[i].getDestY()+bullets[i].getVelY());
  }
}

double Game::get_degrees(double input) {
    const double halfC = M_PI / 180;
    return input * halfC;
}


void Game::walk() {
  player.lookAt(i);

  int dx = cos(get_degrees(player.getAngle()))*PROTATE;
  int dy = sin(get_degrees(player.getAngle()))*PROTATE;

  if(l) player.moveDest(dy, -dx);
  if(r) player.moveDest(-dy, dx);

  dx = cos(get_degrees(player.getAngle()))*pvel;
  dy = sin(get_degrees(player.getAngle()))*pvel;

  if(u) pvel = PSPEED;
  if(d) pvel = -PSPEED;
  if(!u && !d) pvel = 0;

  if(u || d) player.moveDest(dx,dy);

  if(player.getDestX() < 0) { player.setDestX(0); pvel=pvel/2; }
  if(player.getDestX() > WIDTH-player.getDestW()) { player.setDestX(WIDTH-player.getDestW()); pvel=pvel/2; }
  if(player.getDestY() < 0) { player.setDestY(0); pvel=pvel/2; }
  if(player.getDestY() > HEIGHT-player.getDestH()) { player.setDestY(HEIGHT-player.getDestH()); pvel=pvel/2; }
}

void Game::fire() {
  Object tmp = bullet;
  tmp.setSpeed(10);
  tmp.setDestCoord(player.getDestX(), player.getDestY());
  tmp.setVelTo(i.getMouseX(), i.getMouseY());
  cout << tmp.getVelX() << " - " << tmp.getVelY() << endl;
  bullets.push_back(tmp);
}


