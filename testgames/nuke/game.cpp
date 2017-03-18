#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Nuke", WIDTH, HEIGHT, 0);
  e.setColor(0x70, 0x70, 0x90);
  tileset.create("tiles", "res/tiles.png", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/TILES_PER_ROW, TILES_PER_ROW, TOTAL_TILES);
  tileset.setPassable(1, 16);
  tileset.setSolid(1, 2);
  tileset.setSolid(9, 10);
  map.loadMap("res/map");
  level.setPrecise(true);
  stage.createStage(map, tileset);
  level.setStage(stage);
  level.create();
  level.setScreenSize(WIDTH, HEIGHT);
  running = true;
  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(0, 0, 45, 45);
  player.setDest(250, 200, 45, 45);
  player.setPos(0, 0, 45, 45);
  level.addEntity(player);
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
  i.logPress();
  if(i.checkKey(i.esc) || i.checkKey(i.quit)) running = false;
  if(i.checkKey(i.left)) l=true;
  if(!i.checkKey(i.left)) l=false;
  if(i.checkKey(i.right)) r=true;
  if(!i.checkKey(i.right)) r=false;
  if(i.checkKey(i.up)) u=true;
  if(!i.checkKey(i.up)) u=false;
  if(i.checkKey(i.down)) d=true;
  if(!i.checkKey(i.down)) d=false;
}

void Game::update() {
  mcount++;
  if(mcount >= mdelay) {
    mcount = 0;
    if(l) level.move(-SPEED, 0);
    if(r) level.move(SPEED, 0);
    if(d) level.move(0, -SPEED);
    if(u) level.move(0, SPEED);
  }
}
