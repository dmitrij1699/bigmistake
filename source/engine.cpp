#ifndef ENGINE_CPP
#define ENGINE_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "header/engine.h"
#include "header/objects.h"
#include "header/Shader.h"
#include "libs/SOIL.h"
#include <vector>
#include <iostream>

#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

GLuint Ltext(const char str[]); 

void callback(GLFWwindow* window, int key, int scancode, int action, int mode);

engine::engine(GLuint WIDTH,GLuint HEIGHT,int F_X,int F_Y,vector<vector<int>> fields): F_X(F_X), F_Y(F_Y),WIDTH(WIDTH), HEIGHT(HEIGHT), fields(fields)  {
    cout << "Старт инициализации..." << endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "bigmistake", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    //glfwSetKeyCallback(window, engine::callback); 
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WIDTH, HEIGHT);
    cout << "Инициализация прошла успешно" << endl;
    
    Shader ourShader("../source/shaders/object.vs", "../source/shaders/object.frag");
    SHprogram= ourShader.Program;
    cout<< "Загрузка текстур" <<endl;
    texture1= Ltext("../Textures/dirt.png");
    texture2= Ltext("../Textures/grass.png");
    cout<< "Текстуры загружены" <<endl;
    drawCircle();

}

void engine::drawCircle(){
    cout << "Старт отрисовки..." << endl;
    objects OBJ(F_X, F_Y);
    vec3 size(OBJ.getSize_x(), OBJ.getSize_y(), 0.0f);
    int i=0;
    while (!glfwWindowShouldClose(window)) {
        cout<<"начало цикла"<<endl;
        glfwPollEvents();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(SHprogram); 
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(SHprogram, "dirt"), 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glUniform1i(glGetUniformLocation(SHprogram, "grass"), 1);  
        GLint typeTLoc = glGetUniformLocation(SHprogram, "typeT");
        GLint incLoc = glGetUniformLocation(SHprogram, "inc");
        GLint sizeLoc = glGetUniformLocation(SHprogram, "size");
        cout <<"wow!"<< endl;
        vec3 inc((GLfloat) OBJ.getInc_x(),0.0f, 0.0f);
        for (int y=0; y<F_Y; y++){
            for(int x=0; x<F_X; x++){
                switch( fields[x][y] ){  
                    case 1: {
                        glUniform1i(typeTLoc, fields[x][y] );
                        glUniform3fv(incLoc,3,&inc[0]); //!!!!!!!!
                        glUniform3fv(sizeLoc,3, &size[0]);
                        glDrawArrays(GL_QUADS, 0, 4);
                    }   
                    default: { 
                        glUniform3fv(incLoc,3,&inc[0]); //!!!!!!!!
                        glUniform3fv(sizeLoc,3,&size[0]);
                        glUniform1i(typeTLoc,  fields[x][y] );
                        glDrawArrays(GL_QUADS, 0, 4);
                        }
                    }
                inc= inc+ vec3(OBJ.getInc_x(), 0.0f, 0.0f);
            }
            inc= inc+ vec3(0.0f, OBJ.getInc_y(), 0.0f);
        } 

        glfwSwapBuffers(window);
        cout<<"конец цикла"<<endl;
        i++;

        //if(i>100) break;
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