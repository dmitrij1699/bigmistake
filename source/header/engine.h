#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Shader.h"

using namespace std;

class engine {
private:
    //uint *fields;
    GLFWwindow* window;
    GLuint texture1, texture2, SHprogram;
    GLuint WIDTH, HEIGHT;
    int F_X, F_Y;
    vector<vector<int>> fields;
public:
    engine(const GLuint,const GLuint,const int,const int,  vector<vector<int>> );
    void drawCircle();
    void callback(GLFWwindow* , int , int , int , int );
    //void draw();

};











#endif