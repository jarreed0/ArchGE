#ifndef PARK_H
#define PARK_H

#include <iostream>
using namespace std;
#include <vector>
#include "../../engine/engine.h"
#include "../../engine/image.h"
#include "../../engine/input.h"

class Park {
public:
 Park();
 ~Park();
 int start();
 void draw();
private:
 Engine window;
 Object player;
 Input handle;
 vector<Object> coin;
 vector<Object> grass;
 int WINDOW_WIDTH = 405;
 int WINDOW_HEIGHT = 655;
 bool done;
};

#endif //PARK_H
