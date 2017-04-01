#include "game.h"
#include <sstream>

int main(int argc, char* argv[]) {
  Game g;
  if(argc > 1) {
    int seed;
    sscanf(argv[1],"%d",&seed);
    g.setSeed(seed);
  }
  g.loop();
  return 0;
}
