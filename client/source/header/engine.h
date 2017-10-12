#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Shader.h"
#include "objects.h"

using namespace std;

class engine {
private:
    void glfwInic();    //Инициализация glfw
    void glewInic();    //Инициализация glew
    void chErr();       // проверка ошибок средствами OpenGL
    void shaderInic();  //Загрузка в SHprog шейдера
    void textureUse();  //Загрузка текстур
    void drawRoutine(); 
    void drawCircle();
    void drawFields(objects, GLint, GLint);
    void drawLines(objects);
    void drawNumber(int);
    //uint *fields;
    GLuint SHprog,LineSH, NumberSH;
    GLFWwindow* window;
    GLuint dirt, grass, archer, catapult, crossbow, knight,peasant, ram, road ;
    GLuint WIDTH, HEIGHT;
    int F_X, F_Y;
    vector<int> fields;
public:
    engine(const GLuint,const GLuint,const int,const int,  vector<int> );

    static void callback(GLFWwindow* , int , int , int , int );
    //void draw();

};











#endif