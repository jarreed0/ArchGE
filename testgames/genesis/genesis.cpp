#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  engine.bypassSplash(4231998);
  running=true;
  engine.setBackground("res/bkg.bmp");
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.center(WIDTH, HEIGHT);
  engine.setColor(0x9f, 0x9f, 0x9f);
  map.setWindowSize(WIDTH, HEIGHT);
  map.setCameraMargin(75, 75);
  map.setLensMargin(15, 15);
  engine.preLoop();
  input.reset();
  vector<Tile> tmp1, tmp2;
  tmp1 = map.loadMaps("wall", "res/avery.wall", "res/wall.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 7);
  tmp2 = map.loadMaps("blocks", "res/avery.map", "res/blocks.bmp", engine.renderScreen(), TILE_SIZE, TILE_SIZE, 1, 22);
  speed = 5;
  start();
}
Genesis::~Genesis() {
  engine.deconstruct();
}
void Genesis::start() {
  while(running) {
    checkInput();
    engine.preLoop();
    draw();
    engine.endLoop();
  }
}
void Genesis::draw() {
  engine.pushToScreen(background);
  tiles = map.getTilesToRender();
  for(int i = 0; i<tiles.size(); i++) { engine.pushToScreen(tiles[i]); }
  engine.pushToScreen(player);
  Object k = map.getCamera();
  //Object l = map.getLens();
  //Object l;
  //k.setImage("res/bkg.bmp", engine.renderScreen());
  //k.setSource(0, 0, k.getDW(), k.getDH());
  //k.setDest(WIDTH-75-75, HEIGHT-75-75, 75, 75);
  //engine.pushToScreen(k);
  //l.setImage("res/bkg.bmp", engine.renderScreen());
  //l.setDest(WIDTH-75-75-25-25, HEIGHT-75-75-25-25, k.getDX(), k.getDY());
  //l.setSource(0, 0, 90, 90);
  //engine.pushToScreen(l);
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.right)) {
    player = map.move(speed, 0, player);
  }
  if(input.checkKey(input.left)) {
    player = map.move(-speed, 0, player);
  }
  if(input.checkKey(input.up)) {
    player = map.move(0, speed, player);
  }
  if(input.checkKey(input.down)) {
    player = map.move(0, -speed, player);
  }
  if(input.checkKey(input.quit)) { running=false; cout << "quit" << endl; }
  if(input.checkKey(input.esc)) { running=false; cout << "esc" << endl; }
}
