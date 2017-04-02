#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("sample", WIDTH, HEIGHT, 0); //SPLASH DOESN'T WORK, NEED TO FIX!!!
  e.setGravity(9.8);
  //e.setColor(0x00, 0xff, 0x80);
  e.setColor(0x00, 0x08, 0x99);
  e.setFrameRate(60);
  //e.setBackground("../../engine/res/engine-logo.png");
  tileset.create("tiles", "res/tiles.bmp", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES);
  tileset.setSolid(1, TOTAL_TILES);
  map.loadMap("res/1.level");
  level.setPrecise(true);
  stage.createStage(map, tileset);
  level.setStage(stage);
  level.create();
  //level.setScale(40, 40);
  level.setScreenSize(WIDTH, HEIGHT);
  running = true;
  player.setImage("res/player.bmp", e.getRenderer());
  player.setFrame(0, 0, 42/2, 64/2);
  player.setDestSize(42/2, 64/2);
  player.center(WIDTH, HEIGHT);
  player.setPos(0, 0, 42/2, 64/2);
  player.actGravity(true);
  loop();
}
Game::~Game() {
}

void Game::loop() {
  while(running) {
    e.loopStart();
    //bool frame = true;
    //while(frame) {
      e.update();
      input();
      update();
      draw();
      //if(!e.FPS()) frame=false;
    //}
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
player.setPos(player.getDest());
mcount++;
if(mcount >= mdelay) {
  mcount = 0;
  if(l) level.move(-SPEED, 0);
  if(r) level.move(SPEED, 0);
  //if(d) level.move(0, -SPEED);
  if(u) player.move(0, SPEED);//level.move(0, SPEED);
  vector<Tile> utiles = level.getTilesToRender();
  bool fall=true;
  for(int i = 0; i<utiles.size(); i++) {
   utiles[i].setPos(utiles[i].getDest());
   if(utiles[i].isSolid() && col.isTouching(player, utiles[i])) {
     //cout << utiles[i].getName() << endl;
     fall=false;
   }
  }
  if(fall) player.moveDest(0, e.getGravity());
}
}
