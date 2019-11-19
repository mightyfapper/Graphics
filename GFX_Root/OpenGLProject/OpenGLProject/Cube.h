#pragma once
#include "GameObject.h"

class Cube : public GameObject
{
public:
	Cube();
	~Cube();

	// Loads cube into buffer
	void Load();
};
