#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

// texture transparency
uniform float texTrans;

void main()
{
	//FragColor = vec4(ourColor, 1.0);

	// linearly interpolate between both textures (80% container, 20% awesomeface)
	// add "* vec4(ourColor, 1.0)" behind to make the box colorful
	// practice 1: reverse the direction of the happy face
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(1.0 - TexCoord.x, TexCoord.y)), texTrans);
}