#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libs/SOIL.h"
#include "header/Shader.h"
#include <vector>

#include "libs/glm/vector_relational.hpp"
#include "libs/glm/mat4x4.hpp" 
#include "libs/glm/gtc/matrix_transform.hpp" 
#include "libs/glm/gtc/type_ptr.hpp"

using namespace glm;
using namespace std;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
GLuint buffersIn();
GLuint Ltext(const char str[]); 

const GLuint WIDTH = 1280, HEIGHT = 720;
const int F_X=25;
const int F_Y=25;
uint fields[F_X][F_Y];
GLuint VAO;
int main()
{

    float in_x=(float) 2/F_X;
    float in_y=(float) 2/F_Y;
    cout<< "in_x= "<<in_x <<endl;
    float position_x[F_X];
    float position_y[F_Y];
    position_x[0]=-1;
    position_y[0]=-1;
    for (int i=1; i<F_X; i+=1){
        position_x[i]=position_x[i-1]+in_x;
        cout<< "position=" << position_x[i]<< endl;
        
    }
    for (int i=1; i<F_Y; i+=1){
        position_y[i]=position_y[i-1]+in_y;
    }

    /*float position[F_X][F_Y];
    position[0][0]=0;
    for(int x=0; x<F_X; x+=1){
        position[x][0]=0;
        for(int y=1; y<F_Y; y+=1){
            position[x][y]=position[x][y-1]+in_y;
        }
        position[x-1]
    }*/

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



    VAO= buffersIn();

    GLuint texture1;
    GLuint texture2;

    texture1= Ltext("../Textures/dirt.png");
    texture2= Ltext("../Textures/grass.png");

    while (!glfwWindowShouldClose(window))
    {
        
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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
        int g=0;
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
}