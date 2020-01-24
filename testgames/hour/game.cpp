#include "game.h"

Game::Game() {
  //e.debugMode(true);

  /*SDL_DisplayMode DM;
  SDL_GetCurrentDisplayMode(0, &DM);
  WIDTH = DM.w;
  HEIGHT = DM.h;*/

  e.setSplashColor(255,51,255);
  e.init("Flappy Rocket", WIDTH, HEIGHT, 0);//SDL_WINDOW_FULLSCREEN);
  e.setColor(65, 65, 65);
  e.enableTransparency();
  e.setFrameRate(FRAMERATE);
  e.loadFont("res/Peepo.ttf");



  highscore=00;

  player.setImage("res/player.png", e.getRenderer());
  player.setFrame(0, 0, 31, 15);
  player.setDest(WIDTH/2-31, HEIGHT/2-15, 62, 30);
  triangleTemplate.setImage("res/triangle-glow.png", e.getRenderer());
  triangleTemplate.setFrame(0,0,TRIANGLE_W,TRIANGLE_H);
  top.setDest(0, 0, WIDTH, 10);
  top.setPos(top.getDest());
  bot.setDest(0, HEIGHT-10, WIDTH, 10);
  bot.setPos(bot.getDest());
  tr.setColor(100, 0, 0);
  tr.setDestSize(4, 4);
  smokeTemplate.setColor(100, 100, 100);
  flameTemplate.setColor(220, 20, 60);
  menu.setImage("res/menu.png", e.getRenderer());
  menu.setDest(0, 0, WIDTH, HEIGHT);
  menu.setFrame(0, 0, 10, 10);
  localX=localY=pauseTick=0;
  paused=true;
  start=true;
  cameraEnabled=0;

  shield=1;
  bubble.setImage("res/shield.png", e.getRenderer());
  bubble.setFrame(0,0,33,33);
  bubble.setDestSize(33*2.6, 33*2.6);
  bubble.setDestCoord(player.getDestX()-(player.getDestW()/4), player.getDestY()-(player.getDestH()));
  bubble.setAngle(player.getAngle());

  //startLevel();
  boost=score=deathCount=0;

  loop();
}

Game::~Game() {}

void Game::loop() {
  while(e.getRunning()) {
    input();
    pauseTick++;
    if(!paused) update();
    draw();
    e.loop();
  }
}

void Game::draw() {
  drawBackground();
  e.draw(player);
  if(shield) {
    bubble.setDestCoord(player.getDestX()-(player.getDestW()/4), player.getDestY()-(player.getDestH()));
    bubble.setAngle(player.getAngle());
    e.draw(bubble);
  }

  for(int i=0; i<triangle.size(); i++) {
    e.draw(triangle[i].t1);
    e.draw(triangle[i].t2);
    if((triangle[i].t1.getDestY() < 100)) {
      triangle[i].t1.moveDestY(FLIGHT);
      triangle[i].t2.moveDestY(FLIGHT);
    }
    if(triangle[i].t2.getDestY() > HEIGHT-100) {
      triangle[i].t1.moveDestY(-GRAVITY);
      triangle[i].t2.moveDestY(-GRAVITY);
    }
  }
  e.draw(to_string(score), WIDTH/2, 18, 250, 250, 250);
  e.draw(top);
  e.draw(bot);
  //e.draw(tr);
  e.draw(flame);
  e.draw(smoke);
  if(paused) {
    e.draw(menu);
    if(!start) {
      e.draw("Paused", WIDTH/2-25, HEIGHT/2-100, 255, 255, 255);
    } else {
      e.draw("Press UP ARROW or W To Begin!", WIDTH/2-160, HEIGHT/2-100, 255, 255, 255);
      string hs = "Highscore: ";
      hs+=to_string(highscore);
      e.draw(hs, WIDTH/2-80, HEIGHT/2-50, 255, 255, 255);
      e.draw("Press P To Pause", WIDTH/2-90, HEIGHT-68, 255, 255, 255);
    }
  }
  if(boost) {cameraEnabled=0;e.draw("HYPERDRIVE.", WIDTH/2-50, HEIGHT-68, 255, 255, 255);}
  if(cameraEnabled && count < 2) e.draw("RUN!", WIDTH/2-20, HEIGHT-68, 255, 255, 255);
}

