#include "text.h"

Text::Text() {
 Sans = TTF_OpenFont("Sans.ttf", 24);
 color = {255, 255, 255};
}

Text::~Text() {}

void Text::setColor(Uint8 r, Uint8 g, Uint8 b) {
 color = {r, g, b};
}

Object Text::createMessage(string s, int x, int y, SDL_Renderer* ren) {
 cout << "creating msg" << endl;
 Object m;
 cout << "created msg obj" << endl;
 SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, s.c_str(), color);
 cout << "created surface" << endl;
 SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
 cout << "created texture" << endl;
 SDL_Rect Message_rect;
 cout << "created rect" << endl;
 Message_rect.x = x; 
 Message_rect.y = y;
 Message_rect.w = s.length()*25;
 Message_rect.h = 25;
 cout << "margined rect" << endl;
 return m;
}

Object Text::createMessage(int s, int x, int y, SDL_Renderer* ren) {
 return createMessage(to_string(s), x, y, ren);
}
