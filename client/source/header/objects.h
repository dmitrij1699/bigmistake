#ifndef OBJECTS_H
#define OBJECTS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class objects {
private:
    vector<float> default_vec;
    vector<float> vertices;
    vector<GLuint> indices; //порядок отрисовки
    vector<float> text;
    vector<float> VecX;
    vector<float> VecY;
    GLuint VAO, EBO;
    int N_X, N_Y;
    float size_x, size_y;
    void defv();
    void defVAO();
public:
    //           objects(int X,int Y):N_X(X), N_Y(Y){};

    void in(int x, int y);
    int getN_X();
    int getN_Y();
    int getCount(){return 1;};
    float getVecX(int number);          // Возвращает икс вектора для умножения
    float getVecY(int number);          // Возвращает игрик вектора для умножения
    //vector<float> getLine(int number){};  // Возваращет массив с 4 координатами объекта (всего 8 чисел: xyxyxyxy)
    //vector<float> getBuff(){};            // Возвращает готовый буффер для открисовки объектов
    vector<float> GetDefault();
    GLuint getVAO();

};







#endif