#pragma once
#include "Cube.h"
#include "Wall.h"

class Player : public Cube
{
public:
	Player();
	~Player();

	bool canMove;

	float Score;

	// Input loop
	// +X is right
	// +Y is forward
	// +Z is up
	void CheckInput(GLfloat speed);

	void CheckCollision(Wall *GO);

private:
	int positionState;
	bool buttonUp;

	double currentFrame, deltaTime, lastFrame;

};
