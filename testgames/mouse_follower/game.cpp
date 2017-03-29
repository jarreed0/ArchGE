#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Mouse Follower", WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS);
  e.setColor(0xff, 0xff, 0xff);
  running = true;

  o.setImage("res/object.png", e.getRenderer());
  o.setFrame(0, 0, 16, 16);
  o.setSpeed(3);
  o.setDest(100,100,16,16);
  o.center(WIDTH, HEIGHT);

  o2=o;
  mobjs.push_back(o);

  makeNewBlock=false;

  e.setFontColor(0xff, 0xff, 0xff);

  cout << "Click mouse for more objects.\nPress z for object count.\n";

  loop();
}
Game::~Game() {}

void Game::loop() {
  while(running) {
    e.loopStart();
    //bool frame = true;
    //while(frame) {
      e.update();
      makeNewBlock=false;
      input();
      update();
      draw();
      //if(!e.FPS()) { frame=false; }
    //}
    e.render();
  }
}

void Game::draw() {
  //e.draw(o);
  e.draw(mobjs);
  //e.draw(e.getFPS(), 10, 10);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) running = false;
  if(i.checkKey(i.mouseleft)) { cout << mobjs[0].getVelX() << ", " << mobjs[0].getVelY() << endl; makeNewBlock=true; }
  if(i.checkKey(i.z)) {  cout << ":" << mobjs.size() << endl; }
}

void Game::update() {
  o2.centerOn(i);
  if(o2.getDestX() > (WIDTH-o2.getDestW())) o2.setDestX(WIDTH-o2.getDestW());
  if(o2.getDestY() > (HEIGHT-o2.getDestH())) o2.setDestY(HEIGHT-o2.getDestH());
  if(o2.getDestX() < 0) o2.setDestX(0);
  if(o2.getDestY() < 0) o2.setDestY(0);
  if(timeToMove) {mobjs[0].setVelTo(o2); mobjs[0].moveDest(mobjs[0].getVelX(), mobjs[0].getVelY());}

  for(int j=1; j<mobjs.size(); j++) {
   if(timeToMove) {
    Object moveTo = mobjs[j-1];
    moveTo.setDest(mobjs[j-1].getMovedBuff());
    //moveTo.setDestCoord(moveTo.getDestX()-(moveTo.getDestW()/2), moveTo.getDestY()-(moveTo.getDestH()/2));
    /*if(col.isAbove(moveTo, mobjs[j-1])) {
     moveTo.setDestY(moveTo.getDestY()+moveTo.getSpeed());
    } else {
     moveTo.setDestY(moveTo.getDestY()-moveTo.getSpeed());
    }
    if(col.isLeftOf(moveTo, mobjs[j-1])) {
     moveTo.setDestX(moveTo.getDestX()+moveTo.getSpeed());
    } else {
     moveTo.setDestX(moveTo.getDestX()-moveTo.getSpeed());
    }*/
    mobjs[j].setVelTo(moveTo);
    mobjs[j].moveDest(mobjs[j].getVelX(), mobjs[j].getVelY());
   }
  }

  mcount++;
  if(mcount >= vel) {
    mcount = 0;
    timeToMove = true;
    if(makeNewBlock) createObj();
  }
}

void Game::createObj() {
 cout << "Creating new object " << mobjs.size() << endl;
 Object mo, mo2;
 mo.setImage("res/object.png", e.getRenderer());
 mo.setFrame(0, 0, 16, 16);
 mo.setSpeed(3);
 mo.setDest(100, 100, 16, 16);
 //mo2=mo;
 mobjs.push_back(mo);
 //mobjs2.push_back(mo2);
}
