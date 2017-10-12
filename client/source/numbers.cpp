#ifndef NUMBERS_CPP
#define NUMBERS_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/Shader.h"
#include "header/numbers.h"
#include <vector>

using namespace std;

numbers::numbers(){
    vertices={
        -0.5, -1,    //0
        0.5 , -1,    //1
        0.5 ,  0,    //2
        -0.5,  0,    //3
        -0.5,  1,    //4
        0.5 ,  1     //5
    };


}

GLuint numbers::VAO_num(int x){

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO;


    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices)* sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    vector<GLuint> indices;

    switch(x)
    {
        case 0:
            indices ={
                0, 1,
                1, 2,
                2, 3,
                3, 0
            };
            break;
        case 1:
            indices ={
                3 , 5,
                5 , 1
            };
            break;

        case 2:
            indices={
                4, 5,
                5, 2,
                2, 3,
                3, 0,
                0, 1
            };
            break;

        case 3:
             indices={
                4, 5,
                3, 2,
                0, 1,
                5, 1
            };
            break;

        case 4:
             indices={
                4, 3,
                3, 2,
                5, 1

            };
            break;

        case 5:
             indices={
                5, 4,
                4, 3,
                3, 2,
                2, 1,
                1, 0
            };
            break;

        case 6:
             indices={
                5, 4,
                4, 0,
                3, 2,
                2, 1,
                1, 0
            };
            break;

        case 7:
             indices={
                4, 5,
                5,0,
                3, 2
            };
            break;

        case 8:
             indices={
                4, 5,
                3, 2,
                0, 1,
                4, 0,
                5, 1
            };
            break;
        case 9:
             indices={
                4, 5,
                4, 3,
                3, 2,
                5, 1,
                1, 0
            };
            break;
   
    }

    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices)* sizeof(GLuint), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);



    glBindVertexArray(0); // Unbind VAO
    return VAO;
}

#endif