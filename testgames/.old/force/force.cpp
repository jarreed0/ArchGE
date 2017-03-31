#include "force.h"

Force::Force() {
  e.debugMode(true);
  e.init(TITLE, WIDTH, HEIGHT, 0);
  e.exitOnEscape(true);
  i.logPress();
  loadLevels();
  level.setScreenSize(WIDTH, HEIGHT);
  e.setColor(0x10, 0x01, 0x88);
  running = true;
  player.setFrame(0, 0, 24, 32);
  player.setImage("res/player.bmp", e.getRenderer());
  player.setDestSize(24, 32);
  player.center(WIDTH, HEIGHT);
  //pRight = player.createNewFrameSet(2, 1, 1, 24, 32);
  //pLeft = player.createNewFrameSet(2, 2, 1, 24, 32);
  //player.setCurFrameSet(pLeft);
  falling = jumping = false;
  jumpCount=0;
  loop();
}

Force::~Force() {
  //e.deconstruct();
}

void Force::loop() {
  while(e.getRunning()) {
    e.loopStart();
    e.update();
    input();
    if(falling) {
      level.move(0, -SPEED);
    }
    draw();
    e.render();
  }
}

void Force::draw() {
  disp = level.getTilesToRender();
  //disp = level.tilesToRender();
  bool colliding = false;
  player.setPos(player.getDest());
  for(int i = 0; i < disp.size(); i++) {
    e.draw(disp[i]);
    disp[i].setPos(disp[i].getDest());
    if(col.isTouching(player, disp[i])) {
      colliding = true;
    }
    if(moveRight) {
      Entity p = player;
      p.move(SPEED, SPEED);
      if(col.isTouching(p, disp[i]) && disp[i].getValue() != 42) {
        moveRight=false;
      }
    }
    if(moveLeft) {
      Entity p = player;
      p.move(-SPEED, SPEED);
      if(col.isTouching(p, disp[i]) && disp[i].getValue() != 42) {
        moveLeft=false;
      }
    }
  }
  falling = false;
  if(!colliding) {
    falling=true;
  }
  if(moveRight) level.move(SPEED, 0);
  if(moveLeft) level.move(-SPEED, 0);
  if(jumping) { level.move(0, SPEED); jumpCount++; falling=false; }
  if(jumpCount > 50) { jumpCount=0; jumping=false; }
  e.draw(player);
}

void Force::input() {
  i.logPress();
  moveLeft=moveRight=false;
  if(running) {
    if(i.checkKey(i.left)) {
      moveLeft = true;
      //player.setCurFrameSet(pLeft);
    }
    if(i.checkKey(i.right)) {
      moveRight = true;
      //player.setCurFrameSet(pRight);
    }
    if(i.checkKey(i.up)) { jumping=true; }
    //if(i.checkKey(i.down)) { level.move(0, -SPEED); }
  }
}

void Force::loadLevels() {
  disp.clear();
  //level.loadMaps("tile", "res/1.level", "res/tiles.bmp", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES); //
  Map map1;
  Tileset tileset;
  map1.loadMap("res/1.level");
  tileset.create("tiles", "res/tiles.bmp", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES);
  level.setStage(map1, tileset);
}
