#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Day of Escape", WIDTH, HEIGHT, 0);
  e.setColor(65, 244, 193);
  running = true;
  e.setFrameRate(FRAMERATE);  

  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(64 * iframe, 0, 64, 64);
  player.setDest(32, 0, 64, 64);

  tile.setImage("res/ground.png", e.getRenderer());
  tile.setFrame(0, 0, 64, 64);

  tile2.setImage("res/ground.png", e.getRenderer());
  tile2.setFrame(0, 0, 64, 64);
  tile2.setDest(128, 356, 64, 64);

  tile3.setImage("res/ground.png", e.getRenderer());
  tile3.setFrame(0, 0, 64, 64);
  tile3.setDest(192, 292, 64, 64);

  ground.setDest(0, 420, 640, 64);
  screen.setDest(0, 0, WIDTH, HEIGHT);

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
  e.draw(tile2);
  e.draw(tile3);
  e.draw(player);
  e.draw(tile);
  drawFloor();
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.a) && !movingl) {movingl = true;movingr = false;lookingleft = true;lookingright = false;}
  if(!i.checkKey(i.a) && movingl) {movingl = false;}
  if(i.checkKey(i.d) && !movingr) {movingr = true;movingl = false;lookingright = true;lookingleft = false;}
  if(!i.checkKey(i.d) && movingr) {movingr = false;}
  if(i.checkKey(i.w) && !jumping && !nj) {jumping = true;nj = true;}
  if(i.checkKey(i.p)) paused = !paused;
  if(i.checkKey(i.esc) || i.checkKey(i.quit)) running = false;
}

void Game::update() {
  updatePlayer();
  gravity();
  nowJumping();
}

void Game::gravity() {
  if (!jumping) {
    for (int i = 0; i < 8; i++) {
      player.setDestY(player.getDestY() + 1);
      if (col.overlaps(player, ground) || col.overlaps(player, tile2) || col.overlaps(player, tile3)) {
        player.setDestY(player.getDestY() - 1);
        if (nj) nj = false;
      }
    }
  }
}

void Game::updatePlayer() {
  for (int i = 0; i < 3; i++) {
    if(movingl) {
      player.setDestX(player.getDestX() - 1.0);
      if(!col.contains(screen, player)) player.setDestX(player.getDestX() + 1.0);
      if(col.overlaps(tile2, player)) player.setDestX(player.getDestX() + 1.0);
      if(col.overlaps(tile3, player)) player.setDestX(player.getDestX() + 1.0);
    }

    if(movingr) {
      player.setDestX(player.getDestX() + 1.0);
      if(!col.contains(screen, player)) player.setDestX(player.getDestX() - 1.0);
      if(col.overlaps(tile2, player)) player.setDestX(player.getDestX() - 1.0);
      if(col.overlaps(tile3, player)) player.setDestX(player.getDestX() - 1.0);
    }
  }  

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

void Game::nowJumping() {
  if(jumping){
    jump += 8;
    player.setDestY(player.getDestY() - 8.0);
    if(jump >= 80) {
      jumping = false;
      jump = 0;
    }
  }
}
