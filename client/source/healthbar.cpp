#ifndef healthbar_CPP
#define healthbar_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "header/objects.h"
#include "libs/SOIL.h"
#include "header/Shader.h"
#include "header/healthbar.h"
#include <vector>
#include <cmath>

using namespace std;

void healthbar::in(float x_in, float y_in, float size_x_in, float size_y_in, float health_in){
    x=x_in;
    y=y_in;
    size_x=size_x_in;
    size_y=size_y_in;
    health=health_in;
    
}


#endif