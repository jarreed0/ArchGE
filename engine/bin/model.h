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
 vector<unsigned int> vertexIndices, uvIndices, normalIndices;
 vector<vec3> temp_vertices;
 vector<vec2> temp_uvs;
 vector<vec3> temp_normals;
 vector<vec3> out_vertices;
 vector<vec2> out_uvs;
 vector<vec3> out_normals;
public:
 Model();
 ~Model();
 void loadOBJ(const char* path);
};

#endif //MODEL_H
