#ifndef BUKAVKI_CPP
#define BUKAVKI_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/bukavki.h"
#include <string>
#include <vector>


//Класс для отрисовки текста. Инициализируем. Подаем строку. Передаем координаты(центр) и роазмер текста. ВУАЛЯ!

bukavki::bukavki(string str, float size_in, float pos_x_in, float pos_y_in):size(size_in),pos_x(pos_x_in),pos_y(pos_y_in) {

    for(int i=0;i<str.size();i++){
        addNewChar(str[i] );
    }
}

void bukavki::addNewChar(char next){
    switch (next){
        case "А":
            indices.push_back(0,5,
                              5,14
                              15,16);
            num.push_back(3);
            break;
        case "Б":
            indices.push_back(4,10,
                              4,0,
                              0,14,
                              14,12,
                              2, 12);
            num.push_back(5); 
            break;
    }
}

GLuint bukavki::getVAO(){

    vector<float> bias;

    vector<float> default_vec {
        0,  -1,     //0
        0,  -0.5,   //1
        0,  0,      //2
        0,  0.5,    //3
        0,  1,      //4
        0.5,1,      //5
        0.5,0.5,    //6
        0.5,0,      //7
        0.5,-0.5,   //8
        0.5,-1,     //9
        1,  1,      //10
        1,  0.5,    //11
        1,  0,      //12
        1,  -0.5,   //13
        1,  -1,     //14
        0.25,0,     //15
        0.75,0,     //16
        0.75,1,     //17
        1,  0.75,   //18
        1,  0.25,   //19
        1,  -0.25,  //20
        1,  -0.75,  //21
        0.75,-1,    //22
        0.25,-0.25, //23
        0.75,-0.25, //24
        0,  -0.75,  //25
        0,75,-0.75  //26
    };

    for(int i=0;i<default_vec.size();i++){
        default_vec[i]=default_vec[i]*size;
    }

    for(int i=0;i<num.size();i++){
        for(int  g=bias.size(); ( g-bias.size() )<num[i] ;g++)
            bias[g]=(float) i*size;
    }


    GLuint VBO[2],VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO[0];
    GLuint biASS= VBO[1];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,default_vec.size()* sizeof(default_vec), &default_vec[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, biASS);
    glBufferData(GL_ARRAY_BUFFER,bias.size()* sizeof(bias), &bias[0], GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()* sizeof(indices), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    
    glBindBuffer(GL_ARRAY_BUFFER, biASS);
    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
    return VAO;
}

int bukavki::getNum(){
    int sum=0;
    for(int i=0; i<num.size();i++){
        sum+=num[i];
    }
    return sum;
}

#endif