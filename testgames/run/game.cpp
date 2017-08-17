#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("RUN!", WIDTH, HEIGHT, 0);
  e.setColor(194, 177, 128);//(226,206,179);

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

  //c2 = c1;
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
  //e.draw(burn);
  e.draw(c1.getBurns());
  e.draw(c2.getBurns());
  e.draw(bullets);
  //e.draw(car);
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

  //car.setPos(car.getDest());
  //player.setPos(player.getDest());
  //if(i.checkKey(i.e)) if(inCar) {getOut();cout<<"out"<<endl;} else if(col.isTouching(car,player)) {getIn();cout<<"in"<<endl;}
  click=0;
  if(i.checkKey(i.mouseleft)) click=1;
}

void Game::update() {
  //if(inCar) driveCar();
  walk();

  //c1.move(l,r,u,d);
  c1.drive();

  c2.move(l2,r2,u2,d2);
  c2.drive();

  if(click) fire();
/*
  if(!u && !d) {
    if(vel > 0) vel-=vel*.05;
    if(vel < 0) vel+=abs(vel)*.05;
  }
  int dx = cos(get_degrees(car.getAngle()))*vel;
  int dy = sin(get_degrees(car.getAngle()))*vel;
  car.moveDest(dx,dy);
  if(car.getDestX() < 0) { car.setDestX(0); vel=vel/2; }
  if(car.getDestX() > WIDTH-car.getDestW()) { car.setDestX(WIDTH-car.getDestW()); vel=vel/2; }
  if(car.getDestY() < 0) { car.setDestY(0); vel=vel/2; }
  if(car.getDestY() > HEIGHT-car.getDestH()) { car.setDestY(HEIGHT-car.getDestH()); vel=vel/2; }
  if(vel>(SPEED-1) || vel<(-SPEED+1) && inCar) genBurn();
  int burnTick = e.getTicks();
  static int lastBurnTick = e.getTicks();
  if(burnTick-lastBurnTick > 50 && burn.size() > 2) {
    lastBurnTick=burnTick;
    for(int i=0; i<3; i++) burn.erase(burn.begin());
  }
  if(inCar) player.setDestCoord(car.getDestX(), car.getDestY());*/

  for(int i=0; i<bullets.size(); i++) {
    bullets[i].setDestCoord(bullets[i].getDestX()+bullets[i].getVelX(), bullets[i].getDestY()+bullets[i].getVelY());
  }
}

double Game::get_degrees(double input) {
    const double halfC = M_PI / 180;
    return input * halfC;
}

void Game::genBurn() {
  for(int i=2; i<4; i++) {
    Object tmp;
    tmp.setDest((i*15)+car.getDestX(),(i*6)+car.getDestY(),10-i,10+i);
    tmp.setColor(180+(i*5), 165-(i*3), 120+(i*3));//(22+(i*5),24-(i*3),26+(i*3));
    burn.push_back(tmp);
  }
}

void Game::driveCar() {
  static bool stutter = true;

  if(l) car.rotateAngle(-ROTATE-abs(vel/2));
  if(r) car.rotateAngle(ROTATE+abs(vel/2));
  if(vel>SPEED) vel=SPEED;
  if(vel<-SPEED) vel=-SPEED;

  if(vel > -.8 && vel < .8) { vel=0; stutter=true; }
  if(u) { if(vel<=0 && vel<1) {vel=1;} vel+=vel*.02; }
  if(d) { if(vel>=0 && vel>-1) {vel=-1;} vel-=abs(vel)*.02; }

  if(abs(vel) < SPEED*.3) stutter=true;
  static int stutterTick = 0;
  if(abs(vel) >= (abs(SPEED)*.5) && stutter) {
     vel-=vel*.15;
     stutterTick++;
     if(stutterTick > 4) {
        stutter = false;
        stutterTick = 0;
     }
  }
}

void Game::getIn() {
  inCar=true;
}

void Game::getOut() {
  inCar=false;
  player.setDestCoord(car.getDestX(), car.getDestY());
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

