#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Nuke", WIDTH, HEIGHT, 0); //SPLASH DOESN'T WORK, NEED TO FIX!!!
  e.setColor(0x90, 0x75, 0x60);
  //e.setBackground("../../engine/res/engine-logo.png");
  level.setPrecise(true);
  level.setScreenSize(WIDTH, HEIGHT);
  stage.createStage("res/map", "tiles", "res/tiles.png", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/TILES_PER_ROW, TILES_PER_ROW, TOTAL_TILES);
  level.setStage(stage);
  level.create();
  running = true;
  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(0, 0, 45, 45);
  player.setDest(250, 200, 45, 45);
  player.setPos(0, 0, 45, 45);
  player.center(WIDTH, HEIGHT);
  loop();
}
Game::~Game() {
}

void Game::loop() {
  while(running) {
    e.loopStart();
    bool frame = true;
    while(frame) {
      e.update();
      input();
      update();
      draw();
      if(!e.FPS()) frame=false;
    }
    e.render();
  }
}

void Game::draw() {
  e.draw(level);
  e.draw(player);
}

void Game::input() {
  r=l=u=d=false;
  i.logPress();
  if(i.checkKey(i.esc) || i.checkKey(i.quit)) running = false;
  if(i.checkKey(i.left)) l=true;
  if(i.checkKey(i.right)) r=true;
  if(i.checkKey(i.up)) u=true;
  if(i.checkKey(i.down)) d=true;
}

void Game::update() {
  if(l) level.move(-SPEED, 0);
  if(r) level.move(SPEED, 0);
  if(d) level.move(0, -SPEED);
  if(u) level.move(0, SPEED);
}
