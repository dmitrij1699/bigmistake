#ifndef MENU_CPP
#define MENU_CPP
//Класс для создания и отрисовки менюхи

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "header/menu.h"

void menu::addNewItem(string str_in){
    coord.clear();
    indices.clear();
    str[str.size()]=str_in;
    if (str.size()==1 ){
        coord.insert(coord.end(), {-0.75, -0.75, //0
                        0.75,   -0.75, //1
                        0.75,   0.75, //2
                        -0.75,  0.75} ); //3
        indices.insert(indices.end(), {0,1,2, 0,2,3});
    } else {
        float part=(float) 6*str.size()+(str.size()-1);  // 6/6-сам объект, 1/6-растояние между ними
        float diff_y=1.5/part;
        coord[5]=-0.75+6*diff_y;
        coord[7]=coord[5];
        for(int i=1;i< (str.size()-1) ;i++){
            coord.push_back( -0.75 );
            coord.push_back( coord[ 8*(i-1)+5 ]+diff_y);
            coord.push_back( 0.75 );
            coord.push_back( coord[8*(i-1)+5 ]+diff_y);

            coord.push_back( -0.75 );
            coord.push_back( coord[ 8*i+1 ]+6*diff_y);
            coord.push_back( 0.75 );
            coord.push_back( coord[ 8*i+1 ]+6*diff_y);

            indices.push_back(4*i);
            indices.push_back(4*i+1);
            indices.push_back(4*i+2);
            indices.push_back(4*i+1);
            indices.push_back(4*i+2);
            indices.push_back(4*i+3);
        }
    }

}



#endif