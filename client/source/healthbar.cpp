#ifndef healthbar_CPP
#define healthbar_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/objects.h"
#include "libs/SOIL.h"
#include "header/Shader.h"
#include "header/healthbar.h"
#include <vector>
#include <cmath>

using namespace std;

healthbar::healthbar(float size_x_in, float size_y_in){
    size_x=size_x_in/2;
    size_y=size_y_in/2;
    defVAO();
}

void healthbar::in(float x_in, float y_in, float health_in){
    x=x_in;
    y=y_in-3*size_y/4;
    health=health_in;
    draw();
}

void healthbar::defVAO(){
    float position[]={
        -1.0 ,  -1.0,
        1.0  ,  -1.0,
        -1.0 ,  1.0,
        1.0,    1.0
    };

    GLuint indices[]={
        1, 2, 3,
        1, 0, 2
    };


    Shader ourShader("../source/shaders/healthbar.vs", "../source/shaders/healthbar.frag");
    shader= ourShader.Program;
    resize = glGetUniformLocation(shader, "resize");
    move = glGetUniformLocation(shader, "move");
    color = glGetUniformLocation(shader, "colorU");

    GLuint VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    GLuint positionP= VBO;

    glBindBuffer(GL_ARRAY_BUFFER, positionP);
    glBufferData(GL_ARRAY_BUFFER,sizeof(position)* sizeof(float), position, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices)* sizeof(GLuint), indices, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, positionP);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
}

void healthbar::draw(){
    glUseProgram(shader);
    glBindVertexArray(VAO);
    glUniform2f(resize, size_x, size_y/8 );
    glUniform2f(move, x, y );
    glUniform1i(color, 0); //черный
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
    glUniform2f(resize, size_x*health,size_y/8 );
    glUniform2f(move, x, y );
    glUniform1i(color, 1); //зеленый 
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
    glBindVertexArray(0);
}


#endif