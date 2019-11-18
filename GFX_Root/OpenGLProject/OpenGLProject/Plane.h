#pragma once
#include "GameObject.h"

class Plane : public GameObject
{
public:
	Plane();
	~Plane();

	// Loads plane verts into GL_ARRAY_BUFFER
	void Init();
};
