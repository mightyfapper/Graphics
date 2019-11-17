#pragma once
#include "GameObject.h"

class Cube : public GameObject
{
public:
	Cube();
	~Cube();

	// Loads cube verts into GL_ARRAY_BUFFER
	void Init();
};
