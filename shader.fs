#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	//FragColor = vec4(ourColor, 1.0);

	// linearly interpolate between both textures (80% container, 20% awesomeface)
	// add "* vec4(ourColor, 1.0)" behind to make the box colorful
	// practice 1: reverse the direction of the happy face
	FragColor = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, vec2(1.0 - TexCoord.x, TexCoord.y)), 0.2);
}