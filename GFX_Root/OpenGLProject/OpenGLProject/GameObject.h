#pragma once
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	glm::mat4 position, rotation, scale, Model_MAT;
	glm::vec4 color;

	void SetModel(glm::vec3 pos, glm::vec3 rotAxis, GLfloat rotVal, glm::vec3 scl);
};
