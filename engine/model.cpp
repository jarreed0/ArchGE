#include "model.h"

Model::Model() {}
Model::~Model() {}

void Model::loadOBJ(const char* path) {
 FILE * file = fopen(path, "r");
 if(file==NULL) cout << "Impossible to open file!/n";
 while(true) {
  char lineHeader[128];
  int res = fscanf(file, "%s", lineHeader);
  if(res==EOF) break;
  if ( strcmp( lineHeader, "v" ) == 0 ){
    glm::vec3 vertex;
    fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
    temp_vertices.push_back(vertex);
  } else if ( strcmp( lineHeader, "vt" ) == 0 ){
    vec2 uv;
    fscanf(file, "%f %f\n", &uv.x, &uv.y );
    temp_uvs.push_back(uv);
  } else if ( strcmp( lineHeader, "vn" ) == 0 ){
    vec3 normal;
    fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
    temp_normals.push_back(normal);
  } else if ( strcmp( lineHeader, "f" ) == 0 ){
    string vertex1, vertex2, vertex3;
    unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
    int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
    if (matches != 9){
        cout << "File can't be read by our simple parser : ( Try exporting with other options\n";
    }
    vertexIndices.push_back(vertexIndex[0]);
    vertexIndices.push_back(vertexIndex[1]);
    vertexIndices.push_back(vertexIndex[2]);
    uvIndices.push_back(uvIndex[0]);
    uvIndices.push_back(uvIndex[1]);
    uvIndices.push_back(uvIndex[2]);
    normalIndices.push_back(normalIndex[0]);
    normalIndices.push_back(normalIndex[1]);
    normalIndices.push_back(normalIndex[2]);
 }
 for(int i=0; i<vertexIndices.size(); i++) {
  unsigned int vertexIndex = vertexIndices[i];
  vec3 vertex = temp_vertices[vertexIndex-1];
  out_vertices.push_back(vertex);
 }
}}