void Game::input() {
  i.logPress();
  if(i.checkKey(i.p) && pauseTick>30) {paused = !paused; pauseTick=0;}
  if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
  if(i.checkKey(i.up) || i.checkKey(i.w)) {up=true;if(start && pauseTick>30){pauseTick=0;start=paused=0;startLevel(0);}}else{ up=false;}
  //if(i.checkKey(i.l)) cameraEnabled=!cameraEnabled;
}

void Game::update() {
  updatePlayer();
  generateMap();
  if(col.overlaps(top,player) || col.overlaps(bot, player)) die(-1);
  int Ox = player.getDestW() / 2;
  int Oy = player.getDestH() / 2;
  int x = player.getDestX();// + (Ox  * cos(0) - (Oy * sin(0)));
  int y = player.getDestY();// + (Ox  * sin(0) + (Oy * cos(0)));
  int theta = player.getAngle();
  if(theta < 0) theta = 360-theta;
  int x2 = Ox+(x-Ox)*cos(theta)+(y-Oy)*sin(theta);
  int y2 = Oy-(x-Ox)*sin(theta)+(y-Oy)*cos(theta);
  tr.setDestCoord(x2,y2);
  //tr.setDestCoord(Rx-tr.getDestW()-player.getDestW()/2, Ry-tr.getDestH()+(tr.getDestH()/2));
  //tr.moveDestY(-player.getAngle());
  smokeTrail();
  flameTrail();
  if(cameraEnabled)camera();
  localX=localY=0;
  if(count>=4 && !cameraEnabled) {
    cameraEnabled=1;
    count=0;
  } else if(cameraEnabled && count==5) {
    cameraEnabled=0;
    boost=1;
    count=0;
  } else if(boost && count>=WIDTH+player.getDestW()) {
    shield=1;
    boost=0;
    startLevel(score);
  }
  if(deathCount >= 6) cameraEnabled=0;
  if(score==40) deathCount=0;
  if(regenShield==50) {shield=1; regenShield=0; deathCount=0;}
}

void Game::updatePlayer() {
  if(up) {
    player.rotateAngle(-ROTATION);
  } else {
    player.rotateAngle(ROTATION);
  }
  changeColor();
  if(player.getAngle()>=45) player.setAngle(45);
  if(player.getAngle()<=-45) player.setAngle(-45);
  if(player.getAngle()>0 ) {
    if(deathCount < 8) {
      player.moveDestY(FLIGHT);localY+=FLIGHT;
    } else {
      player.moveDestY(FLIGHT-(FLIGHT/3));localY+=FLIGHT-(FLIGHT/3);
    }
  } else {
    if(deathCount < 8) {
      player.moveDestY(-GRAVITY);localY-=GRAVITY;
    } else {
      player.moveDestY(-GRAVITY/2);localY-=GRAVITY/2;
    }
  }
  //player.moveDestX(2);
  if(player.getDestX()>WIDTH) {player.setDestX(-player.getDestW());flame.clear();smoke.clear();}
  player.setPos(player.getDest());
}

