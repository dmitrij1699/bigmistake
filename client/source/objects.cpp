#ifndef OBJECTS_CPP
#define OBJECTS_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/objects.h"
#include "libs/SOIL.h"
#include "header/Shader.h"
#include <vector>
#include <cmath>

using namespace std;


GLuint Ltext(const char str[]); 



void objects::draw(){
    drawUnits();
    drawLines();
}

void objects::drawLines(){
    glUseProgram(shader_line);
    glBindVertexArray(VAO_line);
    int NUMB=(N_X+N_Y-1)*2;
    glDrawArrays(GL_LINES,0, NUMB );
    glBindVertexArray(0);
}

void objects::drawUnits(){
    glUseProgram(shader_obj);
    bindTexture();
    glBindVertexArray(VAO);
    for(int i=0;i<N_X*N_Y;i++){
            glUniform2f(inc, VecX[i], VecY[i] );
            glUniform1i(type, fields[N_X*N_Y-i-1]);
            glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
        
    }
    glBindVertexArray(0);
}


objects::objects(int *fields ,int y, int x){
    this->fields=fields;
    N_X=x; 
    N_Y=y;

    

    size_x=(float ) 2/x;
    size_y=(float ) 2/y;

    VecX.resize(x*y);
    VecY.resize(x*y);

    defv();

    defVAO();
    texture_use();



    defVAOline();

    float waat;



    float def_x= -1-( -((float ) size_x/2));
    float def_y= -1-( -((float ) size_y/2));
    for(int i=0;i<y;i++){

        for(int j=0;j<x;j++){
            VecX[j+i*x]=def_x+size_x*(j);

            VecY[j+i*x]=def_y+size_y*i;
        }
        /*for(int g=0;g<x/2;g++){
            waat=VecX[g+i*x];
            VecX[g+i*x]=VecX[(i+1)*x-g];
            VecX[(i+1)*x-g]=waat;
            waat=VecY[g+i*x];
            VecY[g+i*x]=VecY[(i+1)*x-g];
            VecY[(i+1)*x-g]=waat;
        }*/
    }
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

    text.size();
    indices = { 
        1, 2, 3,
        1, 0, 2
    };
}


void objects::defVAO(){
    Shader ourShader("../source/shaders/object.vs", "../source/shaders/object.frag");
    shader_obj= ourShader.Program;
    inc = glGetUniformLocation(shader_obj, "inc");
    type = glGetUniformLocation(shader_obj, "typeT");


    float texture[] = {
        
        0.0f, 0.0f, // 0
        1.0f, 0.0f, // 1
        0.0f, 1.0f, // 2
        1.0f, 1.0f // 3
        
    };
    

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

void objects::defVAOline(){

    Shader lineShader("../source/shaders/line.vs", "../source/shaders/line.frag");
    shader_line= lineShader.Program;

    vector<float> lines((N_X+N_Y-1)*4);
    for(int i=0; i<(N_X-1);i++){
        lines[i*4]=-1+size_x*(i+1);
        lines[i*4+1]=-1;
        lines[i*4+2]=-1+size_x*(i+1);
        lines[i*4+3]=1;
    }

    for(int i=(N_X-1); i<(N_X+N_Y-1);i++){
        
        lines[i*4]=-1;
        lines[i*4+1]=-1+size_y*(i+1-N_X);
        lines[i*4+2]=1;
        lines[i*4+3]=-1+size_y*(i+1-N_X);
    }




    GLuint VBOline;
    glGenVertexArrays(1, &VAO_line);
    glGenBuffers(1, &VBOline);
    glGenBuffers(1, &EBO_line);
    GLuint posit= VBOline;

    glBindBuffer(GL_ARRAY_BUFFER, posit);
    glBufferData(GL_ARRAY_BUFFER,lines.size()* sizeof(lines), &lines[0], GL_STATIC_DRAW);


    glBindVertexArray(VAO_line);
    
   

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, posit);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0); // Unbind VAO
}


void objects::texture_use(){
    

    dirt= Ltext("../Textures/dirt.png");
    grass= Ltext("../Textures/grass.png");
    archer= Ltext("../Textures/defence/archer.png");
    catapult= Ltext("../Textures/defence/catapult.png");
    crossbow= Ltext("../Textures/defence/crossbow.png");
    knight= Ltext("../Textures/attack/knight.png");
    peasant= Ltext("../Textures/attack/peasant.png");
    ram= Ltext("../Textures/attack/ram.png");
    road= Ltext("../Textures/road.png");

  
    

}

void objects::bindTexture(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, dirt);
    glUniform1i(glGetUniformLocation(shader_obj, "dirt"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, grass);
    glUniform1i(glGetUniformLocation(shader_obj, "grass"), 1);  
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, archer);
    glUniform1i(glGetUniformLocation(shader_obj, "archer"), 2);
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, catapult);
    glUniform1i(glGetUniformLocation(shader_obj, "catapult"), 3);  
    glActiveTexture(GL_TEXTURE4);
    glBindTexture(GL_TEXTURE_2D, crossbow);
    glUniform1i(glGetUniformLocation(shader_obj, "crossbow"), 4);
    glActiveTexture(GL_TEXTURE5);
    glBindTexture(GL_TEXTURE_2D, knight);
    glUniform1i(glGetUniformLocation(shader_obj, "knight"), 5);  
    glActiveTexture(GL_TEXTURE6);
    glBindTexture(GL_TEXTURE_2D, peasant);
    glUniform1i(glGetUniformLocation(shader_obj, "peasant"), 6);
    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, ram);
    glUniform1i(glGetUniformLocation(shader_obj, "ram"), 7);  
    glActiveTexture(GL_TEXTURE8);
    glBindTexture(GL_TEXTURE_2D, road);
    glUniform1i(glGetUniformLocation(shader_obj, "road"), 8);
}



int objects::changeField(float x, float y, int n){
    float diff=2;
    int k=0;
    for(int i=0; i<N_X*N_Y;i++){
        if ( ( fabs(VecX[i]-x)*fabs(VecX[i]-x)+fabs(VecY[i]-y)*fabs(VecY[i]-y) ) <diff){
            k=i;
            diff=( fabs(VecX[i]-x)*fabs(VecX[i]-x)+fabs(VecY[i]-y)*fabs(VecY[i]-y) );
        }
    }
    drawSingle(n,k);
    return k;
}

void objects::drawSingle(int n, int k){ //n-тип ячейки, k-номер
    glUseProgram(shader_obj);
    bindTexture();
    glBindVertexArray(VAO);
    glUniform2f(inc, VecX[k], VecY[k] );
    glUniform1i(type, n);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
    glBindVertexArray(0);
}


void objects::drawUnit(float x, float y, int n){ //n-тип ячейки, k-номер
    glUseProgram(shader_obj);
    bindTexture();
    glBindVertexArray(VAO);
    glUniform2f(inc, x, y );
    glUniform1i(type, n);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT, 0 );
    glBindVertexArray(0);
}

// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

float objects::getVecX(int number){
    return VecX[number];
}

float objects::getVecY(int number){
    return VecY[number];
}

GLuint objects::getVAO(){
    return VAO;
}

GLuint objects::getVAOline(){
    return VAO_line;
}

int objects::getN_Y(){
    return N_Y;
}

int objects::getN_X(){
    return N_X;
}

float objects::getSize_y(){
    return size_y;
}

float objects::getSize_x(){
    return size_x;
}

#endif