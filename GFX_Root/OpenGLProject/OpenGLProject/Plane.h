#pragma once
#include "GameObject.h"

class Plane : public GameObject
{
public:
	Plane();
	~Plane();

	// Loads plane into buffer
	void Load(int s);
};
