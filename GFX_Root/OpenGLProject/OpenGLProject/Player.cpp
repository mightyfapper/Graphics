#include "Player.h"

Player::Player()
{
	positionState = 0;
	Score = 0;
	buttonUp = true;
	canMove = true;

	currentFrame = glfwGetTime();
	lastFrame = currentFrame;
	deltaTime = 0;
}

Player::~Player()
{

}

void Player::CheckInput(GLfloat speed)
{
	// Restart
	if (glfwGetKey(windowRef, GLFW_KEY_R) == GLFW_PRESS)
	{
		Score = 0;
		printf("Score: %i - Press R to restart \r", (int)Score);
		canMove = true;
	}

	if (!canMove)
		return;

	// deltaTime
	currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	// Difficulty
	speed += Score/8;
	speed *= (float)deltaTime;

	// Forward
	Translate(glm::vec3(0, speed, 0));

	if ((glfwGetKey(windowRef, GLFW_KEY_D) == GLFW_PRESS) && buttonUp)
	{
		// Already right
		if (positionState == 1)
			return;

		positionState += 1;
		SetPosition(glm::vec3(3 * positionState, position[1], 0));

		buttonUp = false;
	}

	if ((glfwGetKey(windowRef, GLFW_KEY_A) == GLFW_PRESS) && buttonUp)
	{
		// Already left
		if (positionState == -1)
			return;

		positionState -= 1;
		SetPosition(glm::vec3(3 * positionState, position[1], 0));

		buttonUp = false;
	}

	if ((glfwGetKey(windowRef, GLFW_KEY_D) == GLFW_RELEASE) && (glfwGetKey(windowRef, GLFW_KEY_A) == GLFW_RELEASE))
		buttonUp = true;
}

void Player::CheckCollision(Wall *GO)
{
	GLfloat distanceX = position[0] - GO->position[0];
	GLfloat distanceY = position[1] - GO->position[1];

	GLfloat offsetX = scale[0] + GO->scale[0];
	GLfloat offsetY = scale[1] + GO->scale[1];

	// Hit
	if ((glm::abs(distanceX) < offsetX && glm::abs(distanceY) < offsetY))
	{
		canMove = false;

		// Divide by 2 since we have 2 walls that register a score
		printf("Score: %i - Press R to restart\r", (int)(Score / 2));
	}

	// Point
	else if (position[1] > GO->position[1])
	{
		GO->MoveWall();
		Score++;
		printf("Score: %i\r", (int)(Score/2));
	}
}
