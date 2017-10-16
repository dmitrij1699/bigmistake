#version 330 core

layout (location = 0) in vec2 coord;

uniform float size;
uniform float biass;
uniform vec2 inc;

void main()
{
	gl_Position = vec4( (coord.x*size)+biass+inc.x , (coord.y*size)+inc.y ,0.0f, 1.0f);
}
