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
    void callback();
    void click();

    int* state;
    double* pos_x, *pos_y;

    vector<float> vertices, text;
    vector<GLuint> indices;
    GLuint VAO, shader, type, inc, WIDTH,HEIGHT;

    vector<int> typeT;
    vector<int> price;

    

    GLuint archer,catapult,crossbow,knight,peasant, ram;

    bool release;

    double time, time0;
    int money;         //доступные деньги
    vector<int> choice;         //вектор, в который скидываем "покупки"
public:
    choose(double, bool, double*, double*, int*, GLuint, GLuint);              //получает на вход временя старта.
    void genDefault();
    void genBySize(float); //принимает размер интерфейса
    void buy(int); //проверяет покупку. тригеррится при щелчке мыши. возвращает номер покупки.
    void draw();

};

#endif