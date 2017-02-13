#include "arch.h"

/*
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/10/17
*/

Arch::Arch() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
  }

  if (SDL_CreateWindowAndRenderer(860, 480, 0, &window, &renderer)) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
  }

  while (1) {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT) {
          break;
      }
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
  }
}

Arch::Arch(int WIDTH, int HEIGHT) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
  }

  if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer)) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
  }

  while (1) {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT) {
          break;
      }
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
  }
}

Arch::Arch(int WIDTH, int HEIGHT, Uint32 FLAGS) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
  }

  if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, FLAGS, &window, &renderer)) {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
  }

  while (1) {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT) {
          break;
      }
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, texture, NULL, NULL);
      SDL_RenderPresent(renderer);
  }
}

Arch::~Arch() {
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
