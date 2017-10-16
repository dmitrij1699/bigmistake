#ifndef MENU_CPP
#define MENU_CPP
//Класс для создания и отрисовки менюхи

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "header/menu.h"
#include "header/Shader.h"
#include "header/bukavki.h"
#include <cmath>

void menu::addNewItem(string str_in){
    
    str.push_back(str_in);
    if (str.size()<=1 ){
        coord.insert(coord.end(), {-0.75, -0.75, //0
                        0.75,   -0.75, //1
                        0.75,   0.75, //2
                        -0.75,  0.75} ); //3
        indices.insert(indices.end(), {0,1,2, 0,2,3});
    } else {
        float part=(float) 6*str.size()+(str.size()-1);  // 6/6-сам объект, 1/6-растояние между ними
        float diff_y=1.5/part;
        coord[5]=-0.75+6*diff_y;
        coord[7]=coord[5];
        for(int i=0;i< (str.size()-1) ;i++){
            coord.push_back( -0.75 );
            coord.push_back( coord[ 8*i+5 ]+diff_y);
            coord.push_back( 0.75 );
            coord.push_back( coord[8*i+5 ]+diff_y);

            coord.push_back( -0.75 );
            coord.push_back( coord[ 8*(i+1)+1 ]+6*diff_y);
            coord.push_back( 0.75 );
            coord.push_back( coord[ 8*(i+1)+1 ]+6*diff_y);

            indices.push_back(4*(i+1) );
            indices.push_back(4*(i+1)+1);
            indices.push_back(4*(i+1)+2);
            indices.push_back(4*(i+1)+1);
            indices.push_back(4*(i+1)+2);
            indices.push_back(4*(i+1)+3);
        }
    }

    for(int i=0; i<coord.size(); i++){
        cout<< "coord["<<i<<"]="<<fixed<<coord[i]<<endl;
    }
    for(int i=0; i<indices.size(); i++){
        cout<< "indices["<<i<<"]="<<fixed<<indices[i]<<endl;
    }

    createVAO();
}

void menu::addNewItem(vector<int> str_in){
    coord.clear();
    indices.clear();
    strI.push_back(str_in[0]);

        strMas.push_back(str_in);

        coord.insert(coord.end(), {-0.75, -0.75, //0
                        0.75,   -0.75, //1
                        0.75,   0.75, //2
                        -0.75,  0.75} ); //3
        indices.insert(indices.end(), {0,1,2, 0,2,3});
        cout<<"STR.SIZE"<<strI.size()<< endl;
        float part=(float) 6*strI.size()+(strI.size()-1);  // 6/6-сам объект, 1/6-растояние между ними
        float diff_y=1.5/part;
        coord[5]=-0.75+6*diff_y;
        coord[7]=coord[5]; 

        for(int i=1; i<strI.size();i++){
            coord.push_back( -0.75 );                       //8,16
            coord.push_back( coord[ 8*(i-1)+5 ]+diff_y);    //9, 17
            coord.push_back( 0.75 );                        //10,18
            coord.push_back( coord[8*(i-1)+5 ]+diff_y);     //11,19

            coord.push_back( -0.75 );                       //12,20
            coord.push_back( coord[ 8*i+1 ]+6*diff_y);      //13,21
            coord.push_back( 0.75 );                        //14,22
            coord.push_back( coord[ 8*i+1 ]+6*diff_y);      //15,23

            indices.push_back(4*i );
            indices.push_back(4*i+1);
            indices.push_back(4*i+2);
            indices.push_back(4*i+1);
            indices.push_back(4*i+2);
            indices.push_back(4*i+3);
        }
    

    for(int i=0; i<coord.size(); i++){
        cout<< "coord["<<i<<"]="<<fixed<<coord[i]<<endl;
    }
    for(int i=0; i<indices.size(); i++){
        cout<< "indices["<<i<<"]="<<fixed<<indices[i]<<endl;
    }

    createVAO();
}

void menu::createVAO(){



    cout<<"Загрузка шейдерной програмы MENU..."<<endl;
    Shader olol("../source/shaders/menu.vs", "../source/shaders/menu.frag");
    shader= olol.Program;


    GLuint VBO,EBO ;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO;

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,coord.size()* sizeof(coord), &coord[0], GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()* sizeof(indices), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
}

void menu::draw(){
    drawPoints();
    drawWords();
}

void menu::drawPoints(){
    glUseProgram(shader);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6*strI.size(),GL_UNSIGNED_INT, 0 );
    glBindVertexArray(0);
}

void menu::drawWords(){
    
    for(int i=0; i<strI.size(); i++){
        float coef=fabs(-coord[i*8+5]-coord[i*8+1]);
        bukavki bb( strMas[i] ,coef/2*0.3, -0.75 , (-coord[i*8+5]-coord[i*8+1] ) /2);
        bb.setVAO();
        bb.draw();
    }
    
}

#endif