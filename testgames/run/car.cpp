#include "car.h"

Car::Car() {
 setRotate(1.5);
 setScale(1.3);
 setStutter(.3);
 setSpeed(7);
 setVel(0);
}

void Car::drive() {
  if(!u && !d) {
    if(vel > 0) vel-=vel*.05;
    if(vel < 0) vel+=abs(vel)*.05;
  }
  int dx = cos(get_degrees(c.getAngle()))*vel;
  int dy = sin(get_degrees(c.getAngle()))*vel;
  c.moveDest(dx,dy);
  if(c.getDestX() < 0) { c.setDestX(0); vel=vel/2; }
  if(c.getDestX() > wbounds-c.getDestW()) { c.setDestX(wbounds-c.getDestW()); vel=vel/2; }
  if(c.getDestY() < 0) { c.setDestY(0); vel=vel/2; }
  if(c.getDestY() > hbounds-c.getDestH()) { c.setDestY(hbounds-c.getDestH()); vel=vel/2; }
  if(vel>(getSpeed()-1) || vel<(-getSpeed()+1) && in) genBurn();
  int burnTick = SDL_GetTicks();;
  static int lastBurnTick = SDL_GetTicks();;
  if(burnTick-lastBurnTick > 50 && burn.size() > 2) {
    lastBurnTick=burnTick;
    for(int i=0; i<3; i++) burn.erase(burn.begin());
  }
}

void Car::getIn() {}

void Car::getOut() {}

void Car::genBurn() {
  for(int i=2; i<4; i++) {
    Object tmp;
    tmp.setDest((i*15)+c.getDestX(),(i*6)+c.getDestY(),10-i,10+i);
    tmp.setColor(180+(i*5), 165-(i*3), 120+(i*3));
    burn.push_back(tmp);
  }
}

void Car::move(bool le, bool ri, bool up, bool dn) {
  l=le; r=ri; u=up; d=dn;
  static bool stutter = true;

  if(l) c.rotateAngle(-rotate-abs(vel/2));
  if(r) c.rotateAngle(rotate+abs(vel/2));
  if(vel>c.getSpeed()) vel=c.getSpeed();
  if(vel<-c.getSpeed()) vel=-c.getSpeed();

  if(vel > -.8 && vel < .8) { vel=0; stutter=true; }
  if(u) { if(vel<=0 && vel<1) {vel=1;} vel+=vel*.02; }
  if(d) { if(vel>=0 && vel>-1) {vel=-1;} vel-=abs(vel)*.02; }

  if(abs(vel) < c.getSpeed()*.3) stutter=true;
  static int stutterTick = 0;
  if(abs(vel) >= (abs(c.getSpeed())*.5) && stutter) {
     vel-=vel*.15;
     stutterTick++;
     if(stutterTick > 4) {
        stutter = false;
        stutterTick = 0;
     }
  }
}

void Car::update() {}

Object Car::setCar(string img, int fx, int fy, int fw, int fh, SDL_Renderer* ren, float sp, float sc) {
  c.setImage(img, ren);
  c.setFrame(fx, fy, fw, fh);
  c.setSpeed(sp);
  setScale(sc);
  c.setDestSize(fw*scale,fh*scale);
}

double Car::get_degrees(double input) {
    const double halfC = M_PI / 180;
    return input * halfC;
}
