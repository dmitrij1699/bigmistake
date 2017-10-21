#version 330 core
layout (location = 0) in vec2 position;

//uniform int typeT;
uniform vec2 move;
uniform vec2 resize;




void main()
{
    gl_Position =vec4(position.x*resize.x, position.y*resize.y, 0.0, 1.0)+vec4(move, 0.0, 0.0);
}
