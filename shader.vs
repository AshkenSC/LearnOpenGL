#version 330 core
layout(location = 0) in vec3 aPos;		// location variable attribute value = 0
layout(location = 1) in vec3 aColor;	// color variable attribute value = 1
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;			// set an OUTPUT for fragment shader
out vec2 TexCoord;

uniform float xOffset;
uniform mat4 transform;
// declare transformation matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model *transform * vec4(aPos,  1.0);	// use vec3 as vec4 constructor's parameter
	ourColor = aColor;		
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}