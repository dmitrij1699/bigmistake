#ifndef NUMBERS_H
#define NUMBERS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include <vector>

using namespace std;


class numbers {
private:
    void VAO_num(int);
    vector<GLfloat> vertices;
    GLuint shader, VAO;
    GLint inc,size;
    vector <int> num;   //кол-во отрисовок для той или иной цифры(только нужно *2)
public:
    numbers();
    
    void drawNum(int, float,float, float);    //число, size, pos_x, pos_y (центр слева)
};

#endif