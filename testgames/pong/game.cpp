#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.init("Pong", WIDTH, HEIGHT, 0);
  cout << "arrows to move\nz to boost\n" << SCORETOWIN << " points to win\na and s to (de)activate ai\np and o to change ball size\nl and k to (un)pause" << endl;
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
    tmp.setDestSize(4, 4);
    tmp.setDestCoord(cos(i) * 80 + (WIDTH/2)-(tmp.getDestW()*1.5), sin(i) * 80 + (HEIGHT/2)-(tmp.getDestH()/2));
    tmp.setColor(255,255,255);
    scoreboard.push_back(tmp);
  }
  ai=false;
  paused=false;
  p=0;
  spawnball();
  loop();
}

Game::~Game() {
}

void Game::loop() {
  while(e.getRunning()) {
    input();
    if(!paused) update();
    draw();
    e.loop();
  }
}

void Game::draw() {
 if(boost) e.draw(staticBoostMeter);
 e.draw(boostMeter);
 e.draw(boostBar);
 if(boost2) e.draw(staticBoostMeter2);
 e.draw(boostMeter2);
 e.draw(boostBar2);
 e.draw(hittrack);
 e.draw(track);
 e.draw(hitscoreboard);
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
 boost=boost2=false;
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
 if(i.checkKey(i.l)) paused=true;
 if(i.checkKey(i.k)) paused=false;
 if(i.checkKey(i.z)) boost=true;
 if(i.checkKey(i.a)) ai=true;
 if(i.checkKey(i.s)) ai=false;
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
 if(col.isTouching(ball, paddle) && xballspeed<0) { xballspeed=-xballspeed-(xballspeed/10); bhitball=true; bhitpaddle=true; if(p!=0) {yballspeed+=(yballspeed/100);} }
 if(col.isTouching(ball, paddle2) && xballspeed>0) { xballspeed=-xballspeed-(xballspeed/10); bhitball=true; bhitpaddle2=true; yballspeed+=(yballspeed/100);}
 if(ball.getDestX() < 0) { xballspeed = SPEED*2; score2++; scoreboard[score2-1+SCORETOWIN].setColor(scoreboard[0].red); cout << score << " - " << score2 << endl; bhitball=true; }
 if(ball.getDestX()+ball.getDestW() > WIDTH) { xballspeed=SPEED*2; xballspeed=-xballspeed; score++; scoreboard[score-1].setColor(scoreboard[0].blue); cout << score << " - " << score2 << endl; bhitball=true; }
 if(ball.getDestY() < 0 || ball.getDestY()+ball.getDestH() > HEIGHT) { yballspeed=-yballspeed-(yballspeed/50); bhitball=true; }
 if(paddle.getDestY() < 0 || paddle.getDestY()+paddle.getDestH() > HEIGHT) paddle.setDest(paddle.getBuff());
 
 if(boost && boostBar.getDestW()>0) {
   int pad2mov = 0;
   int pad2mid = paddle.getDestY()+(paddle.getDestH()/2);
   int balldest = (yballspeed/xballspeed)*(pad2mid)+ball.getDestY();
   if(balldest > pad2mid) pad2mov = SPEED*6;
   if(balldest < pad2mid) pad2mov = -SPEED*6;
   paddle.moveDestY(pad2mov);
   boostCount--;
   if(boostBar.getDestW()>0)boostBar.setDestW(boostBar.getDestW()-(boostBarSize/100));
 }

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

 hitscoreboard.clear();
 for(int i=0; i<scoreboard.size(); i++) {
   Object tmp = scoreboard[i];
   tmp.setDest(tmp.getDestX()-3,tmp.getDestY()-3,10,10);
   tmp.setColor(200,255,200);
   tmp.setPos(tmp.getDest());
   if(col.isTouching(ball,tmp)) hitscoreboard.push_back(tmp);
 }

/*paddle2.setVelTo(ball);
 paddle2.moveDestY(paddle2.getVelY());*/
 //paddle2.setDestY(ball.getDestY()-((paddle2.getDestH()-ball.getDestH())/2));

 int pad2mov = 0;
 int pad2mid = paddle2.getDestY()+(paddle2.getDestH()/2);
 int balldest = (yballspeed/xballspeed)*(pad2mid)+ball.getDestY();
 if(balldest > pad2mid) pad2mov = SPEED;
 if(balldest < pad2mid) pad2mov = -SPEED;
 if(balldest > (pad2mid+paddle2.getDestH()) && (ball.getDestX()> (WIDTH-(3*(WIDTH/4))) )) boost2=true;
 if(balldest < (pad2mid-paddle2.getDestH()) && (ball.getDestX()> (WIDTH-(3*(WIDTH/4))) )) boost2=true;
 paddle2.moveDestY(pad2mov);

 if(paddle2.getDestY() < 0) paddle2.setDestY(0);
 if(paddle2.getDestY()+paddle2.getDestH() > HEIGHT) paddle2.setDestY(HEIGHT-paddle.getDestH());

 if(ai) {
 pad2mov = 0;
 pad2mid = paddle.getDestY()+(paddle.getDestH()/2);
 balldest = -(yballspeed/xballspeed)*(pad2mid)+ball.getDestY();
 if(balldest > pad2mid) pad2mov = SPEED;
 if(balldest < pad2mid) pad2mov = -SPEED;
 if(balldest > (pad2mid+paddle.getDestH()) && (ball.getDestX()> ((3*(WIDTH/4))) )) boost=true;
 if(balldest < (pad2mid-paddle.getDestH()) && (ball.getDestX()> ((3*(WIDTH/4))) )) boost=true;
 paddle.moveDestY(pad2mov);
 }

 if(boost2 && boostBar2.getDestW()>0) {
   int pad2mov = 0;
   int pad2mid = paddle2.getDestY()+(paddle2.getDestH()/2);
   int balldest = (yballspeed/xballspeed)*(pad2mid)+ball.getDestY();
   if(balldest > pad2mid) pad2mov = SPEED*6;
   if(balldest < pad2mid) pad2mov = -SPEED*6;
   paddle2.moveDestY(pad2mov);
   boostCount2--;
   if(boostBar2.getDestW()>0){ boostBar2.setDestW(boostBar2.getDestW()-(boostBarSize2/100)); boostBar2.moveDestX((2*boostBarSize2/100)); }
 }

 if(paddle2.getDestY() < 0 || paddle2.getDestY()+paddle2.getDestH() > HEIGHT) paddle2.setDest(paddle2.getBuff());
 if(yballspeed>8)yballspeed=8;
 if(yballspeed<-8)yballspeed=-8;
 if(xballspeed>24)xballspeed=24;
 if(xballspeed<-24)xballspeed=-24;
 if(score >= SCORETOWIN || score2 >= SCORETOWIN) spawnball();

}
void Game::spawnball() {
 xballspeed = SPEED*2;
 yballspeed = -SPEED/2;
 ball.setDestSize(10, 10);
 ball.center(WIDTH, HEIGHT);
 for(int i=0; i<scoreboard.size(); i++) {
   scoreboard[i].setColor(255,255,255);
   Object tmp = scoreboard[i];
   tmp.setDest(tmp.getDestX()-8,tmp.getDestY()-8,30,30);
   if(score>=SCORETOWIN) tmp.setColor(200,200,255);
   if(score>=SCORETOWIN) tmp.setColor(255,200,200);
   tmp.setPos(tmp.getDest());
   hitscoreboard.push_back(tmp);
 }
 score=score2=0;
 cout << score << " - " << score2 << endl;
 ball.setColor(ball.green);
 resetBoost();
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

void Game::resetBoost() {
  boost=boost2=false;
  boostCount=100;
  boostMeter.setDest(10,10,115,18);
  boostMeter.setColor(120,120,140);
  boostBar.setDestCoord(boostMeter.getDestX()+(boostMeter.getDestW()*.04), boostMeter.getDestY()+(boostMeter.getDestH()*.15));
  boostBar.setDestSize(boostMeter.getDestW()-(2*boostBar.getDestX())+(2*boostMeter.getDestX()),boostMeter.getDestH()-(2*boostBar.getDestY())+(2*boostMeter.getDestY()));
  boostBar.setColor(100,100,255);
  boostBarSize=boostBar.getDestW();
  staticBoostMeter = boostMeter;
  staticBoostMeter.moveDest(-3,-3);
  staticBoostMeter.setDestSize(boostMeter.getDestW()+6,boostMeter.getDestH()+6);
  staticBoostMeter.setColor(60,60,255);
  boostCount2=100;
  boostMeter2.setDest(WIDTH-115-10,10,115,18);
  boostMeter2.setColor(140,120,120);
  boostBar2.setDestCoord(boostMeter2.getDestX()+(boostMeter2.getDestW()*.04), boostMeter2.getDestY()+(boostMeter2.getDestH()*.15));
  boostBar2.setDestSize(boostMeter2.getDestW()-(2*boostBar2.getDestX())+(2*boostMeter2.getDestX()),boostMeter2.getDestH()-(2*boostBar2.getDestY())+(2*boostMeter2.getDestY()));
  boostBar2.setColor(255,100,100);
  boostBarSize2=boostBar2.getDestW();
  staticBoostMeter2 = boostMeter2;
  staticBoostMeter2.moveDest(-3,-3);
  staticBoostMeter2.setDestSize(boostMeter2.getDestW()+6,boostMeter2.getDestH()+6);
  staticBoostMeter2.setColor(255,60,60);
}






