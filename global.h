#ifndef GLOBAL_H
#define GLOBAL_H

#define VERSION "0.0"

using namespace std;
#include <iostream>
#include <string>
#include "SDL2/SDL.h"

/*
This is the global class that will store global variables, global libraries to include, and if annotations is on/off.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/10/17
*/

class Global {
public:
  Global() {setAnnotation(1); out("Global variables and functions initiated.\n");}
  ~Global() {out("Deconstructing global class.\n");}
  void out(string s) {if(annotation){cout << s;}}
  void out(int i) {if(annotation){cout << i;}} //Use this to post to the screen.
  void setAnnotation(bool an) {annotation = an;}
  void flipAnnotation() {if(annotation) {annotation=0;} else {annotation=1;}}
  const char* getVersion() const {return VERSION;}
private:
  bool annotation;
};

#endif //GOBAL_H
