#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "header/engine.h"
#include "header/objects.h"

using namespace std;

engine::engine(GLuint WIDTH,GLuint HEIGHT, int F_X, int F_Y, uint *fields) {
    cout << "Старт инициализации..." << endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, engine::callback);
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WIDTH, HEIGHT);
    cout << "Инициализация прошла успешно" << endl;
}

void engine::drawCircle(){
    cout << "Старт отрисовки..." << endl;
    objects OBJ(F_X, F_Y);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        glfwSwapBuffers(window);
    }
}











#endif