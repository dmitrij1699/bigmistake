#ifndef OBJECTS_CPP
#define OBJECTS_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/objects.h"
#include "libs/SOIL.h"
#include "header/Shader.h"
#include <vector>

using namespace std;

int objects::getN_Y(){
    return N_Y;
}

int objects::getN_X(){
    return N_X;
}

void objects::in(int y, int x){
    N_X=(x); 
    N_Y=(y);

    size_x=(float ) 2/x;
    size_y=(float ) 2/y;

    VecX.resize(x*y);
    VecY.resize(x*y);

    defv();

    defVAO();

    cout.precision(3); 
    cout.setf(ios::fixed);
    cout<<"<<<<<<<<<<<<<<<<<<<" <<endl;



    float def_x= -1-( -((float ) size_x/2));
    float def_y= -1-( -((float ) size_y/2));
    cout<<"def_x="<<def_x<<"; def_y="<<def_y<< endl;
    for(int i=0;i<y;i++){

        for(int j=0;j<x;j++){
            VecX[j+i*x]=def_x+size_x*(j);
            cout<<"j="<<j<<"; VecX["<<j+i*x<<"]="<<VecX[j+i*x]<< endl;
            VecY[j+i*x]=def_y+size_y*i;
        }
                 
    }
}

float objects::getVecX(int number){
    return VecX[number];
}

float objects::getVecY(int number){
    return VecY[number];
}


void objects::defv(){
    default_vec.resize(8);
    text.resize(8);
    indices.resize(6);
    default_vec[0]=-size_x/2;
    default_vec[1]=-size_y/2;
    default_vec[2]=size_x/2;
    default_vec[3]=-size_y/2;
    default_vec[4]=-size_x/2;
    default_vec[5]=size_y/2;
    default_vec[6]=size_x/2;
    default_vec[7]=size_y/2;
    cout.precision(3); 
    cout.setf(ios::fixed);

    cout<<"size_x="<<size_x << "; size_y="<<size_y<< endl;

    for(int i=0; i<default_vec.size(); ++i)
    std::cout <<"default_vec["<<i<<"]"<< default_vec[i] <<endl<< ' ';
    float texture[] = {
        0.0f, 0.0f, // 0
        1.0f, 0.0f, // 1
        1.0f, 1.0f, // 2
        0.0f, 1.0f // 3
    };
    //text(texture, sizeof(texture));
    text.size();
    indices = {  
        0, 1, 2, 
        1, 2, 3
    };
}

//vector<float> GetDefault(){
  //  return default_vec;
//}


GLuint objects::getVAO(){
    return VAO;
}

void objects::defVAO(){
    float texture[] = {
        0.0f, 0.0f, // 0
        1.0f, 0.0f, // 1
        1.0f, 1.0f, // 2
        0.0f, 1.0f // 3
    };

    cout.precision(3); 
    cout.setf(ios::fixed);

    for(int i=0; i<default_vec.size(); ++i)
    std::cout <<"default_vec["<<i<<"]"<< default_vec[i] <<endl<< ' ';

    for(int i=0; i<indices.size(); ++i)
    std::cout << "indices["<<i<<"]" << indices[i]<< endl<<' ';

    

    GLuint VBO[2];
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO[0];
    GLuint text= VBO[1];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,default_vec.size()* sizeof(default_vec), &default_vec[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glBufferData(GL_ARRAY_BUFFER,sizeof(texture), texture, GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()* sizeof(indices), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
}


#endif