#ifndef CHOOSE_CPP
#define CHOOSE_CPP
//Класс для выбора. Обменивается данными с сервером с сервером, визуализирует интерфейс. 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "header/choose.h"
#include "header/numbers.h"


using namespace std;

GLuint Ltext(const char str[]);

void choose::genBySize(float size){}

void choose::genDefault(){
    money=35;
    vertices.insert(vertices.end(),{
        -0.225, -1, //0
        -0.075, -1, //1
        -0.075, -0.85, //2
        -0.225, -0.85   //3
    });
    indices.insert(indices.end(),{
        0, 1, 2,
        0, 2, 3
    });
    text.insert(text.end(),{
        0.0, 0.0, // 0
        1.0, 0.0, // 1
        1.0, 1.0, // 2
        0.0, 1.0
    });
    Shader ourShader("../source/shaders/choose.vs", "../source/shaders/choose.frag");
    shader= ourShader.Program;

    type = glGetUniformLocation(shader, "typeT");
    inc =glGetUniformLocation(shader, "inc");

    archer= Ltext("../Textures/defence/archer.png");
    catapult= Ltext("../Textures/defence/catapult.png");
    crossbow= Ltext("../Textures/defence/crossbow.png");
    knight= Ltext("../Textures/attack/knight.png");
    peasant= Ltext("../Textures/attack/peasant.png");
    ram= Ltext("../Textures/attack/ram.png");
    textureSet();
    
}

choose::choose(double dtime, bool type):time(dtime){
    if (type) {
        typeT={5, 6, 7};
    } else typeT={3, 4, 5};
    time0=time+31;
    genDefault();
    VAOvariables();


    
}

void choose::drawVariables(){
    
    glUseProgram(shader);
    glBindVertexArray(VAO);

    for(int i=0; i<typeT.size();i++){
        glUniform1i(type,typeT[i]);
        glUniform2f(inc,i*0.16, 0);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
    }
    glBindVertexArray(0);
}

void choose::textureSet(){
    
    
    glUseProgram(shader); 
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, archer);
    glUniform1i(glGetUniformLocation(shader, "archer"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, catapult);
    glUniform1i(glGetUniformLocation(shader, "catapult"), 1);  
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, crossbow);
    glUniform1i(glGetUniformLocation(shader, "crossbow"), 2);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, knight);
    glUniform1i(glGetUniformLocation(shader, "knight"), 3);  
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, peasant);
    glUniform1i(glGetUniformLocation(shader, "peasant"), 4);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, ram);
    glUniform1i(glGetUniformLocation(shader, "ram"), 5);  
}

void choose::VAOvariables(){

    

    GLuint VBO[2], EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);

    GLuint position= VBO[0];
    GLuint text= VBO[1];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()* sizeof(vertices), &vertices[0], GL_STATIC_DRAW);


    glBindBuffer(GL_ARRAY_BUFFER, text);
    glBufferData(GL_ARRAY_BUFFER,sizeof(this->text)*this->text.size(), &this->text[0], GL_STATIC_DRAW);

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

void choose::draw(){
    time=time0-glfwGetTime();
    drawVariables();
    drawNum();
}

void choose::drawNum(){
    numbers num;
    num.drawNum((int) time/10, 0.05, -0.03, 0.93);
    num.drawNum(time- ( (int) time/10)*10, 0.05, 0.03, 0.93);

    num.drawNum( (int) money/10 , 0.05, 0.905, 0.0);       
    num.drawNum( money- ( (int) money/10)*10, 0.05, 0.965, 0.0);
}




#endif