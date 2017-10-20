#ifndef healthbar_H
#define healthbar_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

using namespace std;


class healthbar{
private:
    float x, y, size_x, size_y, health;

public:
    void in(float, float, float, float, float); // x, y, size_x, size_y, %health
};




#endif