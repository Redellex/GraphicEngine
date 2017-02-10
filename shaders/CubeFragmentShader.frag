#version 330 core
in vec3 Kolor;
out vec4 color;

uniform vec3 choosenColor;

void main()
{
        color = vec4(choosenColor, 0.5f);
}