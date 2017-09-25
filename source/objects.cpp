#ifndef OBJECTS_CPP
#define OBJECTS_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "header/objects.h"

using namespace std;

objects::objects(int F_X,int F_Y){
    cout<< "Высчитывание координат объектов..."<< endl;
    float inc_x, inc_y, line[(F_X+F_Y-2)*8], obj_x[F_X], obj_y[F_Y], square[F_X*8][F_Y*8] ;
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

    for(int x=0; x<F_X*4; x++){
        for(int y=0; y<F_Y*4; y++){
            
        }
    }

    cout<<"Заполнение буферов"<< endl;

    GLuint VBO[2], EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO[0];
    GLuint text= VBO[1];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textures), textures, GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
    glDeleteBuffers(2, VBO);
    glDeleteBuffers(1, &EBO);


}











#endif