#include "input-tmp.h"

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
  mouseleft = 43;
  quit = 44;
  esc = 45;
  w = 46;
  mouseright = 47;
  mousemiddle = 48;
  mouseup = 49;
  mousedown = 50;
}
Input::~Input() {}

void Input::logPress() {
  reset();
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
        keys[quit] = true; cout << "\n"; break; break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
			    case SDLK_LEFT: keys[left] = true; cout << "left\n"; break;
    	    case SDLK_RIGHT: keys[right] = true; cout << "right\n"; break;
    	    case SDLK_DOWN: keys[down] = true; cout << "down\n"; break;
          case SDLK_a: keys[a] = true; cout << "a\n"; break;
          case SDLK_b: keys[b] = true; cout << "b\n"; break;
          case SDLK_c: keys[c] = true; cout << "c\n"; break;
          case SDLK_d: keys[d] = true; cout << "d\n"; break;
          case SDLK_e: keys[e] = true; cout << "e\n"; break;
          case SDLK_f: keys[f] = true; cout << "f\n"; break;
          case SDLK_g: keys[g] = true; cout << "g\n"; break;
          case SDLK_h: keys[h] = true; cout << "h\n"; break;
          case SDLK_i: keys[i] = true; cout << "i\n"; break;
          case SDLK_j: keys[j] = true; cout << "j\n"; break;
          case SDLK_k: keys[k] = true; cout << "k\n"; break;
          case SDLK_l: keys[l] = true; cout << "l\n"; break;
          case SDLK_m: keys[m] = true; cout << "m\n"; break;
          case SDLK_n: keys[n] = true; cout << "n\n"; break;
          case SDLK_o: keys[o] = true; cout << "o\n"; break;
          case SDLK_p: keys[p] = true; cout << "p\n"; break;
          case SDLK_q: keys[q] = true; cout << "q\n"; break;
          case SDLK_r: keys[r] = true; cout << "r\n"; break;
          case SDLK_s: keys[s] = true; cout << "s\n"; break;
          case SDLK_t: keys[t] = true; cout << "t\n"; break;
          case SDLK_u: keys[u] = true; cout << "u\n"; break;
          case SDLK_v: keys[v] = true; cout << "v\n"; break;
          case SDLK_w: keys[w] = true; cout << "w\n"; break;
          case SDLK_x: keys[x] = true; cout << "x\n"; break;
          case SDLK_y: keys[y] = true; cout << "y\n"; break;
    	    case SDLK_z: keys[z] = true; cout << "z\n"; break;
          case SDLK_ESCAPE: keys[esc] = true; cout << "esc\n"; break;
          case SDLK_1: keys[1] = true; cout << "1\n"; break;
          case SDLK_2: keys[2] = true; cout << "2\n"; break;
          case SDLK_3: keys[3] = true; cout << "3\n"; break;
          case SDLK_4: keys[4] = true; cout << "4\n"; break;
          case SDLK_5: keys[5] = true; cout << "5\n"; break;
          case SDLK_6: keys[6] = true; cout << "6\n"; break;
          case SDLK_7: keys[7] = true; cout << "7\n"; break;
          case SDLK_8: keys[8] = true; cout << "8\n"; break;
          case SDLK_9: keys[9] = true; cout << "9\n"; break;
          case SDLK_0: keys[0] = true; cout << "0\n"; break;
          case SDLK_LSHIFT: keys[lshift] = true; cout << "\n"; break; keys[shift] = true; cout << "lshift\n"; break;
          case SDLK_RSHIFT: keys[rshift] = true; cout << "\n"; break; keys[shift] = true; cout << "rshift\n"; break;
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
          switch (event.button.button) {
            //case SDL_BUTTON_WHEELUP: keys[mouseup] = true; cout << "\n"; break;
            //case SDL_BUTTON_WHEELDOWN: keys[mousedown] = true; cout << "\n"; break;
            case SDL_BUTTON_LEFT: keys[mouseleft] = true; cout << "\n"; break;
            case SDL_BUTTON_RIGHT: keys[mouseright] = true; cout << "\n"; break;
            case SDL_BUTTON_MIDDLE: keys[mousemiddle] = true; cout << "\n"; break;
          }
        }
        SDL_GetMouseState(&mousex, &mousey);
    }
}

bool Input::checkKey(int k) {
  return keys[k];
}

void Input::reset() {
  //NEED TO LOOP THROUGH KEYS[] AND SET THEM ALL TO false
  //THE LOOP BELOW CAUSES THE GAME TO CRASH
  for(int i; i<sizeof(keys); i++) {
    keys[i] = 0;
  }
}
