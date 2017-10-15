#ifndef ENGINE_CPP
#define ENGINE_CPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "header/engine.h"
#include "header/objects.h"
#include "header/Shader.h"
#include "libs/SOIL.h"
#include <vector>
#include <iostream>
#include "header/buff.h"
#include "header/numbers.h"
#include "header/calc.h"

#include "libs/glm/gtc/type_ptr.hpp"


using namespace glm;
using namespace std;


calc::calc(vector<int> AT,vector<int> fields,double time):time(time),AT(AT),fields(fields){
    def_2.set(0.75,1, 3, 1);  //скорость, урон, радиус, стоимость
    def_3.set(0.2,5, 15, 10);
    def_4.set(0.5,1.75, 6, 4);


    at_5.set(0.75, 10, 5); //скорость, хелсы, стоимость
    at_6.set(1.25, 4, 1); 
    at_7.set(0.4, 20, 10); //////
}
   
int calc::ff(int x, int y){
    return fields[y*F_X+x];
}


void calc::road(){
    

}

#endif