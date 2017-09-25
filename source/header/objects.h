#ifndef OBJECTS_H
#define OBJECTS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class objects {
private:
    vector<float> vertices;
    vector<float> indices;
    int F_X, F_Y;
    GLuint VAO;
    const float thickness=0.01; //толщина линии между клетками
public:
    objects(int, int);

};







#endif