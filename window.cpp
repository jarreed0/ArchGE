#include "window.h"

Window::Window() {
  //gl.out("Created window.\n");
  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == NULL){
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
	}
}

Window::~Window() {
  //gl.out("Closing window.\n");
}
