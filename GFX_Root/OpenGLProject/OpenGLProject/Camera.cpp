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

void Camera::SetView(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	View_MAT = glm::lookAt(
		eye,	// Camera in World Space
		center,	// and looks at the origin
		up		// Head up direction
	);
}