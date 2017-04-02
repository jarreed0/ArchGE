#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define SPEED 6
#define WIDTH 640
#define HEIGHT 480
#define FRAMERATE 60
#define TILESIZE 64

class Game {
private:
  Engine e;
  bool running, facedown, faceup, faceleft, faceright;
  Input i;
  Object arena;
  Entity bike;
  vector<Object> tile;
  Object logo;
  vector<Object> beam;
  GameState gs;
  bool l, r, u, d;
<<<<<<< HEAD
  int vel, timerFps = 0;
  bool paused;
=======
>>>>>>> c67c66df5f3e794a83a50dfbf15126601448378f
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void genTiles();
};

#endif //GAME_H
