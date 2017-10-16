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

using namespace std;

class menu{
private:
    vector<string> str;
    vector<GLuint> indices;
    vector<Glfloat> coord;

public:
    void addNewItem(string);
    //int backlight(double, double); 
};
#endif