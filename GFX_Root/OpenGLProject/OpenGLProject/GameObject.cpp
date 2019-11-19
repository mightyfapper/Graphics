#include "GameObject.h"

GameObject::GameObject()
{
	obj_Type = 0;
	buf_Stride = 0;
	ele_Number = 0;
	tex_Slot = 0;

	pos_MAT = glm::mat4();
	rot_MAT = glm::mat4();
	scl_MAT = glm::mat4();
	Model_MAT = glm::mat4();

	// Defaults
	position = glm::vec3();
	rotation = glm::vec3();

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

void GameObject::Rotate(GLfloat rVal, glm::vec3 rAxis)
{
	float temp;

	for(int i=0; i<3; i++)
	{
		temp = rVal * rAxis[i];
		// If not set
		if (temp == 0)
			continue;

		// Else
		rotation[i] += temp;

		// From degree to rad
		GLfloat rad = (rotation[i] * 3.14f) / 180;

		rot_MAT = glm::rotate(rad, rAxis);
	}
	SetModel();
}

void GameObject::SetModel()
{
	Model_MAT = rot_MAT * pos_MAT * scl_MAT;
}

void GameObject::CheckInput(GLfloat speed)
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

void GameObject::CheckCollision(GameObject* GO)
{
	GLfloat distanceX;
	GLfloat distanceY;

	distanceX = position[0] - GO->position[0];
	distanceY = position[1] - GO->position[1];

	if (glm::abs(distanceX) < 1 && glm::abs(distanceY) < 1)
	{
		cout << "collide" << endl;
	}
}
