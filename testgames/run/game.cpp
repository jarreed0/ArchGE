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

  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(0,0,50,50);
  player.setDest(10, 10, 25, 25);

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
  e.draw(burn);
  e.draw(car);
  if(!inCar) e.draw(player);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) e.setRunning(false);
  u=d=l=r=0;
  if(i.checkKey(i.w)) u=true;
  if(i.checkKey(i.s)) d=true;
  if(i.checkKey(i.a)) l=true;
  if(i.checkKey(i.d)) r=true;
  car.setPos(car.getDest());
  player.setPos(player.getDest());
  if(i.checkKey(i.e)) if(inCar) {getOut();cout<<"out"<<endl;} else if(col.isTouching(car,player)) {getIn();cout<<"in"<<endl;}
}

void Game::update() {
  if(inCar) driveCar();
  if(!inCar) walk();

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
//  if(l) player.rotateAngle(-PROTATE);
//  if(r) player.rotateAngle(PROTATE);
  player.lookAt(i);

  if(u) pvel = PSPEED;
  if(d) pvel = -PSPEED;
  if(!u && !d) pvel = 0;

  int dx = cos(get_degrees(player.getAngle()))*pvel;
  int dy = sin(get_degrees(player.getAngle()))*pvel;
  player.moveDest(dx,dy);

  if(player.getDestX() < 0) { player.setDestX(0); pvel=pvel/2; }
  if(player.getDestX() > WIDTH-player.getDestW()) { player.setDestX(WIDTH-player.getDestW()); pvel=pvel/2; }
  if(player.getDestY() < 0) { player.setDestY(0); pvel=pvel/2; }
  if(player.getDestY() > HEIGHT-player.getDestH()) { player.setDestY(HEIGHT-player.getDestH()); pvel=pvel/2; }
}

