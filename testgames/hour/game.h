#ifndef GAME_H
#define GAME_H

#include <arch/arch.h>

#define WIDTH 620//1600
#define HEIGHT 480//900
#define FRAMERATE 60
#define TRIANGLE_H 600
#define TRIANGLE_W 600//320
#define SPEED 5
#define GRAVITY 4
#define FLIGHT 3
#define ROTATION 2

class Game {
private:
  struct column {
    Object t1;
    Object t2;
    bool scored;
  };
  Engine e;
  bool paused = false;
  Input i;
  int localX, localY;
  Collision col;
  Entity player;
  vector<column> triangle;
  bool up;
  Object triangleTemplate;
  column columnTemplate;
  int score;
  Object top, bot;
  Object tl, tr, bl, br;
  int r, g, b;
  bool purple, green, blue, orange;
  vector<Object> smoke;
  Object smokeTemplate;
  vector<Object> flame;
  Object flameTemplate;
  vector<Object> dust;
  Object dustTemplate;
  bool cameraEnabled, start, boost;
  float count, pauseTick;
  Object menu;
  bool shield;
  Object bubble;
  int deathCount;
  int regenShield;
  int highscore;
  //int WIDTH, HEIGHT;
public:
  Game();
  ~Game();
  void loop();
  void draw();
  void input();
  void update();
  void updatePlayer();
  void drawFloor();
  void generateMap();
  void generateDust();
  void makeTriangle();
  void startLevel(int s);
  void changeColor();
  void smokeTrail();
  void flameTrail();
  void drawBackground();
  void camera();
  void die(int i);
  void boostMode();
};

#endif //GAME_H
