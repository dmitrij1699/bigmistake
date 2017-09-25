#ifndef BUFF_CPP
#define BUFF_CPP


#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint buffersIn() {

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

    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 2, // First Triangle
        0, 2, 3  // Second Triangle
    };
    GLuint VBO[2],VAO, EBO;
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindBuffer(GL_ARRAY_BUFFER, text);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
    glDeleteBuffers(2, VBO);
    glDeleteBuffers(1, &EBO);
    return VAO;
}

#endif