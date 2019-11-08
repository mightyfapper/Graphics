#include "GameObject.h"

GameObject::GameObject()
{
	position = glm::mat4();
	rotation = glm::mat4();
	scale = glm::mat4();

	Model_MAT = glm::mat4();

	color = glm::vec4();
}

GameObject::~GameObject()
{

}

void GameObject::SetModel(glm::vec3 pos, glm::vec3 rotAxis, GLfloat rotVal, glm::vec3 scl)
{
	position = glm::translate(pos);

	glm::vec3 myRotationAxis(rotAxis); // about the ?-axis
	rotation = glm::rotate(rotVal, myRotationAxis);

	scale = glm::scale(scl);

	Model_MAT = rotation * position * scale;
}