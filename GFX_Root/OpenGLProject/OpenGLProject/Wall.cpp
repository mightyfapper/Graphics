#include "Wall.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}

void Wall::MoveWall()
{
	int wallOffset[]{ -3, 0, 3 };
	SetPosition(glm::vec3(wallOffset[rand() % 3], position[1] + 20, 0));
}
