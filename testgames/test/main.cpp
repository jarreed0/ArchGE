#include <arch/arch.h>
using namespace std;

int main() {
 Engine e;
 e.debugMode(true);
 e.init("test", 300, 400, 0);
 e.setColor(0x00, 0xff, 0x80);
 bool running = 1;
 Input i;
 e.setBackground("../../engine/res/engine-logo.png");
 while(running) {
  e.loopStart();
  bool frame = true;
  while(frame) {
   e.update();
   i.logPress();
   if(i.checkKey(i.esc) || i.checkKey(i.quit)) running = false;
   if(!e.FPS()) frame=false;
  }
  e.render();
 }
 return 0;
}
