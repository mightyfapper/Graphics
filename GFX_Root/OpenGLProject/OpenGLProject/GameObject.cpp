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
