h#include "game.h"

Game::Game() : level(TOTAL_TILES) {
  i.logPress();
  e.bypassSplash(4231998);
  e.customSplash("res/splash.bmp", 3, 600, 111);
  e.init(TITLE, WIDTH, HEIGHT, 0);
  level.centerCamera(80);
  level.setWindowSize(WIDTH, HEIGHT);
  loadLevel();
  level.setSolid(6);
  level.setSolid(38);
  level.setSolid(44);
  e.setColor(0x00, 0x77, 0x89);
  running = true;
  mm=0;
  player.setSource(0, 0, 24, 32);
  player.setImage("res/player.bmp", e.renderScreen());
  player.setDest(24, 32);
  player.center(WIDTH, HEIGHT);
  pRight = player.createNewFrameSet(1, 1, 1, 24, 32);
  pLeft  = player.createNewFrameSet(1, 2, 1, 24, 32);
  player.setCurFrameSet(pLeft);
  visible = true;
  del = uel = false;
  ver = hor = 0;
  falling = true;
  loop();
}

Game::~Game() {
  e.deconstruct();
}

void Game::loop() {
  while(running) {
    e.loopStart();
    bool frame = true;
    while(frame) {
      e.update();
    if(falling) {
      ver=-SPEED;
    } else {
      ver=0;
    }
    falling=1;
    level.move(hor, ver);
    hor=ver=0;
    input();
    draw();
      if(!e.FPS()) frame=false;
    }
    e.render();
  }
}

void Game::draw() {
  disp = level.getTilesToRender(16, 16);
  for(int i = 0; i < disp.size(); i++) {
    e.pushToScreen(disp[i]);
    if(col.isTouching(player, disp[i])) {
      //colliding
      bool elstop = false;
      if(disp[i].getSolid()) { //solid object, unpassable
        falling=0;
      }
      if(disp[i].getValue() == 22 || disp[i].getValue() == 23 || disp[i].getValue() == 28 || disp[i].getValue() == 29) {
        uel = true;
        elstop = true;
        ecount++;
      } else if(disp[i].getValue() == 34 or disp[i].getValue() == 35 or disp[i].getValue() == 40 or disp[i].getValue() == 41) {
        del = true;
        elstop = true;
        ecount++;
      } else {
        //del = false;
        //uel = false;
      }
      if(elstop) {
        if(level.getY() < ely) {
          ver=0;
          visible=true;
        }
      }
    }
  }
  if(visible) e.pushToScreen(player);
}

void Game::input() {
  i.logPress();
  //i.reset();
  if(running) {
    if(i.checkKey(i.left)) { level.move(-SPEED, 0); player.setCurFrameSet(pLeft); }
    if(i.checkKey(i.right)) { level.move(SPEED, 0); player.setCurFrameSet(pRight); }
    if(i.checkKey(i.up)) {
      if(uel) ver=SPEED; ely=level.getY(); uel=del=false; visible=false;
      if(del) ver=-SPEED; ely=level.getY(); uel=del=false; visible=false;
    }
    if(i.checkKey(i.down)) level.move(0, -SPEED);
    if(i.checkKey(i.quit)) { running = false; cout << "quit\n"; }
    if(i.checkKey(i.esc)) { running = false; cout << "esc\n"; }
    if(i.checkKey(i.r)) loadLevel();
    if(i.checkKey(i.mousemiddle)) { if(mm) {mm=0;} else {mm=1;} }
    if(i.checkKey(i.c)) { cout.precision(100000); cout << "(" << level.getX() << ", " << level.getY() << ")\n"; }
    if(i.checkKey(i.e)) { disp.clear(); level.loadMaps("tile", "res/level.tileset", "res/wall.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, 2, 6, 12); }
    if(mm) mouseMove();
  }
}

void Game::loadLevel() {
  disp.clear();
  level.loadMaps("tile", "res/building.tileset", "res/wall.bmp", e.renderScreen(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/6, 6, TOTAL_TILES);
}

void Game::mouseMove() {
  if(i.mousey < 40) {
    level.move(0, 1);
  }
  if(i.mousey > HEIGHT-40) {
    level.move(0, -1);
  }
  if(i.mousex < 40) {
    level.move(-1, 0);
  }
  if(i.mousex > WIDTH-40) {
    level.move(1, 0);
  }
}
