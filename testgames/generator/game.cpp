#include "game.h"

Game::Game() {
  cout << "Currently only generates a single screen and loops it it forever when going right and down and repeats it once when going up and left.\nSoon it will be infinitely generated in all directions.";
  setSeed(static_cast<int>(time(0)));
  cout << "Pass in seed as arguments\n";
  ifstream f("seeds.txt");
  if(f.is_open()) cout << f.rdbuf();
  //loop();
}

void Game::loop() {
  e.debugMode(true);
  e.init("Generator", WIDTH, HEIGHT, 0);
  e.setColor(0x00, 0x00, 0xff);
  //setSeed(1491006756);
  //setSeed(1491010706);
  //setSeed(1491012920);
  //setSeed(1491012761);
  //setSeed(1491013324);
  //setSeed(1491013842);
  cout << "Seed: " << seed << endl;
  noise.SetRandomSeed(rand() % 10);
  noise.SetPersistence(rand() % 10);
  noise.SetFrequency(rand() % 10);
  noise.SetAmplitude(rand() % 10);
  noise.SetOctaves(rand() % 10);
  x=y=0; int count; max=0;
  for(int i=0; i<(WIDTH/SIZE); i++) {
    vector<Object> tmpvec;
    for(int j=0; j<(HEIGHT/SIZE); j++) {
      Object tmpo;
      tmpo.setDest(i*SIZE, j*SIZE, SIZE, SIZE);
      tmpo.setColor(tmpo.blue);
      tmpvec.push_back(tmpo);
      int h = noise.GetHeight(i, j);
      if(h > max) max = h;
      ground += h;
      count++;
    }
    land.push_back(tmpvec);
  }
  ground=ground/count;
  while(e.getRunning()) {
    input();
    update();
    draw();
    e.loop();
  }
}

void Game::draw() {
  e.draw(land);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.esc) || (i.checkKey(i.quit))) e.setRunning(false);
  if(i.checkKey(i.w)) y+=SPEED;
  if(i.checkKey(i.s)) y-=SPEED;
  if(i.checkKey(i.a)) x+=SPEED;
  if(i.checkKey(i.d)) x-=SPEED;
}

void Game::update() {
  //float snowcap = 2.5*(((max-ground)/9.9)+ground);
  float snowcap = ground*10;
  for(int i=0; i<land.size(); i++) {
    for(int j=0; j<land[i].size(); j++) {
      int gx = i; int gy = j;
      land[i][j].setDestCoord(x+(i*SIZE),y+(j*SIZE));
      if(land[i][j].getDestX()<0) { gx=(((abs(land[i][j].getDestX()/WIDTH))+1)*WIDTH)/SIZE; land[i][j].moveDestX(gx*SIZE);}
      if(land[i][j].getDestY()<0) { gy=(((abs(land[i][j].getDestY()/HEIGHT))+1)*HEIGHT)/SIZE; land[i][j].moveDestY(gy*SIZE); }
      if(land[i][j].getDestX()>WIDTH) {  gx=(-((0)+1)*WIDTH)/SIZE; land[i][j].moveDestX(gx*SIZE); }
      if(land[i][j].getDestY()>HEIGHT) { gy=(-((0)+1)*HEIGHT)/SIZE; land[i][j].moveDestY(gy*SIZE); }
      float height = noise.GetHeight(i, j);
      //cout << height << endl;
      if(height > snowcap) {
       //land[i][j].setColor(255,255,255);
       land[i][j].setColor(0, 46, 37);
      } else if(inRange(height, 0-(ground*4), ground*4)) {
       //land[i][j].setColor(land[i][j].green);
       land[i][j].setColor(76, 70, 50);
      } else {
       //land[i][j].setColor(land[i][j].blue);
       land[i][j].setColor(0, 47, 75);
      }
    }
  }
}


bool Game::inRange(int p, int s, int e) {
  if(p >= e && p <= s) {
    return true;
  }
  return false;
}
