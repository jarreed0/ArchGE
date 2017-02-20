#include "genesis.h"

Genesis::Genesis() : map(28) {
  engine.init(TITLE, WIDTH, HEIGHT, 0);
  running=true;
  background.setImage("res/bkg.bmp", engine.renderScreen());
  background.setSource(0, 0, WIDTH, HEIGHT);
  background.setDest(WIDTH, HEIGHT);
  player.setImage("res/player.bmp", engine.renderScreen());
  player.setSource(0, 0, TILE_SIZE, 45);
  player.setDest(TILE_SIZE, 45);
  player.setDX(50);
  player.setDY(50);
  engine.setColor(0x00, 0x00, 0xff);
  grass.setImage("res/blocks.bmp", engine.renderScreen());
  grass.setValue(1);
  grass.setSource(0*(grass.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  rock.setImage("res/blocks.bmp", engine.renderScreen());
  rock.setValue(2);
  rock.setSource(TILE_SIZE*(rock.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  flower.setImage("res/blocks.bmp", engine.renderScreen());
  flower.setValue(3);
  flower.setSource(TILE_SIZE*(flower.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  water.setImage("res/blocks.bmp", engine.renderScreen());
  water.setValue(4);
  water.setSource(TILE_SIZE*(water.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  dirt.setImage("res/blocks.bmp", engine.renderScreen());
  dirt.setValue(5);
  dirt.setSource(TILE_SIZE*(dirt.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  copper.setImage("res/blocks.bmp", engine.renderScreen());
  copper.setValue(6);
  copper.setSource(TILE_SIZE*(copper.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  iron.setImage("res/blocks.bmp", engine.renderScreen());
  iron.setValue(7);
  iron.setSource(TILE_SIZE*(iron.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  wood.setImage("res/blocks.bmp", engine.renderScreen());
  wood.setValue(8);
  wood.setSource(TILE_SIZE*(wood.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  torch.setImage("res/blocks.bmp", engine.renderScreen());
  torch.setValue(9);
  torch.setSource(TILE_SIZE*(torch.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  table.setImage("res/blocks.bmp", engine.renderScreen());
  table.setValue(10);
  table.setSource(TILE_SIZE*(table.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  stone.setImage("res/blocks.bmp", engine.renderScreen());
  stone.setValue(11);
  stone.setSource(TILE_SIZE*(stone.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  brick.setImage("res/blocks.bmp", engine.renderScreen());
  brick.setValue(12);
  brick.setSource(TILE_SIZE*(brick.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  leaf.setImage("res/blocks.bmp", engine.renderScreen());
  leaf.setValue(13);
  leaf.setSource(TILE_SIZE*(leaf.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  cobble.setImage("res/blocks.bmp", engine.renderScreen());
  cobble.setValue(14);
  cobble.setSource(TILE_SIZE*(cobble.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  post.setImage("res/blocks.bmp", engine.renderScreen());
  post.setValue(15);
  post.setSource(TILE_SIZE*(post.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  chamber.setImage("res/blocks.bmp", engine.renderScreen());
  chamber.setValue(16);
  chamber.setSource(TILE_SIZE*(chamber.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  workbench.setImage("res/blocks.bmp", engine.renderScreen());
  workbench.setValue(17);
  workbench.setSource(TILE_SIZE*(workbench.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  plank.setImage("res/blocks.bmp", engine.renderScreen());
  plank.setValue(18);
  plank.setSource(TILE_SIZE*(plank.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  chickenegg.setImage("res/blocks.bmp", engine.renderScreen());
  chickenegg.setValue(19);
  chickenegg.setSource(TILE_SIZE*(chickenegg.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  sand.setImage("res/blocks.bmp", engine.renderScreen());
  sand.setValue(20);
  sand.setSource(TILE_SIZE*(sand.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  cactus.setImage("res/blocks.bmp", engine.renderScreen());
  cactus.setValue(21);
  cactus.setSource(TILE_SIZE*(cactus.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  snow.setImage("res/blocks.bmp", engine.renderScreen());
  snow.setValue(22);
  snow.setSource(TILE_SIZE*(snow.getValue()-1), 0, TILE_SIZE, TILE_SIZE);
  map.setWindowSize(WIDTH, HEIGHT);
  map.addTile(grass);
  map.addTile(rock);
  map.addTile(flower);
  map.addTile(water);
  map.addTile(dirt);
  map.addTile(copper);
  map.addTile(iron);
  map.addTile(wood);
  map.addTile(torch);
  map.addTile(table);
  map.addTile(stone);
  map.addTile(brick);
  map.addTile(leaf);
  map.addTile(cobble);
  map.addTile(post);
  map.addTile(chamber);
  map.addTile(workbench);
  map.addTile(plank);
  map.addTile(chickenegg);
  map.addTile(sand);
  map.addTile(cactus);
  map.addTile(snow);
  map.loadTiles("res/map.map", TILE_SIZE, TILE_SIZE);
}
Genesis::~Genesis() {
  engine.deconstruct();
}
void Genesis::start() {
  while(running) {
    checkInput();
    engine.preLoop();
    draw();
    engine.endLoop();
  }
}
void Genesis::draw() {
  engine.pushToScreen(background);
  engine.pushToScreen(player);
  tiles = map.getTilesToRender();
  for(int i = 0; i<tiles.size(); i++) {
    //tiles[i].setDest(TILE_SIZE, TILE_SIZE);
    //tiles[i].setDX(50);
    //tiles[i].setDY(50);
    engine.pushToScreen(tiles[i]);
  }
}
void Genesis::checkInput() {
  input.logPress();
  if(input.checkKey(input.quit)) running=false;
  if(input.checkKey(input.esc)) running=false;
}
