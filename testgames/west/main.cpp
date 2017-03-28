#include <arch/arch.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
 Engine e;
 e.debugMode(true);
 e.init("West", 500, 300, 0);
 e.setColor(0x32, 0x88, 0x72);
 e.exitOnEscape(true);
 while(e.getRunning()) {
  e.loopStart();
  e.update();
 }
 e.render();
}
