#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Tron", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);
  running = true;
  arena.setDest(0, 0, WIDTH, HEIGHT);
  arena.setPos(arena.getDest());
  genTiles();
  logo.setImage("res/engine-logo.png", e.getRenderer());
  logo.setFrame(0, 0, 256, 256);
  logo.center(WIDTH, HEIGHT);
  bike.setImage("res/bike.png", e.getRenderer());
  bike.setFrame(0, 0, 64, 64);
  bike.setAngle(180);
  spawn.setDestSize(20, 42);
  spawn.center(WIDTH, HEIGHT);
  respawn();
  gs.setGameState(gs.INGAME);
  e.setFrameRate(FRAMERATE);
  paused=false;
  cout << "p to pause" << endl;
  cout << "c to clear all beams" << endl;
  cout << "arrows to control" << endl;
  loop();
}
Game::~Game() {}

void Game::loop() {
  while(running) {
        //timerFps = e.getTicks(); // SDL_GetTicks() gives the number of milliseconds since the program start.
                                   // I initialize the timer.
        input();
        if(!paused) update();
        draw();
        e.loop();
        /*timerFps = e.getTicks() - timerFps; //I get the time it took to update and draw;

        if(timerFps < 1000/FRAMERATE) // if timerFps is < 16.6666...7 ms (meaning it loaded the frame too fast)
        {
            e.delay((1000/FRAMERATE) - timerFps); //delay the frame to be in time
        } */
  }
}

void Game::draw() {
  /*if(gs.getGameState() == gs.SPLASH) {
    e.draw(logo);
    scount++;
    if(scount >= sdelay) {scount = 0; gs.setGameState(gs.INGAME);}
  }*/
  if(gs.getGameState() == gs.INGAME) {
    e.draw(tile);
    e.draw(beam);
    e.draw(bike);
  }
}

void Game::input() {
  r=l=u=d=false;
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) running = false;
  if(i.checkKey(i.left)) { l = true; newBeam(); }
  if(i.checkKey(i.right)) { r = true; newBeam(); }
  if(i.checkKey(i.up)) { u = true; newBeam(); }
  if(i.checkKey(i.down)) { d = true; newBeam(); }
  if(i.checkKey(i.p)) paused=!paused;
  if(i.checkKey(i.c)) { beam.clear(); newBeam(); }
}

void Game::update() {
  if(l && !faceleft) {faceleft = true;faceright = false;faceup = false;facedown = false;bike.setAngle(-90);}
  if(r && !faceright) {faceright = true;faceleft = false;facedown = false;faceup = false;bike.setAngle(90);}
  if(d && !facedown) {facedown = true;faceup = false;faceleft = false;faceright = false;bike.setAngle(180);}
  if(u && !faceup) {faceup = true;facedown = false;faceleft = false;faceright = false;bike.setAngle(0);}
  if(faceleft) {bike.setDestX(bike.getDestX() - SPEED); beam[beam.size()-1].setDest(bike.getDestX()+42, bike.getDestY()+20, streak, 5);}
  if(faceright) {bike.setDestX(bike.getDestX() + SPEED); beam[beam.size()-1].setDest(bike.getDestX()-streak-20, bike.getDestY()+20, streak, 5);}
  if(facedown) {bike.setDestY(bike.getDestY() + SPEED); beam[beam.size()-1].setDest(bike.getDestX()+9, bike.getDestY()-streak-10, 5, streak-10);}
  if(faceup) {bike.setDestY(bike.getDestY() - SPEED); beam[beam.size()-1].setDest(bike.getDestX()+9, bike.getDestY()+48, 5, streak);}
  streak+=SPEED;
  bike.setPos(bike.getDest());
  if(col.outOfBoundsOf(bike, arena)) { respawn(); }
  for(int i=0; i<beam.size(); i++) {
    beam[i].setPos(beam[i].getDest());
    if(col.isTouching(bike, beam[i])) { respawn(); }
  }
}
void Game::genTiles() {
 for(int i = 0; i < (WIDTH/TILESIZE)+1; i++) {
    for(int j = 0; j < (HEIGHT/TILESIZE)+1; j++) {
      Object tmp;
      tmp.setDest(i * TILESIZE, j * TILESIZE, TILESIZE, TILESIZE);
      tmp.setFrame(0, 0, TILESIZE, TILESIZE);
      tmp.setImage("res/tile.png", e.getRenderer());
      tile.push_back(tmp);
    }
  }
}

void Game::newBeam() {
  Object tmp;
  tmp.setColor(0xff, 0xa5, 0x00);
  beam.push_back(tmp);
  streak=0;
}

void Game::respawn() {
  facedown = true;
  faceup = false;
  faceright = false;
  faceleft = false;
  bike.setAngle(180);
  beam.clear();
  bike.setDest(spawn.getDest());
  newBeam();
}
