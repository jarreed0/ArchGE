#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Tron", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);
  running = true;
  arena.setDest(0, 0, WIDTH, HEIGHT);
  logo.setImage("res/engine-logo.png", e.getRenderer());
  logo.setFrame(0, 0, 256, 256);
  logo.center(WIDTH, HEIGHT);
  bike.setImage("res/bike.png", e.getRenderer());
  bike.setFrame(0, 0, 64, 64);
  bike.setAngle(180);
  facedown = true;
  faceup = false;
  faceright = false;
  faceleft = false;
  vel = 30;
  bike.setDest(100, 100, 64, 64);
  tile.setImage("res/tile.png", e.getRenderer());
  tile.setFrame(0, 0, 64, 64);
  gs.setGameState(gs.INGAME);
  e.setFrameRate(FRAMERATE);
  loop();
}
Game::~Game() {}

void Game::loop() {
  while(running) {
    //e.loopStart();
    //bool frame = true;
    //while(frame) {
      //e.update();

        //timerFps = e.getTicks(); // SDL_GetTicks() gives the number of milliseconds since the program start.
                                   // I initialize the timer.

        input();
        update();
        draw();
        e.loop();
/*
        timerFps = e.getTicks() - timerFps; //I get the time it took to update and draw;

        if(timerFps < 1000/FRAMERATE) // if timerFps is < 16.6666...7 ms (meaning it loaded the frame too fast)
        {
            e.delay((1000/FRAMERATE) - timerFps); //delay the frame to be in time
        } */
      //if(!e.FPS()) { frame=false; }
    //}
    //e.render();/
  }
}

void Game::draw() {
  /*if(gs.getGameState() == gs.SPLASH) {
    e.draw(logo);
    scount++;
    if(scount >= sdelay) {scount = 0; gs.setGameState(gs.INGAME);}
  }*/
  if(gs.getGameState() == gs.INGAME) {
    drawTiles();
    e.draw(bike);
  }
}

void Game::input() {
  r=l=u=d=false;
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) running = false;
  if(i.checkKey(i.left)) l = true;
  if(i.checkKey(i.right)) r = true;
  if(i.checkKey(i.up)) u = true;
  if(i.checkKey(i.down)) d = true;
}

void Game::update() {
  if(l && !faceleft) {faceleft = true;faceright = false;faceup = false;facedown = false;bike.setAngle(-90);}
  if(r && !faceright) {faceright = true;faceleft = false;facedown = false;faceup = false;bike.setAngle(90);}
  if(d && !facedown) {facedown = true;faceup = false;faceleft = false;faceright = false;bike.setAngle(180);}
  if(u && !faceup) {faceup = true;facedown = false;faceleft = false;faceright = false;bike.setAngle(0);}
  if(faceleft) {bike.setDestX(bike.getDestX() - SPEED);}
  if(faceright) {bike.setDestX(bike.getDestX() + SPEED);}
  if(facedown) {bike.setDestY(bike.getDestY() + SPEED);}
  if(faceup) {bike.setDestY(bike.getDestY() - SPEED);}
}

void Game::drawTiles() {
 for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 8; j++) {
      tile.setDest(i * 64, j * 64, 64, 64);
      e.draw(tile);
    }
  }
}
