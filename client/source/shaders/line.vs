#version 330 core

layout (location = 0) in vec2 coord;

void main()
{
	gl_Position = vec4(coord,0.0f, 1.0f);
}