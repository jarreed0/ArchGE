#include "arch.h"

/*
This is a test main function in order to test out the game engine mechanics.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/15/17
*/

//The commented code does not work
//It is a sample for a game
//Though it is not how the engine will work at all
//The engine will have refrenced objects instead of just calling all functions just from the engine

int main() {
  Arch engine(320, 480, "Park Stroll"); //creates reference of engine and sets window specifications
  engine.createWindow(); //creates the window based on specifications
  //engine.Object grass(engine.Coord c(3, 3));
  /*engine.loadImage("res/tiles.png", "tilesimg");
  engine.loadImage("res/sprite.png", "playerimg");
  engine.loadImage("res/gui.png", "guiimg");
  engine.loadMap("res/map.txt", "cart", 20, "map");
  engine.parseImage("tilesimg", 4, 1, 20, 20, "tileparsed");
  engine.parseImage("playerimg", 3, 3, 20, 40, "playerparsed");
  engine.parseImage("guiimg", 3, 1, 15, 15, "guiparsed");
  engine.createEntity("player", "playerparsed");
  engine.createGUI("gui", "guiparsed");
  engine.setMapTile("map", "tileparsed", 0, 4, 1, "air");
  engine.setMapTile("map", "tileparsed", 1, 3, 1, "dirt");
  engine.setMapTile("map", "tileparsed", 2, 1, 1, "grass");
  engine.setMapTile("map", "tileparsed", 3, 2, 1, "stone");
  engine.setMapStart("map", 3, 3);
  engine.setBackground(0x00, 0x00, 0xFF);
  engine.entityStart("map", 3, 3);
  engine.setEntityFrame("player", 2, 2);
  engine.setEntitySpeed("player", 3);*/
  bool loop = true;
  while (loop) { //gameloop
    loop = engine.loopCall(); //calls loop from engine, if it fails the loop will end
    /*engine.drawBackground();
    engine.drawMap("map");
    engine.drawEntity("player");
    if(engine.input() = "left") { engine.moveMap("player", "left", engine.getEntitySpeed("player")); engine.setEntityFrame("player", 1, 2); }
    if(engine.input() = "right") { engine.moveMap("player", "right", engine.getEntitySpeed("player")); engine.setEntityFrame("player", 3, 2); }
    if(engine.input() = "down") { engine.moveMap("player", "down", engine.getEntitySpeed("player")); engine.setEntityFrame("player", 2, 3); }
    if(engine.input() = "up") { engine.moveMap("player", "up", engine.getEntitySpeed("player")); engine.setEntityFrame("player", 2, 1); }*/
    //std::cout << "(" <<  grass.getCoord().getX() << " ," << grass.getCoord().getY() << ")" << endl;
  }
  return 0;
}
