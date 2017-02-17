#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include <iostream>

/*
This class will be used to load in images, parse them, and display them.
Created by: Avery Reed on 2/16/17
Last Edited by: Avery Reed 2/16/17
*/

class Image {
public:
  Image();
  Image(string n, string file, SDL_Renderer* ren);
  ~Image();

  void loadImage(const std::string &file, SDL_Renderer* ren);
  void parseImage();

  SDL_Texture* getImage() const {return img;}

  SDL_Renderer* drawToScale(SDL_Renderer* ren, int x, int y, int w, int h);
  SDL_Renderer* draw(SDL_Renderer* ren, int x, int y);

  void setName(string n) {name = n;}
  string getName() const {return name;}
private:
  SDL_Texture* img;
  string name;
};

#endif //IMAGE_H
