#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Shader.h"
#include "objects.h"
#include "unit.h"
#include "menu.h"

using namespace std;

class engine {
private:
    void glfwInic();    //Инициализация glfw
    void glewInic();    //Инициализация glew
    void chErr();       // проверка ошибок средствами OpenGL
    void drawCircle();
    void drawMenu(menu);
    void drawNumber(int);
    //void drawUnits(objects &,vector <int> &,unit , GLint, GLint );
    GLFWwindow* window;

    GLuint WIDTH, HEIGHT;
    int F_X, F_Y;
    vector<int> fields;
    double time;
public:
    engine(const GLuint,const GLuint,const int,const int,  vector<int> );

    static void callback(GLFWwindow* , int , int , int , int );

};











#endif