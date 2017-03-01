#include "input.h"

Input::Input() {
  reset();
  left = 10;
  right = 11;
  up = 12;
  down = 13;
  q = 14;
  e = 15;
  r = 16;
  t = 17;
  y = 18;
  u = 19;
  i = 20;
  o = 21;
  p = 22;
  a = 23;
  s = 24;
  d = 25;
  f = 26;
  g = 27;
  h = 28;
  j = 29;
  k = 30;
  l = 31;
  z = 32;
  x = 33;
  c = 34;
  v = 35;
  b = 36;
  n = 37;
  m = 39;
  lshift = 40;
  rshift = 41;
  shift = 42;
  mouse = 43;
  quit = 44;
  esc = 45;
  w = 46;
}
Input::~Input() {}

void Input::logPress() {
  reset();
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
        keys[quit] = true;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
          case SDLK_UP: keys[up] = true; break;
			    case SDLK_LEFT: keys[left] = true; break;
    	    case SDLK_RIGHT: keys[right] = true; break;
    	    case SDLK_DOWN: keys[down] = true; break;
          case SDLK_a: keys[a] = true; break;
          case SDLK_b: keys[b] = true; break;
          case SDLK_c: keys[c] = true; break;
          case SDLK_d: keys[d] = true; break;
          case SDLK_e: keys[e] = true; break;
          case SDLK_f: keys[f] = true; break;
          case SDLK_g: keys[g] = true; break;
          case SDLK_h: keys[h] = true; break;
          case SDLK_i: keys[i] = true; break;
          case SDLK_j: keys[j] = true; break;
          case SDLK_k: keys[k] = true; break;
          case SDLK_l: keys[l] = true; break;
          case SDLK_m: keys[m] = true; break;
          case SDLK_n: keys[n] = true; break;
          case SDLK_o: keys[o] = true; break;
          case SDLK_p: keys[p] = true; break;
          case SDLK_q: keys[q] = true; break;
          case SDLK_r: keys[r] = true; break;
          case SDLK_s: keys[s] = true; break;
          case SDLK_t: keys[t] = true; break;
          case SDLK_u: keys[u] = true; break;
          case SDLK_v: keys[v] = true; break;
          case SDLK_w: keys[w] = true; break;
          case SDLK_x: keys[x] = true; break;
          case SDLK_y: keys[y] = true; break;
    	    case SDLK_z: keys[z] = true; break;
          case SDLK_ESCAPE: keys[esc] = true; break;
          case SDLK_1: keys[1] = true; break;
          case SDLK_2: keys[2] = true; break;
          case SDLK_3: keys[3] = true; break;
          case SDLK_4: keys[4] = true; break;
          case SDLK_5: keys[5] = true; break;
          case SDLK_6: keys[6] = true; break;
          case SDLK_7: keys[7] = true; break;
          case SDLK_8: keys[8] = true; break;
          case SDLK_9: keys[9] = true; break;
          case SDLK_0: keys[0] = true; break;
          case SDLK_LSHIFT: keys[lshift] = true; keys[shift] = true; break;
          case SDLK_RSHIFT: keys[rshift] = true; keys[shift] = true; break;
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
          keys[mouse] = true;
          break;
        }
    }
}

bool Input::checkKey(int k) {
  return keys[k];
}

void Input::reset() {
  //NEED TO LOOP THROUGH KEYS[] AND SET THEM ALL TO false
  //THE LOOP BELOW CAUSES THE GAME TO CRASH
  for(int i; i<50; i++) {
    keys[i] = 0;
  }
}