void Game::generateMap() {
  for(int i=0; i<triangle.size(); i++) {
    /*for(int k=0; k<triangle.size(); k++) {
      if(triangle[i].t1.getDestX()==triangle[k].t1.getDestX() && i!=k) triangle.erase(triangle.begin()+k);
    }*/
    Object tmp;
    tmp.setColor(255,255,255);
    for(int k=0; k<TRIANGLE_W-22; k++) {
      tmp.setDest(triangle[i].t1.getDestX()+k/2+4,TRIANGLE_W+triangle[i].t1.getDestY()-k,2,2);
      if(col.overlaps(player,tmp)) {die(i); break;}
      //e.draw(tmp);
      tmp.setDest(k/2 + triangle[i].t2.getDestX() + 4,k+triangle[i].t2.getDestY(),2,2);
      //e.draw(tmp);
      if(col.overlaps(player,tmp)) {die(i);break;}
    }
    //if(player.getDestX()==(triangle[i].t1.getDestY()/2) && player.getDestY()==(triangle[i].t1.getDestX()*2))
    //if(col.overlaps(triangle[i].t1,player) || col.overlaps(triangle[i].t2, player)) startLevel();
    if(!boost && triangle[i].t1.getDestX()+triangle[i].t1.getDestW() < 0) {
      triangle.erase(triangle.begin()+i);
      makeTriangle();
    }
    if(triangle[i].t1.getDestX()+(TRIANGLE_W/2) <= (WIDTH/2)+(SPEED/2)
    && triangle[i].t1.getDestX()+(TRIANGLE_W/2) >= (WIDTH/2)-(SPEED/2)
    && triangle[i].scored==0) {//col.overlaps(tmp, player)) {
      score++;
      if(score>highscore) highscore=score;
      regenShield++;
      count++;
      triangle[i].scored=1;
    }
    if(deathCount < 8) {
      if(!cameraEnabled)triangle[i].t1.moveDestX(-SPEED);
      if(!cameraEnabled)triangle[i].t2.moveDestX(-SPEED);
    } else {
      if(!cameraEnabled)triangle[i].t1.moveDestX(-SPEED-(SPEED/3));
      if(!cameraEnabled)triangle[i].t2.moveDestX(-SPEED-(SPEED/3));
    }
    localX=SPEED;
    
    if(triangle[i].t1.getDestY() < 80) {triangle[i].t2.moveDestY(GRAVITY);triangle[i].t2.moveDestY(-GRAVITY);}
    if(triangle[i].t1.getDestY() > HEIGHT-8) {triangle[i].t2.moveDestY(-FLIGHT);triangle[i].t2.moveDestY(FLIGHT);}
  }
}

void Game::makeTriangle() {
  int r = TRIANGLE_W/(rand() % 4 + 2);// + (rand() % TRIANGLE_SIZE/2 + TRIANGLE_SIZE/2);
  int s = (rand() % TRIANGLE_H/3);
  if(deathCount>6) s=(rand() % TRIANGLE_H/2);
  int v = (rand() % 40 + 150);
  triangleTemplate.setAngle(0);
  triangleTemplate.setDestCoord(triangle[triangle.size()-1].t1.getDestX()-r+WIDTH, HEIGHT-s);
  columnTemplate.t1=triangleTemplate;
  triangleTemplate.setAngle(180);
  triangleTemplate.setDestCoord(triangle[triangle.size()-1].t1.getDestX()-r+WIDTH, columnTemplate.t1.getDestY()-TRIANGLE_H-v);
  columnTemplate.t2=triangleTemplate;
  triangle.push_back(columnTemplate);
}
void Game::startLevel(int s) {
  if(deathCount>10) {shield=true;deathCount=0;}

  smokeTemplate.setColor(100, 100, 100);
  flameTemplate.setColor(220, 20, 60);

  score=s;
  count=cameraEnabled=boost=0;
  player.setDest(WIDTH/2-31, HEIGHT/2-15, 62, 30);
  generateDust();
  triangle.clear();
  triangleTemplate.setAngle(0);
  triangleTemplate.setDest(WIDTH, HEIGHT-200, TRIANGLE_W, TRIANGLE_H);
  columnTemplate.t1=triangleTemplate;
  columnTemplate.scored=0;
  triangleTemplate.setAngle(180);
  triangleTemplate.setDestCoord(WIDTH, -400);
  columnTemplate.t2=triangleTemplate;
  triangle.push_back(columnTemplate);
  for(int i=0; i<10; i++) makeTriangle();
  r=b=255;
  g=51;
  purple=true;
  smoke.clear();
  green=blue=orange=false;
}

