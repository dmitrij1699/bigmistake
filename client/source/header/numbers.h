#ifndef NUMBERS_H
#define NUMBERS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include <vector>

class numbers {
private:
    std::vector<GLfloat> vertices;
public:
    numbers();
    GLuint VAO_num(int);
};

#endif