#ifndef ARCH_H
#define ARCH_H

#include "global.h"

/*
This is the main header file for the engine that will have most classes underneath.
Created by: Avery Reed on 2/10/17
Last Edited by: Avery Reed 2/10/17
*/

class Arch {
public:
  Arch();
  ~Arch();
  Global gl; //Global class is used for global variables, like the engine version
private:
};

#endif //ARCH_H
