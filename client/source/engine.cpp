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
#include "header/unit.h"
#include "header/menu.h"
#include "header/choose.h"
#include "header/connect.h"
#include <string>

#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

GLuint Ltext(const char str[]); 


void engine::glfwInic(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //ну или 4 :)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  
   

    window = glfwCreateWindow(WIDTH, HEIGHT, "bigmistake", nullptr, nullptr);
    glfwMakeContextCurrent(window); 
    glfwSetKeyCallback(window, &engine::callback); 
    glfwSetCursorPosCallback(window, &engine::curs_callback);
    
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





engine::engine(GLuint WIDTH,GLuint HEIGHT,int F_X,int F_Y,vector<int> fields): F_X(F_X), F_Y(F_Y),WIDTH(WIDTH), HEIGHT(HEIGHT), fields(fields)  {

    glfwInic(); //Инициализация glfw
    glewInic(); //Инициализация glew
 
    
    glViewport(0, 0, WIDTH, HEIGHT);


    drawCircle();

}




void engine::drawMenu(menu main_menu){
    main_menu.draw();
}




void engine::drawCircle(){
    process=1;
    int state=0;    //мыша
    double xpos, ypos,time;
    vector<int> coord_choice;
    vector<int> choice;
    time=glfwGetTime();
    vector<int> sfields=fields;
    choose wow(time, false, &xpos, &ypos, &state, WIDTH,HEIGHT, &sfields[0] , &process, F_X, F_Y );

    //vector<int> defence {2,3,3,10};  //Башня, номер клетки.

    menu main_menu;

    vector<int> s0={0,1,1,0,0};
    main_menu.addNewItem(s0);

 
    main_menu.addNewItem(s0);

   
    main_menu.addNewItem(s0);

    vector<int> defence;
    vector<int> attack {6,6,6,5,5,5,7};
    unit newUnit(&process);

    while (!glfwWindowShouldClose(window)) { //ГЛАВНЫЙ ЦИКЛ
        time=glfwGetTime();

        glfwGetCursorPos(window, &xpos, &ypos);
        state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        switch (process) {
            case 0:
                main_menu.draw();
                break;
            case 1:
                wow.draw();
                if( process==2) {
                    wow.getDefence(&defence);
                    newUnit.in(fields,attack , &defence, F_X, F_Y,time );
                    
                }
                break;
            case 2:
                newUnit.calc(time); //3- выйгрыш защиты. 4-выйгрыш атаки
                newUnit.draw();
                break;
            case 3:
                cout<<"Вы выйграли!"<<endl;
                exit(3);
                break;
            case 4:
                cout<<"Вы проиграли!"<<endl;
                exit(4);
                break;
        }
        glfwPollEvents();
        
        glfwSwapBuffers(window);
        if ( process==3 || process==4 ){
            switch (process){
                case 3:
                cout<<"Вы выйграли!"<<endl;
                exit(3);
                break;
            case 4:
                cout<<"Вы проиграли!"<<endl;
                exit(4);
                break;
            }
        }
    }
}

int engine::getProc(){
    return process;
}

void engine::callback(GLFWwindow* window, int key, int scancode, int action, int mode){
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
}


void engine::curs_callback(GLFWwindow* window, double xpos_in, double ypos_in){

    //cout<<"xpos="<<xpos_in<<", ypos="<<ypos_in<<endl;
}




#endif