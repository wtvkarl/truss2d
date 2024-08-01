#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 colorOut;

void main()
{
	gl_Position = vec4(position.x * 0.5, position.y * 0.5, position.z * 0.5, 1.0f);
	colorOut = color;
}