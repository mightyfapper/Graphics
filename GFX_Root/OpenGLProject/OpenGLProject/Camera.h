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
	void SetView(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
};

