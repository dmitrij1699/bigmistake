#ifndef CHOOSE_CPP
#define CHOOSE_CPP
//Класс для выбора. Обменивается данными с сервером с сервером, визуализирует интерфейс. 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "header/choose.h"
using namespace std;

void choose::genBySize(float size){}

void choose::genDefault(){
    vertices.insert(vertices.end(),{
        -0.225, -1, //0
        -0.075, -1, //1
        0.075,  -1, //2
        0.225,  -1, //3
        -0.225, -0.85, //4
        -0.075, -0.85, //5
        0.075,  -0.85, //6
        0.225,  -0.85 //7
    });
    indices.insert(indices.end(){
        0, 1, 5,
        0, 4, 5,
        1, 5, 6,
        1, 6, 2,
        2, 3, 7, 
        2, 6, 7
    });
}

choose::choose(double dtime):time(dtime){
    genDefault();
}

#endif