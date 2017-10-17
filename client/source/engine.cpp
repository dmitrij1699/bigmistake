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
#include <string>

#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

GLuint Ltext(const char str[]); 


void engine::glfwInic(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  
   

    window = glfwCreateWindow(WIDTH, HEIGHT, "bigmistake", nullptr, nullptr);
    glfwSetKeyCallback(window, &engine::callback); 
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





engine::engine(GLuint WIDTH,GLuint HEIGHT,int F_X,int F_Y,vector<int> fields): F_X(F_X), F_Y(F_Y),WIDTH(WIDTH), HEIGHT(HEIGHT), fields(fields)  {
    cout << "Старт инициализации..." << endl;
    glfwInic(); //Инициализация glfw
    glewInic(); //Инициализация glew
 
    
    glViewport(0, 0, WIDTH, HEIGHT);
    cout << "Инициализация прошла успешно" << endl;

    drawCircle();

}



void engine::drawNumber(int x){
    numbers num;
    //glBindVertexArray(num.VAO_num(x));
    int calc=0;
    switch(x){
        case 1:
        case 7:
            calc=2;
            break;
        case 4:
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
   // glDrawElements(GL_LINES, calc*2, GL_UNSIGNED_INT,0 );
    //glBindVertexArray(0);
}

void engine::drawMenu(menu main_menu){
    main_menu.draw();
}

/*void engine::drawUnits(objects &OBJ, vector <int> & attack, unit units,GLint inc,GLint type){
    
    glUseProgram(SHprog); 
    glBindVertexArray(OBJ.getVAO());
    for(int i=0;i<attack.size();i++){
        cout<< "отрисовка "<<i<<"-го объекта"<< endl;
        if(units.ch(i)==1) {
        cout<< "прошел проверку "<<i<<"-ый объект"<< endl;
        glUniform2f(inc,units.getVecX(i), units.getVecY(i) );
        glUniform1i(type,attack[i]);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
        }
    }
    glBindVertexArray(0);
}*/


void engine::drawCircle(){
    int state=0;
    double xpos, ypos;
    cout << "Старт отрисовки..." << endl;
    objects OBJ(&fields[0]);
    OBJ.in(F_X, F_Y);
    double time;
    time=glfwGetTime();
    menu main_menu;
    vector<int> strI {0,1,0, 1};
    main_menu.addNewItem(strI);
    main_menu.addNewItem(strI);
    //vector <int> attack={5, 5, 5, 6, 6,7};
    //unit units(fields, attack, OBJ, F_X, F_Y, time);

    choose wow(time, false, &xpos, &ypos, &state, WIDTH,HEIGHT );
    cout<<"HEIGHT="<<HEIGHT<<", WIDTH="<<WIDTH<< endl;

    while (!glfwWindowShouldClose(window)) {

        glfwGetCursorPos(window, &xpos, &ypos);
        state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        OBJ.draw();
        //drawFields(OBJ, inc, type);
        //drawLines(OBJ);
        //drawNumber(1);
        //drawMenu(main_menu);
        //time=glfwGetTime();
        //units.calc(time);
        //drawUnits(OBJ, attack, units,inc, type);

        wow.draw();

        glfwPollEvents();
        
        glfwSwapBuffers(window);
    }
}


void engine::callback(GLFWwindow* window, int key, int scancode, int action, int mode){
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
}







#endif