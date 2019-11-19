#version 330 core

attribute vec3 a_vertexPosition;
attribute vec2 a_texCoord;

uniform mat4 u_MVP;

out vec2 TexCoord;

void main()
{
	gl_Position =  u_MVP * vec4(a_vertexPosition, 1);
    TexCoord = a_texCoord;
}