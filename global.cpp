#include "global.h"

/*
Created by: Avery Reed on 2/14/17
Last Edited by: Avery Reed 2/14/17
*/

Global::Global() {
  setAnnotation(1);
  out("Global variables and functions initiated.\n");
}

Global::~Global() {
  out("Deconstructing global class.\n");
}
