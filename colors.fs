#version 330 core
out vec4 FragColor;

in vec3 LightingColor; 

uniform vec3 objectColor;

void main()
{
	// BASIC LIGHTING PRACTICE 4
	FragColor = vec4(LightingColor * objectColor, 1.0);
}
