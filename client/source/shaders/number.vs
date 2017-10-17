#version 330 core

layout (location = 0) in vec2 coord;

uniform vec2 inc;
uniform float size;

void main()
{
	gl_Position = vec4( (coord.x*size)+inc.x, (coord.y*size)+inc.y ,0.0f, 1.0f);
}