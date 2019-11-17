#include "Camera.h"

Camera::Camera()
{
	Projection_MAT = glm::mat4();
	View_MAT = glm::mat4();
}

Camera::~Camera()
{

}

void Camera::SetProjection(float fovy, float aspect, float zNear, float zFar)
{
	Projection_MAT = glm::perspective(fovy, aspect, zNear, zFar);
}

void Camera::SetView(glm::vec3 pos, glm::vec3 look, glm::vec3 up)
{
	View_MAT = glm::lookAt(
		pos,
		look,
		up
	);
}