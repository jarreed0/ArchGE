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
  mouseleft = 43;
  quit = 44;
  esc = 45;
  w = 46;
  mouseright = 47;
  mousemiddle = 48;
  mouseup = 49;
  mousedown = 50;
  for(int i=1; i<51; i++) {
   keys[i]=false;
  }
}
Input::~Input() {}

void Input::logPress() {
  //bool done = reset();
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if(event.type == SDL_QUIT) {keys[quit] = true; cout << "Quiting\n";}
    if(event.type == SDL_MOUSEBUTTONDOWN) {
      if((event.button.button == SDL_BUTTON_LEFT) && !keys[mouseleft]) {keys[mouseleft] = true; cout << "Left mouse button\n";}
      if((event.button.button == SDL_BUTTON_RIGHT) && !keys[mouseright]) {keys[mouseright] = true; cout << "Right mouse button\n";}
      if((event.button.button == SDL_BUTTON_MIDDLE) && !keys[mousemiddle]) {keys[mousemiddle] = true; cout << "Middle mouse button\n";}
    }
    if(event.type == SDL_MOUSEBUTTONUP) {
      if((event.button.button == SDL_BUTTON_LEFT) && keys[mouseleft]) {keys[mouseleft] = false; cout << "Left mouse button up\n";}
      if((event.button.button == SDL_BUTTON_RIGHT) && keys[mouseright]) {keys[mouseright] = false; cout << "Right mouse button up\n";}
      if((event.button.button == SDL_BUTTON_MIDDLE) && keys[mousemiddle]) {keys[mousemiddle] = false; cout << "Middle mouse button up\n";}
    }
    if(event.type == SDL_KEYDOWN) {
      if((event.key.keysym.sym == SDLK_LEFT) && !keys[left]) {keys[left] = true; cout << "left\n";}
      if((event.key.keysym.sym == SDLK_RIGHT) && !keys[right]) {keys[right] = true; cout << "right\n";}
      if((event.key.keysym.sym == SDLK_DOWN) && !keys[down]) {keys[down] = true; cout << "down\n";}
      if((event.key.keysym.sym == SDLK_UP) && !keys[up]) {keys[up] = true; cout << "up\n";}
      if((event.key.keysym.sym == SDLK_a) && !keys[a]) {keys[a] = true; cout << "a\n";}
      if((event.key.keysym.sym == SDLK_b) && !keys[b]) {keys[b] = true; cout << "b\n";}
      if((event.key.keysym.sym == SDLK_c) && !keys[c]) {keys[c] = true; cout << "c\n";}
      if((event.key.keysym.sym == SDLK_d) && !keys[d]) {keys[d] = true; cout << "d\n";}
      if((event.key.keysym.sym == SDLK_e) && !keys[e]) {keys[e] = true; cout << "e\n";}
      if((event.key.keysym.sym == SDLK_f) && !keys[f]) {keys[f] = true; cout << "f\n";}
      if((event.key.keysym.sym == SDLK_g) && !keys[g]) {keys[g] = true; cout << "g\n";}
      if((event.key.keysym.sym == SDLK_h) && !keys[h]) {keys[h] = true; cout << "h\n";}
      if((event.key.keysym.sym == SDLK_i) && !keys[i]) {keys[i] = true; cout << "i\n";}
      if((event.key.keysym.sym == SDLK_j) && !keys[j]) {keys[j] = true; cout << "j\n";}
      if((event.key.keysym.sym == SDLK_k) && !keys[k]) {keys[k] = true; cout << "k\n";}
      if((event.key.keysym.sym == SDLK_l) && !keys[l]) {keys[l] = true; cout << "l\n";}
      if((event.key.keysym.sym == SDLK_m) && !keys[m]) {keys[m] = true; cout << "m\n";}
      if((event.key.keysym.sym == SDLK_n) && !keys[n]) {keys[n] = true; cout << "n\n";}
      if((event.key.keysym.sym == SDLK_o) && !keys[o]) {keys[o] = true; cout << "o\n";}
      if((event.key.keysym.sym == SDLK_p) && !keys[p]) {keys[p] = true; cout << "p\n";}
      if((event.key.keysym.sym == SDLK_q) && !keys[q]) {keys[q] = true; cout << "q\n";}
      if((event.key.keysym.sym == SDLK_r) && !keys[r]) {keys[r] = true; cout << "r\n";}
      if((event.key.keysym.sym == SDLK_s) && !keys[s]) {keys[s] = true; cout << "s\n";}
      if((event.key.keysym.sym == SDLK_t) && !keys[t]) {keys[t] = true; cout << "t\n";}
      if((event.key.keysym.sym == SDLK_u) && !keys[u]) {keys[u] = true; cout << "u\n";}
      if((event.key.keysym.sym == SDLK_v) && !keys[v]) {keys[v] = true; cout << "v\n";}
      if((event.key.keysym.sym == SDLK_w) && !keys[w]) {keys[w] = true; cout << "w\n";}
      if((event.key.keysym.sym == SDLK_x) && !keys[x]) {keys[x] = true; cout << "x\n";}
      if((event.key.keysym.sym == SDLK_y) && !keys[y]) {keys[y] = true; cout << "y\n";}
      if((event.key.keysym.sym == SDLK_z) && !keys[z]) {keys[z] = true; cout << "z\n";}
      if((event.key.keysym.sym == SDLK_ESCAPE) && !keys[esc]) {keys[esc] = true; cout << "Esc\n";}
      if((event.key.keysym.sym == SDLK_1) && !keys[1]) {keys[1] = true; cout << "1\n";}
      if((event.key.keysym.sym == SDLK_2) && !keys[2]) {keys[2] = true; cout << "2\n";}
      if((event.key.keysym.sym == SDLK_3) && !keys[3]) {keys[3] = true; cout << "3\n";}
      if((event.key.keysym.sym == SDLK_4) && !keys[4]) {keys[4] = true; cout << "4\n";}
      if((event.key.keysym.sym == SDLK_5) && !keys[5]) {keys[5] = true; cout << "5\n";}
      if((event.key.keysym.sym == SDLK_6) && !keys[6]) {keys[6] = true; cout << "6\n";}
      if((event.key.keysym.sym == SDLK_7) && !keys[7]) {keys[7] = true; cout << "7\n";}
      if((event.key.keysym.sym == SDLK_8) && !keys[8]) {keys[8] = true; cout << "8\n";}
      if((event.key.keysym.sym == SDLK_9) && !keys[9]) {keys[9] = true; cout << "9\n";}
      if((event.key.keysym.sym == SDLK_0) && !keys[0]) {keys[0] = true; cout << "0\n";}
      if((event.key.keysym.sym == SDLK_LSHIFT) && !keys[lshift]) {keys[lshift] = true; cout << "left shift\n";}
      if((event.key.keysym.sym == SDLK_RSHIFT) && !keys[rshift]) {keys[rshift] = true; cout << "right shift\n";}
    }
    if(event.type == SDL_KEYUP) {
      if((event.key.keysym.sym == SDLK_LEFT) && keys[left]) {keys[left] = false; cout << "left up\n";}
      if((event.key.keysym.sym == SDLK_RIGHT) && keys[right]) {keys[right] = false; cout << "right up\n";}
      if((event.key.keysym.sym == SDLK_DOWN) && keys[down]) {keys[down] = false; cout << "down up\n";}
      if((event.key.keysym.sym == SDLK_UP) && keys[up]) {keys[up] = false; cout << "up up\n";}
      if((event.key.keysym.sym == SDLK_a) && keys[a]) {keys[a] = false; cout << "a up\n";}
      if((event.key.keysym.sym == SDLK_b) && keys[b]) {keys[b] = false; cout << "b up\n";}
      if((event.key.keysym.sym == SDLK_c) && keys[c]) {keys[c] = false; cout << "c up\n";}
      if((event.key.keysym.sym == SDLK_d) && keys[d]) {keys[d] = false; cout << "d up\n";}
      if((event.key.keysym.sym == SDLK_e) && keys[e]) {keys[e] = false; cout << "e up\n";}
      if((event.key.keysym.sym == SDLK_f) && keys[f]) {keys[f] = false; cout << "f up\n";}
      if((event.key.keysym.sym == SDLK_g) && keys[g]) {keys[g] = false; cout << "g up\n";}
      if((event.key.keysym.sym == SDLK_h) && keys[h]) {keys[h] = false; cout << "h up\n";}
      if((event.key.keysym.sym == SDLK_i) && keys[i]) {keys[i] = false; cout << "i up\n";}
      if((event.key.keysym.sym == SDLK_j) && keys[j]) {keys[j] = false; cout << "j up\n";}
      if((event.key.keysym.sym == SDLK_k) && keys[k]) {keys[k] = false; cout << "k up\n";}
      if((event.key.keysym.sym == SDLK_l) && keys[l]) {keys[l] = false; cout << "l up\n";}
      if((event.key.keysym.sym == SDLK_m) && keys[m]) {keys[m] = false; cout << "m up\n";}
      if((event.key.keysym.sym == SDLK_n) && keys[n]) {keys[n] = false; cout << "n up\n";}
      if((event.key.keysym.sym == SDLK_o) && keys[o]) {keys[o] = false; cout << "o up\n";}
      if((event.key.keysym.sym == SDLK_p) && keys[p]) {keys[p] = false; cout << "p up\n";}
      if((event.key.keysym.sym == SDLK_q) && keys[q]) {keys[q] = false; cout << "q up\n";}
      if((event.key.keysym.sym == SDLK_r) && keys[r]) {keys[r] = false; cout << "r up\n";}
      if((event.key.keysym.sym == SDLK_s) && keys[s]) {keys[s] = false; cout << "s up\n";}
      if((event.key.keysym.sym == SDLK_t) && keys[t]) {keys[t] = false; cout << "t up\n";}
      if((event.key.keysym.sym == SDLK_u) && keys[u]) {keys[u] = false; cout << "u up\n";}
      if((event.key.keysym.sym == SDLK_v) && keys[v]) {keys[v] = false; cout << "v up\n";}
      if((event.key.keysym.sym == SDLK_w) && keys[w]) {keys[w] = false; cout << "w up\n";}
      if((event.key.keysym.sym == SDLK_x) && keys[x]) {keys[x] = false; cout << "x up\n";}
      if((event.key.keysym.sym == SDLK_y) && keys[y]) {keys[y] = false; cout << "y up\n";}
      if((event.key.keysym.sym == SDLK_z) && keys[z]) {keys[z] = false; cout << "z up\n";}
      if((event.key.keysym.sym == SDLK_ESCAPE) && keys[esc]) {keys[esc] = false; cout << "Esc up\n";}
      if((event.key.keysym.sym == SDLK_1) && keys[1]) {keys[1] = false; cout << "1 up\n";}
      if((event.key.keysym.sym == SDLK_2) && keys[2]) {keys[2] = false; cout << "2 up\n";}
      if((event.key.keysym.sym == SDLK_3) && keys[3]) {keys[3] = false; cout << "3 up\n";}
      if((event.key.keysym.sym == SDLK_4) && keys[4]) {keys[4] = false; cout << "4 up\n";}
      if((event.key.keysym.sym == SDLK_5) && keys[5]) {keys[5] = false; cout << "5 up\n";}
      if((event.key.keysym.sym == SDLK_6) && keys[6]) {keys[6] = false; cout << "6 up\n";}
      if((event.key.keysym.sym == SDLK_7) && keys[7]) {keys[7] = false; cout << "7 up\n";}
      if((event.key.keysym.sym == SDLK_8) && keys[8]) {keys[8] = false; cout << "8 up\n";}
      if((event.key.keysym.sym == SDLK_9) && keys[9]) {keys[9] = false; cout << "9 up\n";}
      if((event.key.keysym.sym == SDLK_0) && keys[0]) {keys[0] = false; cout << "0 up\n";}
      if((event.key.keysym.sym == SDLK_LSHIFT) && keys[lshift]) {keys[lshift] = false; cout << "left shift up\n";}
      if((event.key.keysym.sym == SDLK_RSHIFT) && keys[rshift]) {keys[rshift] = false; cout << "right shift up\n";}
    }
/*
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
*/
        SDL_GetMouseState(&mousex, &mousey);
    }
}

bool Input::checkKey(int k) {
  return keys[k];
}


bool Input::reset() {
  //NEED TO LOOP THROUGH KEYS[] AND SET THEM ALL TO false
  //THE LOOP BELOW CAUSES THE GAME TO CRASH
  keys[44] = 0;
  keys[45] = 0;
  for(int i; i<sizeof(keys); i++) {
    keys[i] = 0;
  }
  return true;
}
