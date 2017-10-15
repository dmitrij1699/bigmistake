#version 330 core

layout (location = 0) in vec2 coord;
layout (location = 0) in vec1 bias;

void main()
{
	gl_Position = vec4(coord.x+bias, coord.y ,0.0f, 1.0f);
}