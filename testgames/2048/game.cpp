#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("2048", WIDTH, HEIGHT, 0);
  e.setColor(0xBB,0xAD,0xA0);
  grid.setDest(10, 10, 78, 78);
  grid.setColor(0xCD, 0xC0, 0xB4);
  l=r=u=d=0;
  for(int i=0; i<4; i++){ for(int j=0; j<4; j++){ tiles[i][j]=0;}}
  srand(e.getTicks());
  int start = rand() % 1 + 2;
  for(int i=0; i<start; i++) tiles[rand() % 3 + 0][rand() % 3 + 0]=2;
  start = rand() % 1 + 1;
  for(int i=0; i<start; i++) tiles[rand() % 3 + 0][rand() % 3 + 0]=4;
  loop();
}

Game::~Game() {
}

void Game::loop() {
  while(e.getRunning()) {
    input();
    update();
    draw();
    e.loop();
  }
}

void Game::draw() {
  drawGrid();
  //e.draw("test", 60, 50, 200, 205, 50, "/usr/share/vlc/skins2/fonts/FreeSans.ttf");
}

void Game::input() {
 i.logPress();
 if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
 l=r=u=d=0;
 if(i.checkKey(i.left)) l=1;
 if(i.checkKey(i.right)) r=1;
 if(i.checkKey(i.up)) u=1;
 if(i.checkKey(i.down)) d=1;
}

void Game::update() {
  if(d) {
    for(int i=0; i<4; i++){ for(int j=0; j<4; j++){
      if(tiles[i][j]==0 && j<4) {tiles[i][j+1]=tiles[i][j]; tiles[i][j]=0;}
    }}
  }
}

void Game::drawGrid() {
   for(int i=0; i<4; i++) {
      for(int j=0; j<4; j++) {
         grid.setDestCoord(10+(i*85), 10+(j*85));
	 if(tiles[i][j]==0) grid.setColor(0xCD, 0xC0, 0xB4);
	 if(tiles[i][j]==2) grid.setColor(0xEE, 0xE4, 0xDA);
	 if(tiles[i][j]==4) grid.setColor(0xED, 0xE0, 0xC8);
	 if(tiles[i][j]==8) grid.setColor(0xED, 0xE0, 0xC8);
	 if(tiles[i][j]==16) grid.setColor(0xF5, 0x95, 0x63);
	 if(tiles[i][j]==32) grid.setColor(0xF6, 0x7C, 0x5F);
	 if(tiles[i][j]==64) grid.setColor(0xFF, 0x4C, 0x2B);
	 if(tiles[i][j]==128) grid.setColor(0xEE, 0xD8, 0x6A);
	 if(tiles[i][j]==256) grid.setColor(0xEE, 0xD5, 0x57);
	 if(tiles[i][j]==512) grid.setColor(0xEF, 0xD2, 0x44);
	 if(tiles[i][j]==1024) grid.setColor(0xEB, 0xC4, 0x40);
	 if(tiles[i][j]==2048) grid.setColor(0xEC, 0xC1, 0x2E);
	 if(tiles[i][j]==4096) grid.setColor(255, 61, 60);
	 if(tiles[i][j]>4096) grid.setColor(255, 30, 30);
	 e.draw(grid);
      }
   }
}




