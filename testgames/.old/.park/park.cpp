#include "park.h"

Park::Park() {
 window.init(WINDOW_WIDTH, WINDOW_HEIGHT, 0);
 //player.setImage("res/player.bmp", window.renderScreen());
 //coin.setImage("res/coin.bmp", window.renderScreen());
 int grassAmount = window.random(10, 50);
 for(int i; i<grassAmount; i++) {
  Object grasstmp;
  grasstmp.setImage("res/grass.bmp", window.renderScreen());
  grasstmp.setSource(0, 0, 45, 45);
  grasstmp.setDest(i*window.random(8, 14), i*window.random(3, 19));
  grasstmp.setAng(window.random(0, 30));
  grass.push_back(grasstmp);
 }
}
Park::~Park() {
 window.deconstruct();
}
int Park::start() {
  for (auto done = false; !done;) {
    handle.logPress();
    if(handle.checkKey(handle.quit)) done = true;;
    if(handle.checkKey(handle.esc)) done = true;
    window.setColor(0x00, 0x38, 0x19);
    window.preLoop();
    draw();
    window.endLoop();
  }
  return 0;
}
void Park::draw() {
 for(int i; i<grass.size(); i++) {
  window.pushToScreen(grass[i]);
 }
}
