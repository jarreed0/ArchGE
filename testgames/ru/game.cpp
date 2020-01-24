#include "game.h"

Game::Game() {
  e.debugMode(true);
  drawMenu=0;
  menum=0;
  e.init("Round Up Demo", WIDTH, HEIGHT, 0);
  e.setColor(32,32,32);
  phone.setImage("res/phone.png", e.getRenderer());
  phone.setFrame(0, 0, WIDTH, HEIGHT);
  phone.setDest(0,0,WIDTH,HEIGHT);
  map=phone;
  map.setImage("res/map.png", e.getRenderer());
  fc.setImage("res/fc.png", e.getRenderer());
  fc.setFrame(0,0,702,702);
  fc.setDest(50,150,72,72);
  mc.setImage("res/mc.png", e.getRenderer());
  mc.setFrame(0,0,398,398);
  mc.setDest(292,478,52,52);
  settings.setImage("res/settings.png", e.getRenderer());
  settings.setFrame(0,0,256,256);
  settings.setDest(298,30,32,32);
  e.loadFont("res/Sans.ttf");
  button.setImage("res/button.png", e.getRenderer());
  button.setFrame(0,0,760,186);
  button.setDest(WIDTH/2-100,HEIGHT-90,200,50);
  looking="Looking For...";
  m.setImage("res/menu-looking.png", e.getRenderer());
  m.setFrame(0,0,300,354);
  m.setDest(50,100,WIDTH-100,HEIGHT-200);
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
 e.draw(map);
 e.draw(fc);
 e.draw(mc);
 e.draw(settings);
 e.draw(button);
 e.draw(looking, WIDTH/2-50, HEIGHT-75, 0,0,0);
 if(drawMenu) menu();
 /*if(menum==1) e.draw(looking,WIDTH/2-50,140,0,0,0);
 if(menum==2) e.draw("FatCats",WIDTH/2-45,140,0,0,0);
 if(menum==3) e.draw("McDonalds",WIDTH/2-50,140,0,0,0);*/
 e.draw(phone);
}

void Game::input() {
 i.logPress();
 if(i.checkKey(i.esc) || i.checkKey(i.quit)) e.setRunning(false);
 if(i.checkKey(i.mouseleft)) {
  mouse.setDest(i.getMouseX(), i.getMouseY(), 25, 25);
  if(col.contains(button, mouse)) { drawMenu=1;  m.setImage("res/menu-looking.png", e.getRenderer());

  } else if(col.contains(fc, mouse)) { drawMenu=1;  m.setImage("res/menu-fc.png", e.getRenderer());

  } else if(col.contains(mc, mouse)) { drawMenu=1;  m.setImage("res/menu-mc.png", e.getRenderer());

  } else {
   drawMenu=0;
   menum=0;
  }
 }
}

void Game::menu() {
 e.draw(m);
}

void Game::update() {
}

