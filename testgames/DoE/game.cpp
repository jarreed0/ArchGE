#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Day of Escape", WIDTH, HEIGHT, 0);
  e.setColor(0xff, 0xff, 0xff);
  running = true;
  e.setFrameRate(FRAMERATE);
  
  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(64 * iframe, 0, 64, 64);
  player.setDest(0, 0, 64, 64);

  tile.setImage("res/ground.png", e.getRenderer());
  tile.setFrame(0, 0, 64, 64);

  loop();
}

Game::~Game() {}

void Game::loop() {
  while(running) {
    input();
    if(!paused) update();
    draw();
    e.loop();
  }
}

void Game::draw() {
  e.draw(player);
  drawFloor();
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.a) && !movingl) {movingl = true;movingr = false;lookingleft = true;lookingright = false;}
  if(!i.checkKey(i.a) && movingl) {movingl = false;}
  if(i.checkKey(i.d) && !movingr) {movingr = true;movingl = false;lookingright = true;lookingleft = false;}
  if(!i.checkKey(i.d) && movingr) {movingr = false;}
  if(i.checkKey(i.p)) paused = !paused;
  if(i.checkKey(i.esc)) running = false;
}

void Game::update() {
  updatePlayer();
  gravity();
}

void Game::gravity() {
  if(player.getDestY() < 358) player.setDestY(player.getDestY() + 8);
}

void Game::updatePlayer() {
  if(movingl) player.setDestX(player.getDestX() - 3.0);
  if(movingr) player.setDestX(player.getDestX() + 3.0);

  if(movingl || movingr) {
    fcount++;
    if(fcount >= fdelay) {
      fcount = 0;
      pframe++;
      if(pframe >= 4) {
        pframe = 0;
      }
    }
  }

  if(!movingl && !movingr) {
    icount++;
    if(icount >= idelay) {
      icount = 0;
      iframe++;
      if(iframe >= 2) {
        iframe = 0;
      }
    }
  }

  if(!movingl && !movingr && lookingleft) player.setFrame(64 * iframe, 0, 64, 64);
  if(!movingl && !movingr && lookingright) player.setFrame(64 * (iframe + 2), 0, 64, 64);
  if(movingl && !movingr) player.setFrame(64 * pframe, 64, 64, 64);
  if(!movingl && movingr) player.setFrame(64 * pframe, 128, 64, 64);
}

void Game::drawFloor() {
  for(int i = 0; i < 10; i++) {
    tile.setDest(i * 64, 420, 64, 64);
    e.draw(tile);
  }
}
