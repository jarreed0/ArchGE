#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL_ttf.h>
using namespace std;
#include <iostream>
#include "object.h"

class Text {
private:
 SDL_Color color;
 TTF_Font* Sans;
public:
 Text();
 ~Text();
 void setColor(Uint8 r, Uint8 g, Uint8 b);
 Object createMessage(string s, int x, int y, SDL_Renderer* ren);
 Object createMessage(int s, int x, int y, SDL_Renderer* ren);
};

#endif //TEXT_H
