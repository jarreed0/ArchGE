#include "arch.h"

/*
This is a test main function in order to test out the game engine mechanics.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/12/17
*/

int main() {
  Arch engine(320, 480, "Title"); //creates reference of engine and sets window specifications
  engine.createWindow(); //creates the window based on specifications
  bool loop = true;
  while (loop) { //gameloop
    loop = engine.loopCall(); //calls loop from engine, if it fails the loop will end
  }
  return 0;
}
