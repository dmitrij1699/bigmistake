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


#include "libs/glm/vector_relational.hpp"
#include "libs/glm/mat4x4.hpp" 
#include "libs/glm/gtc/matrix_transform.hpp" 
#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
GLuint buffersIn();
GLuint Ltext(const char str[]); 
const int F_X=10;
const int F_Y=10;


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

GLuint VAO;
int main()
{

    
    
    engine start(WIDTH, HEIGHT, F_X, F_Y,  fields);
    

    return 0;
}