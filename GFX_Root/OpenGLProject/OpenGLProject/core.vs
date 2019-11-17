#version 330 core

attribute vec3 a_vertexPosition;
uniform mat4 u_MVP;

void main()
{
	gl_Position =  u_MVP * vec4(a_vertexPosition, 1);
}
