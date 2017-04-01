#include "game.h"

Game::Game() {
  e.debugMode(true);
  e.exitOnEscape(true);
  e.setGLMode(true);
  e.init("Tada!", WIDTH, HEIGHT, 0, 0, SDL_WINDOW_OPENGL);
  e.setColor(0x00, 0x08, 0x99);
  //monkey.loadOBJ("res/cube.obj");
  loop();
}
Game::~Game() {
}

void Game::loop() {
  last_time = SDL_GetTicks();
  while(e.getRunning()) {
    e.loopStart();
    e.setGLView(3,4,2,0,0,0,0,0,1);
    start_time = SDL_GetTicks();
    e.update();
    input();
    update();
    draw();
    e.render();
  }
}

void Game::draw() {
	glRotated(angleX, 1, 0, 0);
	glRotated(angleZ, 0, 0, 1);

	glBegin(GL_QUADS); //Début pour le CUBEEEEE

	glColor3ub(255,0,0); //face rouge
	glVertex3d(1,1,1);
	glVertex3d(1,1,-1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,1,1);

	glColor3ub(0,255,0); //face verte
	glVertex3d(1,-1,1);
	glVertex3d(1,-1,-1);
	glVertex3d(1,1,-1);
	glVertex3d(1,1,1);

	glColor3ub(0,0,255); //face bleue
	glVertex3d(-1,-1,1);
	glVertex3d(-1,-1,-1);
	glVertex3d(1,-1,-1);
	glVertex3d(1,-1,1);

	glColor3ub(255,255,0); //face jaune
	glVertex3d(-1,1,1);
	glVertex3d(-1,1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(-1,-1,1);

	glColor3ub(0,255,255); //face cyan
	glVertex3d(1,1,-1);
	glVertex3d(1,-1,-1);
	glVertex3d(-1,-1,-1);
	glVertex3d(-1,1,-1);

	glColor3ub(255,0,255); //face magenta
	glVertex3d(1,-1,1);
	glVertex3d(1,1,1);
	glVertex3d(-1,1,1);
	glVertex3d(-1,-1,1);

 //e.draw(e.getFPS(), 10, 10);
}

void Game::input() {
  /*i.logPress();
  if(i.checkKey(i.right)) angle=1;
  if(i.checkKey(i.left)) angle=-1;
  if(i.checkKey(i.up)) posY+=5;
  if(i.checkKey(i.down)) post-=5;
  if(i.checkKey(i.mouseleft)) {
   posX = event.motion.x-WIDTH/2;
   posY = HEIGHT/2-event.motion.y;
  }*/
  i.logPress(); if(i.checkKey(i.right)) cout << "test" << endl;
}

void Game::update() {
		current_time = SDL_GetTicks();
		ellapsed_time = current_time - last_time;
		last_time = current_time;
 
		angleZ += 0.05 * ellapsed_time;
		angleX += 0.05 * ellapsed_time;
 
 
		ellapsed_time = SDL_GetTicks() - start_time;
		if (ellapsed_time < 10)
		{
			SDL_Delay(10 - ellapsed_time);
		}
}
