#ifndef IMAGE_H
#define IMAGE_H

/*
This class will be used to load in images, parse them, and display them.
Created by: Avery Reed on 2/16/17
Last Edited by: Avery Reed 2/16/17
*/

class Image {
public:
  Image();
  ~Image();

  SDL_Surface* loadImage(const char* filename);
  void parseImage();
  void displayImage();
private:
};

#endif //IMAGE_H
