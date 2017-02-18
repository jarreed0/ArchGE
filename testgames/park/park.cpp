#include "park.h"

Park::Park() {
 window.init(WINDOW_WIDTH, WINDOW_HEIGHT, 0);
 //player.setImage("res/player.bmp", window.renderScreen());
 //coin.setImage("res/coin.bmp", window.renderScreen());
 grass.setSource(0, 0, 45, 45);
 int grassAmount = rand()%(50-10+1)+50;
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

}
