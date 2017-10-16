#ifndef MENU_H
#define MENU_H
//Класс для создания и отрисовки менюхи. Создаем класс. 
//После каждым новым вызовом "addNewItem" добавляем следующий пункт и передаем строку для отрисовки в нем
// "backlight" -принимает позицию курсура. и выдает номер "объекта", который должен быть подсвечен

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "bukavki.h"

using namespace std;

class menu{
private:
    GLuint VAO;
    vector<string> str;
    vector<int> strI;
    vector<GLuint> indices;
    vector<GLfloat> coord;
    GLuint shader;
    void drawPoints();
    void drawWords();

public:
    void addNewItem(string);
    void addNewItem(vector<int>);
    void createVAO();
    void draw();
    //int backlight(double, double); 
};
#endif