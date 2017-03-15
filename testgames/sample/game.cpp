#include "game.h"

Game::Game() {
  e.bypassSplash(4231998);
  e.init("sample", WIDTH, HEIGHT, 0); //SPLASH DOESN'T WORK, NEED TO FIX!!!
  //e.setColor(0x00, 0xff, 0x80);
  e.setColor(0x00, 0x08, 0x99);
  //e.setBackground("../../engine/res/engine-logo.png");
  tileset.create("tiles", "res/tiles.bmp", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES);
  map.loadMap("res/1.level");
  level.setPrecise(true);
  stage.createStage(map, tileset);
  level.setStage(stage);
  level.create();
  //level.setScale(40, 40);
  level.setScreenSize(WIDTH, HEIGHT);
  running = true;
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
  e.drawLevel(level);
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
