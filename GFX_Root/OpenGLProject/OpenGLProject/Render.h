#pragma once
#include <gl/glew.h>
#include "Shader.hpp"
#include <glm/glm.hpp>

#include <iostream>
using namespace std;

#include "Camera.h"
#include "GameObject.h"

class Render
{
public:
	Render();
	~Render();

	// Renderer needs camera's View and Projection MAT to draw
	Camera *cameraRef;

	// Generate vertex buffer with vertexBufferID as reference
	// Generate shader program with PID as reference
	// Get reference to a_vertexPosition
	// Get reference to u_MVP
	// Get reference to camera to use when drawing
	void Init();

	// Draws using MVP, MVP_MAT, vertexPosition
	void Draw(GameObject *GO);
	void Cleanup();

private:
	GLuint VA_ID, VB_ID, EB_ID, program_ID, vertexPosition_ID, texCoord_ID, texture_ID, MVP_ID;
	glm::mat4 MVP_MAT;
};
