#pragma once
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 Projection_MAT, View_MAT;

	void SetProjection(float fovy, float aspect, float zNear, float zFar);
	
	// pos: Camera position in World Space
	// look: What it looks at
	// Up: Up direction
	void SetView(glm::vec3 pos, glm::vec3 look, glm::vec3 up);
};
