#include "Player.h"

Player::Player()
{
	// State
	positionState = center;
	canMove = false;
}

Player::~Player()
{

}

void Player::CheckInput(GLfloat speed)
{
	Translate(glm::vec3(0, speed, 0));

	if ((glfwGetKey(windowRef, GLFW_KEY_RIGHT) == GLFW_PRESS) && canMove)
	{
		if (positionState == center)
		{
			positionState = right;
			SetPosition(glm::vec3(3, position[1], 0));
		}
		else if (positionState == left)
		{
			positionState = center;
			SetPosition(glm::vec3(0, position[1], 0));
		}
		canMove = false;
	}

	if ((glfwGetKey(windowRef, GLFW_KEY_LEFT) == GLFW_PRESS) && canMove)
	{
		if (positionState == center)
		{
			positionState = left;
			SetPosition(glm::vec3(-3, position[1], 0));
		}
		else if (positionState == right)
		{
			positionState = center;
			SetPosition(glm::vec3(0, position[1], 0));
		}
		canMove = false;
	}

	if ((glfwGetKey(windowRef, GLFW_KEY_RIGHT) == GLFW_RELEASE) && (glfwGetKey(windowRef, GLFW_KEY_LEFT) == GLFW_RELEASE))
		canMove = true;
}

void Player::CheckCollision(GameObject* GO)
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