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
#include "header/objects.h"
#include <algorithm>


using namespace std;

GLuint Ltext(const char str[]);

void choose::genBySize(float size){}

void choose::genDefault(){
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

choose::choose(double dtime, bool type, double* x, double* y, int* state, GLuint W, GLuint H, int *fields, int *process, int F_X, int F_Y)
    :time(dtime), pos_x(x), pos_y(y), state(state),WIDTH(W),HEIGHT(H), typeA_D(type), process(process), fields(fields), F_X(F_X), F_Y(F_Y) {
    OBJ=new objects(&fields[0],F_X, F_Y);
    buy_proc=false;
    if (typeA_D) {
        price={3,5,2};
        typeT={5, 6, 7};
    } else {
        typeT={2, 3, 4};
        price={3,5,2};
    }
    release=true;
    cout<<"price[0]="<<price[0]<<endl;
    time0=time+31;
    money=35;
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
    callback();
    time=time0-glfwGetTime();
    if (buy_proc==false || typeA_D){
    OBJ->draw();
    for(int i=0;i<coord_choice.size();i++) {
        OBJ->drawSingle(choice[i],coord_choice[i] );
    }
    drawVariables();
    } else {
        drawBuy();
    }
    drawNum();
    callback();
    if(time<0 ) *process=2;
}

void choose::callback(){

        if( *state==GLFW_PRESS && release){
            release=false;
            if(buy_proc== false){
                click();
            } else {
                if(  ( fields[F_X*F_Y-coord_choise-1]!=8) && (coord_choice.end()==find(coord_choice.begin(), coord_choice.end(), coord_choise) ) ){
                    buy_proc=false;
                    coord_choice.push_back(coord_choise);
                }
            }
        } else
        if( *state==GLFW_RELEASE ) {
            release=true;
        }
}

void choose::drawNum(){
    numbers num;
    num.drawNum((int) time/10, 0.05, -0.03, 0.93);
    num.drawNum(time- ( (int) time/10)*10, 0.05, 0.03, 0.93);

    num.drawNum( (int) money/10 , 0.05, 0.905, 0.0);       
    num.drawNum( money- ( (int) money/10)*10, 0.05, 0.965, 0.0);
}

void choose::click(){
    float x=(float) *pos_x/WIDTH;
    x=x*2;
    if( x<= 1 ){
        x=1-x;
        x=x*(-1);
    } else {
        x=x-1;
    }
    
    float y=(float) *pos_y/HEIGHT;
    y=y*2;
    if( y>= 1 ){
        y=y-1;
        y=y*(-1);
    } else {
        y=1-y;
    }
    cout<<"HEIGHT="<<HEIGHT<<", WIDTH="<<WIDTH<< endl;
    cout<<"x="<<x<<", y="<<y<< endl;
    if( (y>=-1.0) && (y<=-0.85) )
        if ( (x>=-0.225) && (x<=-0.075)){
            buy(0);
        } else {
        if ( ( x>=-0.065 ) && ( x<=0.085 )){
            buy(1);
        } else {
        if ( ( x>=0.095 ) && ( x<=0.245 )){
            buy(2);
        } }}
}



void choose::buy(int i){
    cout<<"buy("<<i<<")"<<endl;
    cout<<money<<"wtf??"<<endl;
    cout<<"money="<<money<<endl;
    cout<<"price[i]="<<price[i]<<endl;
    cout<<( money  - price[i]) << endl;
    if ( ( money  - price[i])>=0 ){
        buy_proc=true;
        money=( money  -price[i]);
        cout<<"money="<<money<<endl;
        choice.push_back(typeT[i]);
    }
}

void choose::drawBuy(){
    float x=(float) *pos_x/WIDTH;
    x=x*2;
    if( x<= 1 ){
        x=1-x;
        x=x*(-1);
    } else {
        x=x-1;
    }
    
    float y=(float) *pos_y/HEIGHT;
    y=y*2;
    if( y>= 1 ){
        y=y-1;
        y=y*(-1);
    } else {
        y=1-y;
    }

    OBJ->draw();
    for(int i=0;i<coord_choice.size();i++) {
        OBJ->drawSingle(choice[i],coord_choice[i] );
    }
    for(int i=0;i<coord_choice.size();i++) {
        OBJ->drawSingle(choice[i],coord_choice[i] );
    }
    coord_choise=OBJ->changeField(x, y, choice.back() );
    
}

void choose::getDefence(int *vec, int *size){
    vector<int> newbee;
    for(int i=0; i<choice.size();i++){
        newbee.push_back(coord_choice[i]);
        newbee.push_back(choice[i]);
    }
    *size=newbee.size();
    vec[]=newbee;
}

#endif