void Game::changeColor() {
  SDL_SetTextureColorMod(triangleTemplate.getImage().getTexture(), r, g, b);
  if(purple) { //255 51 255
    if(r>51) r--;
    if(g<255) g++;
    if(b>51) b--;
    if(r==51 && g==255 && b==51) {green=1;purple=blue=orange=0;}
  }
  if(green) { //51 255 51
    if(g>153) g--; 
    if(b<255) b++;
    if(b==255 && g==153) {blue=1;purple=green=orange=0;}
  }
  if(blue) { //51 153 255
    if(r<255) r++;
    if(b>51) b--;
    if(b==51 && r==255) {orange=1;purple=blue=green=0;}  
  }
  if(orange) { //255 153 51 
    if(g>51) g--;
    if(b<255) b++;
    if(r==255 && g==51 && b==255) {purple=1;orange=blue=orange=0;}
  }
  top.setColor(r,g,b);
  bot.setColor(r,g,b);

}

void Game::smokeTrail() {
  int s;
  if(smoke.size()<50) {
    smokeTemplate.setDest(player.getDest());
    s = (rand() % 8 + 10);
    smokeTemplate.setDestSize(s, s);
    smokeTemplate.moveDest(-25, (rand() % 50 - 25)-player.getAngle());
    if(player.getAngle()>0) smokeTemplate.moveDestY(-player.getDestH());
    if(player.getAngle()<0) smokeTemplate.moveDestY(player.getDestH());

  int Ox = player.getDestW() / 2;
  int Oy = player.getDestH() / 2;
  int Rx = player.getDestX() + (Ox  * cos(0) - (Oy * sin(0)));
  int Ry = player.getDestY() + (Ox  * sin(0) + (Oy * cos(0)));
  smokeTemplate.setDestCoord(Rx-tr.getDestW()-player.getDestW()/(1.1), Ry-tr.getDestH()+(tr.getDestH()/2));
  smokeTemplate.moveDestY(-player.getAngle()*2);
  if(boost) smokeTemplate.setColor(0,0,0);

    smokeTemplate.setAngle(rand() % 360);
    smoke.push_back(smokeTemplate);
  }
  for(int i=0; i<smoke.size(); i++) {
    smoke[i].moveDest(-1, (rand() % 10 - 5));
    s = (rand() % 6 - 2);
    smoke[i].rotateAngle(s);
    if(smoke[i].getDestW() >= 18 || smoke[i].getDestW() <= 4) s=0;
    smoke[i].setDestSize(smoke[i].getDestW()-s,smoke[i].getDestW()-s);
    if(smoke[i].getDestX()<WIDTH/3+20) smoke[i].setDestSize(smoke[i].getDestW()-1,smoke[i].getDestW()-1);//smoke.erase(smoke.begin()+i);
    if(smoke[i].getDestW()<=4) smoke.erase(smoke.begin()+i);
  }
}


void Game::flameTrail() {
  int s;
  if(flame.size()<30) {
    flameTemplate.setDest(player.getDest());
    s = (rand() % 8 + 3);
    flameTemplate.setDestSize(s, s);
    flameTemplate.moveDest(sin(abs(player.getAngle())), cos(abs(player.getAngle())));
    if(player.getAngle()>0) flameTemplate.moveDestY(-player.getDestH());
    if(player.getAngle()<=0) flameTemplate.moveDestY(player.getDestH());
    //flameTemplate.moveDest(0, (rand() % 24 - 12)-sin(player.getAngle()));

  int Ox = player.getDestW() / 2;
  int Oy = player.getDestH() / 2;
  int Rx = player.getDestX() + (Ox  * cos(0) - (Oy * sin(0)));
  int Ry = player.getDestY() + (Ox  * sin(0) + (Oy * cos(0)));
  flameTemplate.setDestCoord(Rx-tr.getDestW()-player.getDestW()/2, Ry-tr.getDestH()+(tr.getDestH()/2));
  flameTemplate.moveDestY(-player.getAngle());
  if(boost) flameTemplate.setColor(173,216,230);

    flameTemplate.setAngle(rand() % 360);
    flame.push_back(flameTemplate);
  }
  for(int i=0; i<flame.size(); i++) {
    flame[i].moveDest(-1, (rand() % 10 - 5));
    s = (rand() % 6 - 2);
    flame[i].rotateAngle(s);
    if(flame[i].getDestW() >= 18 || flame[i].getDestW() <= 4) s=0;
    flame[i].setDestSize(flame[i].getDestW()-s,flame[i].getDestW()-s);
    if(flame[i].getDestX()<WIDTH/3+60) flame[i].setDestSize(flame[i].getDestW()-1,flame[i].getDestW()-1);//flame.erase(flame.begin()+i);
    if(flame[i].getDestW()<=2) flame.erase(flame.begin()+i);
  }
}

