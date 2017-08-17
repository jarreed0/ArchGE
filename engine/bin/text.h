#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
using namespace std;
#include "object.h"

class Text {
public:
 Text();
 ~Text() {TTF_Quit();}
 void setStyle(string s);
 void setSize(int s) {size=s;}
 void setColor(Uint8 r, Uint8 g, Uint8 b) {color = {r,g,b};}
 void setMessage(string m, SDL_Renderer* r) {msg=m; ren=r;}
 void update();
 Object write() const {return obj;}
 void setDest(int x, int y, int w, int h) {setCoord(x,y);setSize(w,h);}
 void setSize(int w, int h) {obj.setDestCoord(w,h);}
 void setCoord(int x, int y) {obj.setDestCoord(x,y);}
private:
 int size;
 string style;
 string msg;
 SDL_Surface* surf;
 SDL_Texture* tex;
 TTF_Font* font;
 SDL_Color color;
 SDL_Renderer* ren;
 Object obj;
};

#endif //TEXT_H
