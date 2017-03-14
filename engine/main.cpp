#include "engine.h"
using namespace std;

int main() {
 Engine e;
 e.bypassSplash(4231998);
 e.init("test", 300, 400, 0);
 e.setColor(0x00, 0xff, 0x80);
 bool running = 1;
 int x = 0;
 e.setBackground("/home/avery/Desktop/ArchGE(old_copies)/ArchGE_10/engine/res/engine-logo.png");
 while(running) {
  if(x>10000) running=false;
  bool frame = true;
  while(frame) {
   e.update();
   x++;
   if(!e.FPS()) frame=false;
  }
  e.render();
 }
 return 0;
}
