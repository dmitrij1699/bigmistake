#ifndef ENGINE_CPP
#define ENGINE_CPP

#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include "header/engine.h"
#include "header/objects.h"
#include "header/Shader.h"
#include "libs/SOIL.h"
#include <vector>
#include <iostream>
#include "header/buff.h"

#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

GLuint Ltext(const char str[]); 

void callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void engine::glfwInic(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  
        //glfwSetKeyCallback(window, engine::callback); 

    window = glfwCreateWindow(WIDTH, HEIGHT, "bigmistake", nullptr, nullptr);
    glfwMakeContextCurrent(window); 
    chErr();
}

void engine::glewInic(){
    glewExperimental = GL_TRUE;
    GLenum err=glewInit();
    if(err!=GLEW_OK) {
      // Problem: glewInit failed, something is seriously wrong.
      cout << "glewInit failed: " << glewGetErrorString(err) << endl;
      exit(1);
    }
    chErr();
}

void engine::chErr(){
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
      cout<< "error"<<err<<endl;
    }
}

void engine::shaderInic(){
    cout<<"Загрузка шейдерной програмы..."<<endl;
    Shader ourShader("../source/shaders/object.vs", "../source/shaders/object.frag");
    SHprog= ourShader.Program;
    cout<<"Загрузка шейдерной програмы Успешно!"<<endl;
    chErr();
}

void engine::textureUse(){
    cout<< "Загрузка текстур" <<endl;
    texture1= Ltext("../Textures/dirt.png");
    texture2= Ltext("../Textures/grass.png");
    cout<< "Текстуры загружены" <<endl;
    chErr();
}

engine::engine(GLuint WIDTH,GLuint HEIGHT,int F_X,int F_Y,vector<int> fields): F_X(F_X), F_Y(F_Y),WIDTH(WIDTH), HEIGHT(HEIGHT), fields(fields)  {
    cout << "Старт инициализации..." << endl;
    glfwInic(); //Инициализация glfw
    glewInic(); //Инициализация glew
    shaderInic();
    textureUse();
 
    
    glViewport(0, 0, WIDTH, HEIGHT);
    cout << "Инициализация прошла успешно" << endl;

    drawCircle();

}

void engine::drawRoutine(){
    glfwPollEvents();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(SHprog); 
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glUniform1i(glGetUniformLocation(SHprog, "dirt"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glUniform1i(glGetUniformLocation(SHprog, "grass"), 1);  
}

void engine::drawCircle(){

    cout << "Старт отрисовки..." << endl;
    objects OBJ;
    OBJ.in(F_X, F_Y);

    drawRoutine();

    glBindVertexArray(OBJ.getVAO());


    GLint inc = glGetUniformLocation(SHprog, "inc");
    GLint type = glGetUniformLocation(SHprog, "typeT");
    while (!glfwWindowShouldClose(window)) {
        for(int i=0;i<F_X*F_Y;i++){
            glUniform2f(inc,OBJ.getVecX(i), OBJ.getVecY(i) );
            glUniform1i(type,fields[F_X*F_Y-i-1]);
            glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
        }


        
        glfwSwapBuffers(window);
    }
}


void engine::callback(GLFWwindow* window, int key, int scancode, int action, int mode){
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
}

void  callback(GLFWwindow* window, int key, int scancode, int action, int mode){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}







#endif