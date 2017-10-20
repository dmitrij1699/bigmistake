#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;

//uniform int typeT;
uniform vec2 inc;
//uniform vec3 size;




void main()
{
    gl_Position =vec4(position,0.0f, 1.0f)+vec4(inc, 0.0f, 0.0f);
}
