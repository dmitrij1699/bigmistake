#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class engine {
private:
    unsigned int *fields;
    GLFWwindow* window;
    

public:
    engine(GLuint, GLuint, int, int, uint *);
    void drawCircle();
    void callback();
    //void draw();

};











#endif