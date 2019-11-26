#pragma once
#include "Cube.h"

class Player : public Cube
{
public:
	Player();
	~Player();

	// Input loop
	// +X is right
	// +Y is forward
	// +Z is up
	void CheckInput(GLfloat speed);

	void CheckCollision(GameObject* GO);

private:
	enum E_positionState { center, right, left };
	int positionState;
	bool canMove;
};
