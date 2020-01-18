#version 330 core
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

uniform Material material;
// TODO

out vec4 FragColor;

in vec3 LightingColor; 

uniform vec3 objectColor;

void main()
{
	// BASIC LIGHTING PRACTICE 4
	FragColor = vec4(LightingColor * objectColor, 1.0);
}
