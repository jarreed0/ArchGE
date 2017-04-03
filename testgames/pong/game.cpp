#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Pong", WIDTH, HEIGHT, 0);
  e.setFrameRate(60);
  e.setColor(0,0,0);
  paddle.setDestSize(10, 90);
  paddle.center(WIDTH,HEIGHT);
  paddle.setDestX(10);
  paddle.setColor(paddle.blue);
  paddle2.setDest(paddle.getDest());
  paddle2.setDestX(WIDTH-paddle.getDestX()-paddle2.getDestW());
  paddle2.setColor(paddle2.red);
  hitball.setColor(150,255,150);
  hitpaddle.setColor(150,150,255);
  hitpaddle2.setColor(255,150,150);
  bhitball=bhitpaddle=bhitpaddle2=false;
  for(int i = 0; i<12; i++) {
    Object tmp;
    tmp.setDestSize(3, 16);
    tmp.center(WIDTH, HEIGHT);
    tmp.setDestY((i*tmp.getDestH())+(tmp.getDestH()*i));
    tmp.setColor(255,255,255);
    track.push_back(tmp);
  }
  for(int i = 0; i<SCORETOWIN*2; i++) {
    Object tmp;
    tmp.setDest((WIDTH/2)+(i*15), (HEIGHT/2)+sqrt(pow(20,2)-pow((i*15),2)), 10, 10);
    tmp.setColor(0,20,80);
    scoreboard.push_back(tmp);
  }
  p=0;
  spawnball();
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
 e.draw(hittrack);
 e.draw(track);
 //e.draw(hitscoreboard);
 e.draw(scoreboard);
 e.draw(paddle);
 e.draw(paddle2);
 if(bhitpaddle) {
   configpaddlehit();
   e.draw(hitpaddle);
 }
 if(bhitpaddle2) {
   configpaddle2hit();
   e.draw(hitpaddle2);
 }
 if(bhitball) {
   configballhit();
   e.draw(hitball);
 }
 e.draw(ball);
}

void Game::input() {
 bool move=0;
 i.logPress();
 if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
 if(i.checkKey(i.up)) { p=1; move=1; }
 if(i.checkKey(i.down)) { p=2; move=1; }
 if(!move) p=0;
 if(i.checkKey(i.o)) ball.setDestSize(ball.getDestW()-1, ball.getDestH()-1);
 if(i.checkKey(i.p)) ball.setDestSize(ball.getDestW()+1, ball.getDestH()+1);
}

void Game::update() {
 bhitball=bhitpaddle=bhitpaddle2=false;
 if(p==1) {
  paddle.moveDestY(-SPEED);
 }
 if(p==2) {
  paddle.moveDestY(SPEED);
 }
 ball.moveDest(xballspeed, yballspeed);
 ball.setPos(ball.getDest()); paddle.setPos(paddle.getDest()); paddle2.setPos(paddle2.getDest());
 if(col.isTouching(ball, paddle) && xballspeed<0) { xballspeed=-xballspeed-(xballspeed/10); bhitball=true; bhitpaddle=true; }
 if(col.isTouching(ball, paddle2) && xballspeed>0) { xballspeed=-xballspeed-(xballspeed/10); bhitball=true; bhitpaddle2=true; }
 if(ball.getDestX() < 0) { xballspeed = SPEED*2; score2++; cout << score << " - " << score2 << endl; bhitball=true; }
 if(ball.getDestX()+ball.getDestW() > WIDTH) { xballspeed=SPEED*2; xballspeed=-xballspeed; score++; cout << score << " - " << score2 << endl; bhitball=true; }
 if(ball.getDestY() < 0 || ball.getDestY()+ball.getDestH() > HEIGHT) { yballspeed=-yballspeed-(yballspeed/10); bhitball=true; }
 if(paddle.getDestY() < 0 || paddle.getDestY()+paddle.getDestH() > HEIGHT) paddle.setDest(paddle.getBuff());
 
 hittrack.clear();
 for(int i=0; i<track.size(); i++) {
  Object tmp = track[i];
  tmp.setPos(tmp.getDestX()-3, tmp.getDestY()-3, tmp.getDestW()+3, tmp.getDestH()+3);
  if(col.isTouching(ball, tmp)) {
    tmp.setDestSize(16, 29);
    tmp.moveDest(-6,-6);
    if(xballspeed > 0) tmp.setColor(0,100,200);
    if(xballspeed < 0) tmp.setColor(250,50,0);
    hittrack.push_back(tmp);
  }
 }

/*paddle2.setVelTo(ball);
 paddle2.moveDestY(paddle2.getVelY());*/
 //paddle2.setDestY(ball.getDestY()-((paddle2.getDestH()-ball.getDestH())/2));

 int pad2mov = 0;
 int pad2mid = paddle2.getDestY()+(paddle2.getDestH()/2);
 int balldest = (yballspeed/xballspeed)*(pad2mid)+ball.getDestY();
 if(balldest > pad2mid) pad2mov = SPEED;
 if(balldest < pad2mid) pad2mov = -SPEED;
 paddle2.moveDestY(pad2mov);

 if(paddle2.getDestY() < 0 || paddle2.getDestY()+paddle2.getDestH() > HEIGHT) paddle2.setDest(paddle2.getBuff());
 if(yballspeed>8)yballspeed=8;
 if(yballspeed<-8)yballspeed=-8;
 if(xballspeed>24)xballspeed=24;
 if(xballspeed<-24)xballspeed=-24;
 if(score >= SCORETOWIN || score2 >= SCORETOWIN) spawnball();
}

void Game::spawnball() {
 xballspeed = SPEED*2;
 yballspeed = SPEED/2;
 ball.setDestSize(10, 10);
 ball.center(WIDTH, HEIGHT);
 score=score2=0;
 cout << score << " - " << score2 << endl;
 ball.setColor(ball.green);
}

void Game::configballhit() {
 hitball.setDestSize(ball.getDestW()*2.5,ball.getDestH()*2.5);
 hitball.setDestCoord(ball.getDestX()-((hitball.getDestW()-ball.getDestW())/2),ball.getDestY()-((hitball.getDestH()-ball.getDestH())/2));
}

void Game::configpaddlehit() {
 hitpaddle.setDestSize(paddle.getDestW()*1.4, paddle.getDestH()*1.2);
 hitpaddle.setDestCoord(paddle.getDestX()+((paddle.getDestW()-paddle.getDestW())/10),paddle.getDestY()-((hitpaddle.getDestH()-paddle.getDestH())/2));
}

void Game::configpaddle2hit() {
 hitpaddle2.setDestSize(paddle2.getDestW()*1.4, paddle2.getDestH()*1.2);
 hitpaddle2.setDestCoord(paddle2.getDestX()-((paddle2.getDestW()-paddle2.getDestW())/10)-paddle2.getDestW(),paddle2.getDestY()-((hitpaddle2.getDestH()-paddle2.getDestH())/2));
}






