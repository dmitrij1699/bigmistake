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
    vector<float> vertices;
    vector<GLuint> indices;
    double time;
    unsigned int money;         //доступные деньги
    vector<int> choice;         //вектор, в который скидываем "покупки"
public:
    choose(double);              //получает на вход временя старта.
    void genDefault();
    void genBySize(float); //принимает размер интерфейса
    int buy(double, double){}; //проверяет покупку. тригеррится при щелчке мыши. возвращает номер покупки.
    void draw();
};

#endif