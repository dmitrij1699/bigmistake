#ifndef BUKAVKI_H
#define BUKAVKI_H
//Класс для отрисовки текста. Инициализируем. Подаем строку. Передаем координаты(лево центр) и роазмер текста. ВУАЛЯ!

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "Shader.h"
using namespace std;

class bukavki{
private:
    GLuint VAO, shader;
    vector<GLuint> indices;
    float size, pos_x, pos_y;
    vector<int> num;    //сколько рисуется линий для отрисовки i-ой буквы
    GLint biass, inc, size_un;

public:
    bukavki(string);  //инициализация. передача строки для отрисовки
    bukavki(string, float); //инициализация. передача строки для отрисовки+размер букв
    //bukavki(string, float, float, float); //инициализация. передача строки для отрисовки+размер букв+X и Y вектора смещения
    bukavki(vector<int>, float, float, float);
    void setVAO();
    int getNum();
    //void addNewChar(char );
    void addNewChar(int );
    void draw();
};

#endif