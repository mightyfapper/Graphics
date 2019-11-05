#pragma once
#include <gl/glew.h>
#include "Shader.hpp"
#include <glm/glm.hpp>

#include <iostream>
using namespace std;

class Render
{
public:
	Render();
	~Render();

	GLuint vertexBufferID, PID, vertexPosition_modelspaceID, MVP_ID;
	glm::mat4 MVP_MAT;

	// Generate vertex buffer with vertexBufferID as reference
	// Generate shader program with PID as reference
	// Get reference to vertexPosition_modelspace
	// Get reference to MVP
	void Init();

	// Draws using MVP, MVP_MAT, vertexPosition_modelspace
	void Draw();
	void Cleanup();
};
