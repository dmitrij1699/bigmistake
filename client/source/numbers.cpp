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
    num={
        4, 2,5, 4, 3, 5,5,3,5,5
    };

}

void numbers::VAO_num(int x){

    vector<GLuint> indices;
    
        
    
        
        switch(x)
        {
            case 0:
                indices ={
                    0, 1,
                    1, 5,
                    5, 4,
                    4, 0
                };//4
    
                break;
            case 1:
                indices ={
                    3 , 5,
                    5 , 1
                };//2
                break;
    
            case 2:
                indices={
                    4, 5,
                    5, 2,
                    2, 3,
                    3, 0,
                    0, 1
                }; //5
                break;
    
            case 3:
                 indices={
                    4, 5,
                    3, 2,
                    0, 1,
                    5, 1
                }; //4
                break;
    
            case 4:
                 indices={
                    4, 3,
                    3, 2,
                    5, 1
    
                }; //3
                break;
    
            case 5:
                 indices={
                    5, 4,
                    4, 3,
                    3, 2,
                    2, 1,
                    1, 0
                }; //5
                break;
    
            case 6:
                 indices={
                    5, 4,
                    4, 0,
                    3, 2,
                    2, 1,
                    1, 0
                }; //5
                break;
    
            case 7:
                 indices={
                    4, 5,
                    5,0,
                    3, 2
                }; //3
                break;
    
            case 8:
                 indices={
                    4, 5,
                    3, 2,
                    0, 1,
                    4, 0,
                    5, 1
                }; //5
                break;
            case 9:
                 indices={
                    4, 5,
                    4, 3,
                    3, 2,
                    5, 1,
                    1, 0
                }; //5
                break;
       
        }

    

    Shader olol("../source/shaders/number.vs", "../source/shaders/number.frag");
    shader= olol.Program;


    inc = glGetUniformLocation(shader, "inc");
    size = glGetUniformLocation(shader, "size");

    GLuint VBO,  EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO;


    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices)* vertices.size(), &vertices[0], GL_STATIC_DRAW);

  

    

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices)* indices.size(), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);



    glBindVertexArray(0); // Unbind VAO
}

void numbers::drawNum(int x,float size_in, float pos_x, float pos_y){
    VAO_num(x);
    glUseProgram(shader);
    glBindVertexArray(VAO);
    glUniform1f(size, size_in);
    glUniform2f(inc, pos_x, pos_y);
    glDrawElements(GL_LINES,num[x]*2,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

#endif