void Game::camera() {
  if(player.getDestY()>HEIGHT/2-15) player.moveDestY(-FLIGHT*1.5);
  if(player.getDestY()<HEIGHT/2-15) player.moveDestY(GRAVITY*1.5);
  player.setDestX(WIDTH/2-31);

  for(int i=0; i<triangle.size(); i++) {
    //if(triangle[i].t2.getDestY()<100 && triangle[i].t1.getDestY()+TRIANGLE_H>HEIGHT-100) {
    if((triangle[i].t1.getDestY()+TRIANGLE_H > HEIGHT+100 && !up) || (triangle[i].t2.getDestY() < -100 && up)) {
      triangle[i].t1.moveDest(-localX*1.5, -localY*1.5);
      triangle[i].t2.moveDest(-localX*1.5, -localY*1.5);
    } else {
      triangle[i].t1.moveDestX(-localX*1.5);
      triangle[i].t2.moveDestX(-localX*1.5);
      //player.moveDestY(localY);
    }
    /*} else {
      //if(player.getDestY()<100 && player.getDestY()>HEIGHT-100) {
        player.moveDestY(localY);
      } else {
        triangle[i].t1.moveDestY(-localY);
      }
      triangle[i].t1.moveDestX(-localX);
      triangle[i].t2.moveDestX(-localX);
      break;
    }*/
  }
}

void Game::drawBackground() {
  for(int i=0; i<dust.size(); i++) {
    if(cameraEnabled) {
      if(!paused)dust[i].moveDestX(-dust[i].getSpeed()*2);
      dust[i].setColor(230, 100, 100);
    } else if(boost) {
      if(!paused)dust[i].moveDestX(-dust[i].getSpeed()*3);
      dust[i].setColor(250, 250, 0);
      player.moveDestX(1);
      triangle.clear();
      count+=.2;
    } else {
      if(!paused)dust[i].moveDestX(-dust[i].getSpeed());
      dust[i].setColor(200, 200, 200);
    }
    if(dust[i].getDestX() < 0) dust[i].setDestX(WIDTH);
    e.draw(dust[i]);
  }
}

void Game::generateDust() {
  dustTemplate.setColor(200, 200, 200);
  //int x=24;
  //int y=24;
  for(int i=0; i<24; i++) {
    int s = rand() % 10 + 2;
    dustTemplate.setDestSize(s, s);
    dustTemplate.setSpeed(rand() % 10 + 6);
    //for(int k=0; k<x; k++) {
      dustTemplate.setDestCoord(rand() % WIDTH, rand() % HEIGHT);
      dust.push_back(dustTemplate);
    //}
  }
}

void Game::die(int i) {
  if(!shield){paused=start=1;}
  else {
    shield=cameraEnabled=0;
    if(i != -1) triangle.erase(triangle.begin()+i);
    if(i == -1) player.setDest(WIDTH/2-31, HEIGHT/2-15, 62, 30);
  }
  deathCount++;
}

/*void Game::boostMode() {
  if(boost) {
    count++;
    boost=false;
    triangle.clear();
    int os;
    startLevel();
    score=os;
  }
}*/
