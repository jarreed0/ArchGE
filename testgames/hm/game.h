#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 353
#define HEIGHT 353

class Game {
private:
 string NAME;
 Engine e;
public:
 Game();
 ~Game();
 void loop();
};

#endif
