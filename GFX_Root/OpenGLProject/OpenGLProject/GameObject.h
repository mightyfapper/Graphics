#pragma once
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>
#include "Window.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	// Current state
	glm::vec3 position, rotation, scale;
	
	glm::vec4 color;
	glm::mat4 Model_MAT;
	
	// Sets new values
	void SetPosition(glm::vec3 pos);
	void SetRotate(GLfloat rotVal, glm::vec3 rotAxis);
	void SetScale(glm::vec3 scl);
	void SetColor(glm::vec4 clr);

	// Uses previous values of position
	void Translate(glm::vec3 trn);
	
	// Saves MVP calculation
	void SetModel();

	// This activates that this moves
	// +X is right
	// +Y is forward
	// +Z is up
	void ActivateMovement(Window* win, GLfloat speed);

private:
	glm::mat4 pos_MAT, rot_MAT, scl_MAT;
};
