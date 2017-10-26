#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libs/SOIL.h"
#include "header/Shader.h"
#include <vector>
#include <cstring> 
#include "header/engine.h"
#include <clocale>
#include <locale>
#include <time.h>   


#include "libs/glm/vector_relational.hpp"
#include "libs/glm/mat4x4.hpp" 
#include "libs/glm/gtc/matrix_transform.hpp" 
#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;



 int F_X=10;
 int F_Y=10;


/*int mfields[F_X][F_Y]={
    //  1  2  3  4  5
        0, 1, 0, 1, 0, //1
        0, 1, 1, 1, 1, //2
        1, 1, 1, 1, 1, //3
        1, 1, 1, 1, 1, //4
        1, 1, 1, 1, 1  //5
    };*/

const GLuint WIDTH = 1280, HEIGHT = 720;
/*vector<int > fields {
    //  4  3  2  1  0
        0, 1, 1, 8, 0, //0
        0, 1, 8, 8, 1, //1
        1, 8, 8, 1, 1, //2
        8, 8, 1, 1, 1, //3
        1, 1, 1, 1, 1  //4
    };*/

    vector<int > fields {
        //  9  8  7  6  5  4  3  2  1  0
            0, 0, 0, 0, 0, 0, 1, 1, 8, 1, //0
            0, 0, 0, 0, 0, 0, 1, 8, 8, 1, //1
            0, 0, 0, 0, 1, 1, 8, 8, 1, 1, //2
            0, 0, 0, 0, 1, 8, 8, 1, 1, 0, //3
            0, 0, 0, 0, 1, 8, 1, 1, 1, 1, //4
            0, 0, 0, 1, 1, 8, 1, 1, 0, 0, //5
            0, 1, 1, 1, 8, 8, 1, 0, 0, 1, //6
            1, 1, 8, 8, 8, 1, 0, 0, 1, 1, //7
            8, 8, 8, 1, 1, 1, 0, 1, 1, 1, //8
            1, 1, 1, 1, 0, 1, 1, 1, 1, 1  //9
        };


void randFields(){
    int g;
    int X_I=0;
    int Y_I=0;    
    fields.clear();
    srand( time(0)+11 );
    int x=15 + rand() % 6;
    srand( time(0)+12 );
    int y=14 + rand() % 6;
    y=10;
    x=y;
    fields.resize(x*y);
    for(int i=0;i<x*y;i++){
        srand( time(0)+g-x );
        if ( (rand() % 2)==0){
            fields[i]=0;
        } else fields[i]=1;
    }
    srand( time(0) );
    g=4+rand() % (x-6);

    fields[g]=8;
    X_I=x-g;

    int kk=0;
    while( X_I<x && Y_I<y){
        srand( time(0)+g-Y_I );
        kk=( rand() % 1000);
        if (kk>500  ) {
            X_I++; //влево
            g=g-1;
            
            fields[g]=8;
    
            
        } else {
            if (g+x >= x*y) break;
            Y_I++; //вниз
            
            g=g+x;
            
            fields[g]=8;
  
        }
        
    }


    while (Y_I>=y && X_I<=x ) {
            g=g-1;
            fields[g]=8;
            X_I++;        
    }


    F_X=x;
    F_Y=y;
    //exit(1);
}



int main()
{
    randFields();
    engine start(WIDTH, HEIGHT, F_X, F_Y,  fields);
    

    return 0;
}