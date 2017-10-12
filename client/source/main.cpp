#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libs/SOIL.h"
#include "header/Shader.h"
#include <vector>
#include <cstring> 
#include "header/engine.h"

#include "libs/glm/vector_relational.hpp"
#include "libs/glm/mat4x4.hpp" 
#include "libs/glm/gtc/matrix_transform.hpp" 
#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
GLuint buffersIn();
GLuint Ltext(const char str[]); 
const int F_X=15;
const int F_Y=20;


/*int mfields[F_X][F_Y]={
    //  1  2  3  4  5
        0, 1, 0, 1, 0, //1
        0, 1, 1, 1, 1, //2
        1, 1, 1, 1, 1, //3
        1, 1, 1, 1, 1, //4
        1, 1, 1, 1, 1  //5
    };*/

const GLuint WIDTH = 1280, HEIGHT = 720;
vector<int > fields {
    //  1  2  3  4  5
        0, 1, 0, 1, 0, //1
        0, 1, 1, 1, 1, //2
        1, 1, 1, 1, 1, //3
        1, 1, 1, 1, 1, //4
        1, 1, 1, 1, 1  //5
    };

GLuint VAO;
int main()
{

    
    engine start(WIDTH, HEIGHT, F_X, F_Y,  fields);
    

    return 0;
}