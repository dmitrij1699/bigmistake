#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec2 line;


uniform int typeT;
uniform vec3 inc;
uniform vec3 size;

out vec2 TexCoord;

void main()
{
    switch(typeT) {
        case 0:{
            gl_Position =vec4( line,0.0f, 1.0f);
            break;
        }
        default:{
            gl_Position =vec4( (position*size+inc), 1.0f);
	        TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
            break;
        }
    }

}