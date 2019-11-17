#include "GameObject.h"

GameObject::GameObject()
{
	pos_MAT = glm::mat4();
	rot_MAT = glm::mat4();
	scl_MAT = glm::mat4();
	Model_MAT = glm::mat4();

	// Defaults
	position = glm::vec3();
	color = glm::vec4(0, 0, 0, 1);

	InitModel();
}

GameObject::~GameObject()
{

}

void GameObject::InitModel()
{
	pos_MAT = glm::translate(glm::vec3(0.f));
	rot_MAT = glm::rotate(0.f, glm::vec3(1.f));
	scl_MAT = glm::scale(glm::vec3(1.f));

	SetModel();
}

void GameObject::SetPosition(glm::vec3 p)
{
	// Save position
	position[0] = p[0];
	position[1] = p[1];
	position[2] = p[2];

	pos_MAT = glm::translate(position);
	SetModel();
}

void GameObject::Rotate(GLfloat rVal, glm::vec3 rAxis)
{
	// From degree to rad
	GLfloat rad = (rVal * 3.14f) / 180;

	rot_MAT = glm::rotate(rad, rAxis);
	SetModel();
}

void GameObject::SetScale(glm::vec3 s)
{
	scl_MAT = glm::scale(s);
	SetModel();
}

void GameObject::Translate(glm::vec3 t)
{
	// Save position
	position[0] += t[0];
	position[1] += t[1];
	position[2] += t[2];

	pos_MAT = glm::translate(position);
	SetModel();
}

void GameObject::SetColor(glm::vec4 c)
{
	color = c;
}

void GameObject::SetModel()
{
	Model_MAT = rot_MAT * pos_MAT * scl_MAT;
}

void GameObject::ActivateMovement(GLfloat speed)
{
	if (glfwGetKey(windowRef, GLFW_KEY_UP) == GLFW_PRESS)
	{
		Translate(glm::vec3(0, speed, 0));
	}

	if (glfwGetKey(windowRef, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		Translate(glm::vec3(0, -speed, 0));
	}

	if (glfwGetKey(windowRef, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		Translate(glm::vec3(speed, 0, 0));
	}

	if (glfwGetKey(windowRef, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		Translate(glm::vec3(-speed, 0, 0));
	}
}
