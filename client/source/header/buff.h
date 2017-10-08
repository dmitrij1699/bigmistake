#ifndef BUFF_H
#define BUFF_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class buff {
private:
    vector <GLfloat> textures = {
        0.0f, 0.0f, // 0
        1.0f, 0.0f, // 1
        1.0f, 1.0f, // 2
        0.0f, 1.0f, // 3
    };
    vector <GLfloat> vertices = {
        // Позиция              
         -1.0f,   -1.0f, 0.0f,      
         1.0f,   -1.0f, 0.0f,      
         1.0f,   1.0f, 0.0f,      
         -1.0f,   1.0f, 0.0f

    }; 
    vector <GLuint> indices = {  
        0, 1, 2, 
        0, 2, 3
    };
  
    GLuint VBO[2],VAO, EBO;

public: 
    buff();
    ~buff();
    GLuint getVAO();
};


#endif