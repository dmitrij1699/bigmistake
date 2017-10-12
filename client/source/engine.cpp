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
#include "header/buff.h"
#include "header/numbers.h"

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
    cout<<"Загрузка шейдерной програмы..."<<endl;
    Shader lineShader("../source/shaders/line.vs", "../source/shaders/line.frag");
    LineSH= lineShader.Program;
    cout<<"Загрузка шейдерной програмы Успешно!"<<endl;
    chErr();
    cout<<"Загрузка шейдерной програмы..."<<endl;
    Shader numberShader("../source/shaders/number.vs", "../source/shaders/number.frag");
    NumberSH= numberShader.Program;
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
    

    glUseProgram(SHprog); 
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glUniform1i(glGetUniformLocation(SHprog, "dirt"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glUniform1i(glGetUniformLocation(SHprog, "grass"), 1);  
}

void engine::drawFields(objects OBJ,GLint inc, GLint type){
    drawRoutine();
    
    glBindVertexArray(OBJ.getVAO());
    for(int i=0;i<F_X*F_Y;i++){
        glUniform2f(inc,OBJ.getVecX(i), OBJ.getVecY(i) );
        glUniform1i(type,fields[F_X*F_Y-i-1]);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
        
    }
    glBindVertexArray(0);
}

void engine::drawLines(objects OBJ){
    glUseProgram(LineSH);
    glBindVertexArray(OBJ.getVAOline());
    int NUMB=(F_X+F_Y-1)*2;
    glDrawArrays(GL_LINES,0, NUMB );
    glBindVertexArray(0);
}

void engine::drawNumber(int x){
    glUseProgram(NumberSH);
    numbers num;
    glBindVertexArray(num.VAO_num(x));
    int calc=0;
    switch(x){
        case 4:
        case 7: 
        case 1:
            calc=3;
            break;
        
        case 3:
        case 0:
            calc=4;
            break;
        
        case 2:
        case 5:
        case 6:
        case 8:
        case 9:
            calc=5;
            break;
    }
    glDrawElements(GL_LINES, calc*2, GL_UNSIGNED_INT,0 );
    glBindVertexArray(0);
}

void engine::drawCircle(){

    cout << "Старт отрисовки..." << endl;
    objects OBJ;
    OBJ.in(F_X, F_Y);

    

    


    GLint inc = glGetUniformLocation(SHprog, "inc");
    GLint type = glGetUniformLocation(SHprog, "typeT");
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        drawFields(OBJ, inc, type);
        drawLines(OBJ);
        drawNumber(0);



        
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