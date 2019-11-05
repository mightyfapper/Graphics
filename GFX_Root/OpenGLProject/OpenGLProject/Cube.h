#pragma once
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

class Cube
{
public:
	Cube();
	~Cube();

	glm::mat4 position, rotation, scale, Model_MAT;

	// Loads verts into vertex buffer
	void Init();

	void SetModel(glm::vec3 pos, glm::vec3 rotAxis, GLfloat rotVal, glm::vec3 scl);
};
