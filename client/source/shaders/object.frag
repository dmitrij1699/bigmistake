#version 330 core
in vec2 TexCoord;

out vec4 color;


uniform sampler2D dirt;
uniform sampler2D grass;
uniform sampler2D archer;
uniform sampler2D catapult;
uniform sampler2D crossbow;
uniform sampler2D knight;
uniform sampler2D peasant;
uniform sampler2D ram;
uniform sampler2D road;

uniform int typeT;

void main()
{
	switch(typeT) {
        case 0:{
            color = texture(dirt, TexCoord);
            break;
        }
		case 1:{
			color = texture(grass, TexCoord);
			break;
		}
		case 2:{
			color = texture(archer, TexCoord);
			break;
		}
		case 3:{
			color = texture(catapult, TexCoord);
			break;
		}
		case 4:{
			color = texture(crossbow, TexCoord);
			break;
		}
		case 5:{
			color = texture(knight, TexCoord);
			break;
		}
		case 6:{
			color = texture(peasant, TexCoord);
			break;
		}
		case 7:{
			color = texture(ram, TexCoord);
			break;
		}
		case 8:{
			color = texture(road, TexCoord);
			break;
		}
		default:{
			color=vec4(0.0f, 0.0f, 0.0f, 0.0f);
			break;
		}
	}
	
}