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
	glm::vec3 position;
	
	glm::vec4 color;
	glm::mat4 Model_MAT;

	GLFWwindow *windowRef;
	
	// Sets default value and calls SetModel()
	void InitModel();

	// Sets new values
	void SetPosition(glm::vec3 pos);
	void SetScale(glm::vec3 scl);
	void SetColor(glm::vec4 clr);

	// Uses current values of position
	void Translate(glm::vec3 trn);

	// Uses current rotation
	void Rotate(GLfloat rotVal, glm::vec3 rotAxis);
	
	// Saves MVP calculation
	void SetModel();

	// This activates that this moves
	// +X is right
	// +Y is forward
	// +Z is up
	void ActivateMovement(GLfloat speed);

private:
	glm::mat4 pos_MAT, rot_MAT, scl_MAT;
};
