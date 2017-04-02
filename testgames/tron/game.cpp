#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Tron", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);
  running = true;
  arena.setDest(0, 0, WIDTH, HEIGHT);
  genTiles();
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
  bike.setDest(100, 100, 64, 64);
  gs.setGameState(gs.INGAME);
  e.setFrameRate(FRAMERATE);
  Object tmp;
  tmp.setColor(0xff, 0xa5, 0x00);
  beam.push_back(tmp);
  paused=false;
  cout << "p to pause" << endl;
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
  if(i.checkKey(i.left)) l = true;
  if(i.checkKey(i.right)) r = true;
  if(i.checkKey(i.up)) u = true;
  if(i.checkKey(i.down)) d = true;
  if(i.checkKey(i.p)) paused=!paused;
}

void Game::update() {
  if(l && !faceleft) {faceleft = true;faceright = false;faceup = false;facedown = false;bike.setAngle(-90);}
  if(r && !faceright) {faceright = true;faceleft = false;facedown = false;faceup = false;bike.setAngle(90);}
  if(d && !facedown) {facedown = true;faceup = false;faceleft = false;faceright = false;bike.setAngle(180);}
  if(u && !faceup) {faceup = true;facedown = false;faceleft = false;faceright = false;bike.setAngle(0);}
  if(faceleft) {bike.setDestX(bike.getDestX() - SPEED); beam[beam.size()-1].setDest(bike.getDestX()+32, bike.getDestY()+30, 300, 5);}
  if(faceright) {bike.setDestX(bike.getDestX() + SPEED); beam[beam.size()-1].setDest(bike.getDestX()+32-300, bike.getDestY()+30, 300, 5);}
  if(facedown) {bike.setDestY(bike.getDestY() + SPEED); beam[beam.size()-1].setDest(bike.getDestX()+30, bike.getDestY()+32-300, 5, 300);}
  if(faceup) {bike.setDestY(bike.getDestY() - SPEED); beam[beam.size()-1].setDest(bike.getDestX()+30, bike.getDestY()+32, 5, 300);}
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
