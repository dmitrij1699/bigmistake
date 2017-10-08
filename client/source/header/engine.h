#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Shader.h"

using namespace std;

class engine {
private:
    void glfwInic();    //Инициализация glfw
    void glewInic();    //Инициализация glew
    void chErr();       // проверка ошибок средствами OpenGL
    void shaderInic();  //Загрузка в SHprog шейдера
    void textureUse();  //Загрузка текстур
    void drawRoutine(); 
    //uint *fields;
    GLuint SHprog;
    GLFWwindow* window;
    GLuint texture1, texture2;
    GLuint WIDTH, HEIGHT;
    int F_X, F_Y;
    vector<int> fields;
public:
    engine(const GLuint,const GLuint,const int,const int,  vector<int> );
    void drawCircle();
    void callback(GLFWwindow* , int , int , int , int );
    //void draw();

};











#endif