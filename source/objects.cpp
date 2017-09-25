#ifndef OBJECTS_CPP
#define OBJECTS_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/objects.h"
#include "libs/SOIL.h"
#include "header/Shader.h"

using namespace std;

objects::objects(int F_X,int F_Y){
    cout<< "Высчитывание координат объектов..."<< endl;
    float  line[(F_X+F_Y-2)*8], obj_x[F_X], obj_y[F_Y], square[F_X*8][F_Y*8] ;
    inc_x= (float) (2-thickness*(F_X-1) )/F_X;
    inc_y= (float) (2-thickness*(F_Y-1) )/F_Y;
    obj_x[0]=-1;
    obj_y[0]=-1;
    for (int x=1; x<F_X; x++){
        obj_x[x]=obj_x[x-1]+inc_x+thickness;
    }
    for (int y=1; y<F_Y; y++){
        obj_y[y]=obj_y[y-1]+inc_y+thickness;
    }
    for(int i=0; i<F_X-1; i++){
        line[i*8]=obj_x[i+1];
        line[1+i*8]=-1.0f;     //1
        line[2+i*8]=obj_x[i+1]-thickness; 
        line[3+i*8]=-1.0f;      //2
        line[4+i*8]=obj_x[i+1]-thickness;
        line[5+i*8]=1.0f;
        line[6+i*8]=obj_x[i+1];
        line[7+i*8]=1.0f;
    }
    int g=0;
    for(int i=F_X-1; i<F_Y+F_X-2; i++){
        line[1+i*8]=obj_y[g+1];
        line[i*8]=-1.0f;     //1
        line[3+i*8]=obj_y[g+1]-thickness; 
        line[2+i*8]=-1.0f;      //2
        line[5+i*8]=obj_y[g+1]-thickness;
        line[4+i*8]=1.0f;
        line[7+i*8]=obj_y[g+1];
        line[6+i*8]=1.0f;
        g++;
    }
    c_x=obj_x[];
    c_y=obj_y[];
    cout<<"Заполнение буферов"<< endl;

    buff(line[]);
    cout<<"VAO заполнен"<< endl;



}

void objects::buff(float *line){
    GLfloat textures[] = {
        0.0f, 0.0f, // 0
        1.0f, 0.0f, // 1
        1.0f, 1.0f, // 2
        0.0f, 1.0f, // 3
    };
    float vertices[] = {
        // Позиция              
         -1.0f,   -1.0f, 0.0f,      
         1.0f,   -1.0f, 0.0f,      
         1.0f,   1.0f, 0.0f,      
         -1.0f,   1.0f, 0.0f

    }; 

    GLuint VBO[2];
    glGenVertexArrays(1, &VAO);
    glGenBuffers(3, VBO);
    GLuint position= VBO[0];
    GLuint text= VBO[1];
    GLuint lineB= VBO[2];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textures), textures, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, lineB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, lineB);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
    glDeleteBuffers(3, VBO);
}


float objects::getSize_x(){
    return (inc_x+thickness);
}

float objects::getSize_y(){
    return (inc_y+thickness);
}

float objects::getInc_x(){
    return (inc_x);
}
float objects::getInc_y(){
    return (inc_y);
}




#endif