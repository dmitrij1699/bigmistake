#version 330 core
in vec2 TexCoord;

out vec4 color;


uniform sampler2D dirt;
uniform sampler2D grass;

uniform int typeT;

void main()
{
	switch(typeT) {
        case 0:{
            color=(0.0f, 0.0f, 0.0f, 1.0f);
            break;
        }
		case 1:{
			color = texture(dirt, TexCoord);
			break;
		}
		default:{
			color = texture(grass, TexCoord);
			break;
		}
	}
	
}