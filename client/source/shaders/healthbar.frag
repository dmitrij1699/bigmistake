#version 330 core
in vec2 TexCoord;

out vec4 color;

uniform int colorU;

void main()
{
switch (colorU) {
    case 0:
        color=vec4(0.0f, 0.0f, 0.0f, 0.0f);
        break;
    case 1:
        color=vec4(0.0f, 1.0f, 0.0f, 0.0f);
        break;
    }
}