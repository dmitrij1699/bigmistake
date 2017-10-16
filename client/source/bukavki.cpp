#ifndef BUKAVKI_CPP
#define BUKAVKI_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/bukavki.h"
#include <string>
#include <vector>
#include "header/Shader.h"

using namespace std;
//Класс для отрисовки текста. Инициализируем. Подаем строку. Передаем координаты(лево центр) и роазмер текста. ВУАЛЯ!

/*bukavki::bukavki(string str, float size_in, float pos_x_in, float pos_y_in):size(size_in),pos_x(pos_x_in),pos_y(pos_y_in) {
    cout<<str<<endl;
    for(int i=0;i<str.size();i++){
        cout<<str[i] <<"??"<<endl;
        wchar_t kk[]={'У','\0'};
        cout<< kk<<endl;
        addNewChar(str[i] );
    }
    char x=0;
    
    for(int i=0;i<255;i++){
        x+=1;
        cout<<x;
    }
    cout<<endl;
}*/


bukavki::bukavki(vector<int> str, float size_in, float pos_x_in, float pos_y_in):size(size_in),pos_x(pos_x_in),pos_y(pos_y_in) {
    
    for(int i=0;i<str.size();i++){
        cout<<str[i] <<"??"<<endl;
        addNewChar(str[i] );
    }
}

void bukavki::addNewChar(int next){
    cout<<"!!!!!!!!!!!"<<next<<"!!!!!!!!!!!"<<endl;
    switch (next){
        case 0:
            indices.insert(indices.end(),{
                              0,5,
                              5,14,
                              15,16 });
            num.push_back(3);
            cout<<"Мы здеся1!1"<<endl;
            break;
        case 1:
            indices.insert(indices.end(),{
                              4,10,
                              4,0,
                              0,14,
                              14,12,
                              2, 12 });
            num.push_back(5); 
            break;
    }
}

/*void bukavki::addNewChar(char next){
    cout<<"!!!!!!!!!!!"<<next<<"!!!!!!!!!!!"<<endl;
    switch (next){
        case 'А':
            indices.insert(indices.end(),{
                              0,5,
                              5,14,
                              15,16 });
            num.push_back(3);
            cout<<"Мы здеся1!1"<<endl;
            break;
        case 'Б':
            indices.insert(indices.end(),{
                              4,10,
                              4,0,
                              0,14,
                              14,12,
                              2, 12 });
            num.push_back(5); 
            break;
    }
    for(int i=0; i<num.size();i++){
        //coit<<"nim["<<i<<"]="<<
    }
}*/

void bukavki::setVAO(){

    cout<<"Загрузка шейдерной програмы BUKAVKI..."<<endl;
    Shader olol("../source/shaders/bukavki.vs", "../source/shaders/bukavki.frag");
    shader= olol.Program;
    cout<<"Загрузка прошла успешно!"<< endl;

    vector<float> bias;

    cout<<"incoming.."<<endl;

    vector<float> default_vec {
        0,  -1,     //0
        0,  -0.5,   //1
        0,  0,      //2
        0,  0.5,    //3
        0,  1,      //4
        0.5,1,      //5
        0.5,0.5,    //6
        0.5,0,      //7
        0.5,-0.5,   //8
        0.5,-1,     //9
        1,  1,      //10
        1,  0.5,    //11
        1,  0,      //12
        1,  -0.5,   //13
        1,  -1,     //14
        0.25,0,     //15
        0.75,0,     //16
        0.75,1,     //17
        1,  0.75,   //18
        1,  0.25,   //19
        1,  -0.25,  //20
        1,  -0.75,  //21
        0.75,-1,    //22
        0.25,-0.25, //23
        0.75,-0.25, //24
        0,  -0.75,  //25
        0,75,-0.75  //26
    };


    cout<<"incoming.."<<endl;

    for(int i=0;i<default_vec.size();i++){
        default_vec[i]=default_vec[i]*size;
    }

    cout<<"incoming.."<<endl;
    for(int i=0;i<default_vec.size()/2;i++){
        //for(int  g=bias.end(); ( g-bias.size() )<num[i] ;g++){
            //bias.push_back( (float) i*size) ;
            bias.push_back(0) ;
            cout<<"bias["<<i<<"]="<<bias[i]<< endl;
        //}
    }
    cout<<"incoming.."<<endl;

    GLuint VBO[2], EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);
    GLuint position= VBO[0];
    GLuint biASS= VBO[1];

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glBufferData(GL_ARRAY_BUFFER,default_vec.size()* sizeof(default_vec), &default_vec[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, biASS);
    glBufferData(GL_ARRAY_BUFFER,bias.size()* sizeof(bias), &bias[0], GL_STATIC_DRAW);


    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()* sizeof(indices), &indices[0], GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    

    glBindBuffer(GL_ARRAY_BUFFER, position);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, biASS);
    glVertexAttribPointer(0, 1, GL_FLOAT, GL_FALSE, 0, NULL);

    glBindVertexArray(0); // Unbind VAO
}

void bukavki::draw(){
    glUseProgram(shader);
    glBindVertexArray(VAO);
    cout<<"DRAW COUNT="<<getNum()<<endl;
    glDrawElements(GL_LINES, getNum(), GL_UNSIGNED_INT,0 );
    glBindVertexArray(0);
}

int bukavki::getNum(){
    int sum=0;
    for(int i=0; i<num.size();i++){
        cout<<"num[i]="<<num[i]<< endl;
        sum+=num[i];
    }
    return sum;
}

#endif