#include "Plane.h"

Plane::Plane()
{
	type = 2;
}

Plane::~Plane()
{

}

void Plane::Init()
{
	static const GLfloat verts[] = {
		-0.5f, -0.5,
		0.5f, -0.5,
		0.5f, 0.5,
		
		0.5f, 0.5,
		-0.5f, 0.5,
		-0.5f, -0.5
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
}
