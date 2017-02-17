#include "ArchGE/H/arch.h"
#include "ArchGE/H/object.h"
#include "ArchGE/H/coord.h"
#include "ArchGE/H/image.h"

/*
This is a test main function in order to test out the game engine mechanics.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/16/17
*/

//The commented code does not work
//It is a sample for a game
//Though it is not how the engine will work at all
//The engine will have refrenced objects instead of just calling all functions just from the engine

int main() {
  Arch engine(320, 480, "Park Stroll"); //creates reference of engine and sets window specifications
  engine.createWindow(); //creates the window based on specifications
  Coord c(3,3);
  Object grass(c, "grass");
  Image background;
  background.loadImage("ArchGE/Res/archge-bw.png");
  bool loop = true;
  std::cout << "(" <<  grass.getCoord().getX() << ", " << grass.getCoord().getY() << ")" << endl;
  while (loop) { //gameloop
    loop = engine.loopCall(); //calls loop from engine, if it fails the loop will end
    engine.drawBackground(background);
  }
  return 0;
}
