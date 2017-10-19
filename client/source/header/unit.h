#ifndef UNIT_H
#define UNIT_H

#include <vector>
#include "objects.h"

using namespace std;


class unit{
protected:
    GLuint shader, inc,type;

    struct par_str{
        float speed;          //скорость
        float pos;          //текущая позиция НА ДОРОГЕ/ инициализируется -1.
        int health;         //здоровье
    };
  
    vector<par_str> un;
    vector<int> fields;
    int F_X, F_Y;
    double old_time,time, dtime;
    vector<int> attack, *defence;
    objects *OBJ;
    vector<float> roadX, roadY;
    vector<int> roadV;
    int length;
    bool empty; //"чиcтота 0 клетки"
    double empty_time; //сколько времени "0" клетка была пустой
public:
    void in(vector<int>,vector<int>,vector<int> *, int, int, double); //fields/attack/OBJ/F_X/F_Y/ time
    void ifDanger(float, float);     //проверка получения дамага юнитом->вызов getDamage. координата юнита X/координата юнита Y. 
    void getDamage(bool, int, int){};  //получение дамага юнитом. время/ номер юнита /номер башни
    void getDamage(int, int){};  //получение дамага юнитом. номер юнита /номер башни
    void getDamage(){};          // 
    void move();          //перемещает (int) юнит на след. позицию
    void default_value(); //заполняет каждый юнит дефолтным значением
    void road();                     //вычисление "дороги"
    void calc(double);               //получаем время, вычисляем все параметры
    float getVecX(int);
    float getVecY(int);
    int nf(int, int);
    int ch(int);
    int convert(int);
    void draw();
    
    
    //Методы для тестов(инициализация)
    void testMove();



    //(получение параметров)

};

#endif
/*


*/