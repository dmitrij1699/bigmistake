#ifndef BUKAVKI_H
#define BUKAVKI_H
//Класс для отрисовки текста. Инициализируем. Подаем строку. Передаем координаты(лево центр) и роазмер текста. ВУАЛЯ!

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class bukavki{
private:
    vector<GLuint> indices;
    float size, pos_x, pos_y;
    vector<int> num;

public:
    bukavki(string);  //инициализация. передача строки для отрисовки
    bukavki(string, float); //инициализация. передача строки для отрисовки+размер букв
    bukavki(string, float, float, float); //инициализация. передача строки для отрисовки+размер букв+X и Y вектора смещения
    GLuint getVAO();
    int getNum();
    void addNewChar(char );
};

#endif