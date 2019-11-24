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
	scale = glm::vec3();

	InitModel();
}

GameObject::~GameObject()
{

}

void GameObject::InitModel()
{
	SetPosition(glm::vec3(0.f));
	Rotate(0.f, glm::vec3(1.f));
	SetScale(glm::vec3(1.f));
	//pos_MAT = glm::translate(glm::vec3(0.f));
	//rot_MAT = glm::rotate(0.f, glm::vec3(1.f));
	//scl_MAT = glm::scale(glm::vec3(1.f));

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
	// Save position
	scale[0] = s[0];
	scale[1] = s[1];
	scale[2] = s[2];

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
	GLfloat temp;
	for(int i=0; i<3; i++)
	{
		temp = rVal * rAxis[i];

		// If not set
		if (temp == 0)
			continue;

		// Else
		rotation[i] += temp;

		// From degree to rad
		temp = (rotation[i] * 3.14f) / 180;
		
		break;
	}
	rot_MAT = glm::rotate(temp, rAxis);
	SetModel();
}

void GameObject::SetModel()
{
	Model_MAT = rot_MAT * pos_MAT * scl_MAT;
}

void GameObject::CheckInput(GLfloat speed)
{
	//if (glfwGetKey(windowRef, GLFW_KEY_UP) == GLFW_PRESS)
	//{
	//}
	Translate(glm::vec3(0, speed, 0));

	if (glfwGetKey(windowRef, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		Translate(glm::vec3(speed, 0, 0));
	}

	if (glfwGetKey(windowRef, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		Translate(glm::vec3(-speed, 0, 0));
	}
}

void GameObject::CheckCollision(GameObject *GO)
{
	//cout<< glm::abs(position[0]) <<endl;
	GLfloat distanceX = position[0] - GO->position[0];
	GLfloat distanceY = position[1] - GO->position[1];

	GLfloat offsetX = scale[0] + GO->scale[0];
	GLfloat offsetY = scale[1] + GO->scale[1];

	// Hit
	if ((glm::abs(distanceX) < offsetX && glm::abs(distanceY) < offsetY) || glm::abs(position[0]) > 5.f)
	{
		cout << "GameOver" << endl;
	}

	// Point
	else if (position[1] > GO->position[1])
	{
		int wallOffset[]{ -3, 0, 3 };
		GO->SetPosition(glm::vec3(wallOffset[rand() % 3], GO->position[1] + 20, 0));
	}
}
