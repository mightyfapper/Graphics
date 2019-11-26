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

	// 3D or 2D
	GLuint obj_Type;
	GLuint buf_Stride;
	GLuint ele_Number;
	GLuint tex_Slot;

	// Current state
	glm::vec3 position, rotation, scale;
	
	glm::vec4 color;
	glm::mat4 Model_MAT;

	// Player needs window reference to get input events
	GLFWwindow *windowRef;
	
	// Sets default value and calls SetModel()
	void InitModel();

	// Sets new values
	void SetPosition(glm::vec3 pos);
	void SetScale(glm::vec3 scl);

	// Uses current values of position
	void Translate(glm::vec3 trn);

	// Uses current rotation
	void Rotate(GLfloat rotVal, glm::vec3 rotAxis);
	
	// Saves MVP calculation
	void SetModel();

private:
	glm::mat4 pos_MAT, rot_MAT, scl_MAT;

};
