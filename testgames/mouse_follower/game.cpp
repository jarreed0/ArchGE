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

  makeNewBlock=false;

  cout << "Press m to create a new object." << endl;

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
  e.draw(mobjs);
  e.draw(mobjs2);
}

void Game::input() {
  i.logPress();
  makeNewBlock=false;
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) running = false;
  if(i.checkKey(i.mouseleft)) {
   cout << o.getVelX();cout << " ,";cout << o.getVelY();cout << "\n";
   makeNewBlock=true;
  }
}

void Game::update() {
  o2.setDest(i.getMouseX(), i.getMouseY(), 16, 16);
  if(o2.getDestX() > (WIDTH-o2.getDestW())) o2.setDestX(WIDTH-o2.getDestW());
  if(o2.getDestY() > (HEIGHT-o2.getDestH())) o2.setDestY(HEIGHT-o2.getDestH());
  if(timeToMove) {o.setVelTo(o2); o.moveDest(o.getVelX(), o.getVelY());}
  for(int j=0; j<mobjs.size(); j++) {
  if(j=0) {
     mobjs2[j].setDest(i.getMouseX(), i.getMouseY(), 16, 16);
   } else {
    //mobjs2[j].setDest(mobjs[j-1].getDestX(), mobjs[j-1].getDestY(), 16, 16);
   }
   if(mobjs2[j].getDestX() > (WIDTH-mobjs2[j].getDestW())) mobjs2[j].setDestX(WIDTH-mobjs2[j].getDestW());
   if(mobjs2[j].getDestY() > (HEIGHT-mobjs2[j].getDestH())) mobjs2[j].setDestY(HEIGHT-mobjs2[j].getDestH());
   if(timeToMove) {mobjs[j].setVelTo(mobjs2[j]); mobjs[j].moveDest(mobjs[j].getVelX(), mobjs[j].getVelY());}
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
 mo2=mo;
 mobjs.push_back(mo);
 mobjs2.push_back(mo2);
}
