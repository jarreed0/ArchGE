#include <arch/arch.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
using namespace glm;

int main() {
 Engine e;
 e.debugMode(true);
 e.init("West", 500, 300, 0);
 e.setColor(0x32, 0x88, 0x72);
 e.exitOnEscape(true);
 while(e.getRunning()) {
  e.loopStart();
  //bool frame = true;
  //while(frame) {
   e.update();
   //if(!e.FPS()) frame=false;
  //}
 }
 e.render();
}
