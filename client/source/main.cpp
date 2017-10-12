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

    /*float in_x=(float) 2/F_X;
    float in_y=(float) 2/F_Y;
    cout<< "in_x= "<<in_x <<endl;
    float position_x[F_X];
    float position_y[F_Y];
    position_x[0]=-1;
    position_y[0]=-1;
    for (int i=1; i<=F_X; i++){
        position_x[i]=position_x[i-1]+in_x;
        
        
    }
    for (int i=1; i<=F_Y; i++){
        position_y[i]=position_y[i-1]+in_y;
    }
    for (int i=0; i<=F_X; i++){
        cout<< "position_x= " << position_x[i];
        cout<< ";  position_y=" << position_y[i]<< endl;
    }
    float position[F_X][F_Y];
    position[0][0]=0;
    for(int x=0; x<F_X; x+=1){
        position[x][0]=0;
        for(int y=1; y<F_Y; y+=1){
            position[x][y]=position[x][y-1]+in_y;
        }
        position[x-1]
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WIDTH, HEIGHT);


    Shader ourShader("../source/shaders/shader.vs", "../source/shaders/shader.frag");
    cout<< "ошибка??"<< endl;
    Shader lineShader("../source/shaders/line.vs", "../source/shaders/line.frag");


    VAO= buffersIn();

    GLuint texture1;
    GLuint texture2;

    texture1= Ltext("../Textures/dirt.png");
    texture2= Ltext("../Textures/grass.png");


    GLfloat verticesL[F_X*6-6];
    for(int i=0; i<F_X; i++) {
        verticesL[i*6]=position_x[i+1]; //x
        verticesL[1+i*6]=-1.0f; //y
        verticesL[2+i*6]=0.0f; //z
        verticesL[3+i*6]=position_x[i+1];
        verticesL[4+i*6]=1.0;
        verticesL[5+i*6]=0.0f;


        cout<<i << "Линия. Начало: x="<< verticesL[i] <<"; y=" <<verticesL[1+i]<< ". Конец: x="<<verticesL[3+i]<< "; y="<<verticesL[4+i] << endl;
    }
    GLfloat LV[]={
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    GLuint LVAO, BverticesL;
    glGenVertexArrays(1, &LVAO);
    glGenBuffers(1, &BverticesL);
    glBindVertexArray(LVAO);
    glBindBuffer(GL_ARRAY_BUFFER, BverticesL);
    glBufferData(GL_ARRAY_BUFFER,sizeof(verticesL), verticesL, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,  3 * sizeof(GLfloat), NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    

    while (!glfwWindowShouldClose(window))
    {
        
        glfwPollEvents();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        ourShader.Use();   


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glUniform1i(glGetUniformLocation(ourShader.Program, "dirt"), 0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);
        glUniform1i(glGetUniformLocation(ourShader.Program, "grass"), 1);  
        
        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint typeTLoc = glGetUniformLocation(ourShader.Program, "typeT");
        glBindVertexArray(VAO);

        fields[0][2]=1;
        fields[0][1]=1;
        fields[0][3]=1;
        fields[0][4]=1;
        for (int x=0; x<F_X; x+=1){
            for(int y=0; y<F_Y; y+=1){
                if (x<=6) fields[x][y]=1;
                switch( fields[x][y] ){  
                    case 1: {
                        mat4 model;
                        model = translate(model, vec3(position_x[x], position_y[y], 0));
                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
                        glUniform1i(typeTLoc, fields[x][y] );
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                    }   
                    default: { 
                        mat4 model;
                        model = translate(model, vec3(position_x[x], position_y[y], 0));
                        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(model));
                        glUniform1i(typeTLoc,  fields[x][y] );
                        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                        }
                    }
            }
        } 

        glBindVertexArray(0); 

        //cout<<"мы тут" <<endl;
        lineShader.Use();
        glBindVertexArray(LVAO);

        //glDrawArrays(GL_LINES, 0​, F_X*3-3​);
        
        glDrawArrays(GL_LINES,0,40);
        //glDrawElements(GL_LINES,F_X, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &VAO);
    glfwTerminate();
    return 0;
} 


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
} */

    //uint  **ek= *fields[F_Y] ; 
    //cout << fields[0][0] <<endl;
    engine start(WIDTH, HEIGHT, F_X, F_Y,  fields);
    

    return 0;
}