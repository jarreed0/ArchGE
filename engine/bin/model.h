#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <cstring> 
#include <glm/glm.hpp>
using namespace std;
using namespace glm;

class Model {
private:
public:
 Model();
 ~Model();
 void load();
};

#endif //MODEL_H
