#ifndef CHOOSE_H
#define CHOOSE_H
//Класс для выбора. Обменивается данными с сервером с сервером, визуализирует интерфейс. 

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "numbers.h"
using namespace std;

class choose{
private:
    void drawNum();
    void drawVariables();
    void VAOvariables();
    void textureSet();

    vector<float> vertices, text;
    vector<GLuint> indices;
    GLuint VAO, shader, type, inc;

    vector<int> typeT;

    GLuint archer,catapult,crossbow,knight,peasant, ram;

    double time, time0;
    unsigned int money;         //доступные деньги
    vector<int> choice;         //вектор, в который скидываем "покупки"
public:
    choose(double, bool);              //получает на вход временя старта.
    void genDefault();
    void genBySize(float); //принимает размер интерфейса
    int buy(double, double){}; //проверяет покупку. тригеррится при щелчке мыши. возвращает номер покупки.
    void draw();

};

#endif