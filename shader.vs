#version 330 core
layout(location = 0) in vec3 aPos	// location variable attribute value = 0
layout(location = 1) in vec3 aPos	// color variable attribute value = 1
out vec3 ourColor			// set an OUTPUT for fragment shader
void main()
{
	gl_Position = vec4(aPos,  1.0);	// use vec3 as vec4 constructor's parameter
	ourColor = aColor;		// set output variable to deep red
}