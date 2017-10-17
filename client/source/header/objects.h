#ifndef OBJECTS_H
#define OBJECTS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;

class objects {
private:
    GLuint dirt, grass,archer,catapult,crossbow,knight,peasant,ram,road;
    int *fields;
    vector<float> default_vec;
    vector<float> vertices;
    vector<GLuint> indices; //порядок отрисовки
    vector<float> text;
    vector<float> VecX;
    vector<float> VecY;
    GLuint VAO, EBO;
    GLuint VAO_line , EBO_line;
    GLuint shader_obj,shader_line ;
    GLint inc, type;
    int N_X, N_Y;
    float size_x, size_y;
    void defv();
    void defVAO();
    void defVAOline();
    void drawUnits();
    void drawLines();
    void texture_use();
    void bindTexture();
    
public:
    //           objects(int X,int Y):N_X(X), N_Y(Y){};
    objects(int *fields, int x, int y);

    void drawSingle(int, int);
    int changeField(float, float, int);
    void draw();
    int getN_X();
    int getN_Y();
    int getCount(){return 1;};
    float getVecX(int number);          // Возвращает икс вектора для умножения
    float getVecY(int number);          // Возвращает игрик вектора для умножения
    //vector<float> getLine(int number){};  // Возваращет массив с 4 координатами объекта (всего 8 чисел: xyxyxyxy)
    //vector<float> getBuff(){};            // Возвращает готовый буффер для открисовки объектов
    vector<float> GetDefault();
    GLuint getVAO();
    GLuint getVAOline();
};







#endif