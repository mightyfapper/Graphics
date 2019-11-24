#include "Plane.h"

Plane::Plane()
{
	obj_Type = 2;
	buf_Stride = 4;
	ele_Number = 6;
	tex_Slot = 0;
}

Plane::~Plane()
{

}

void Plane::Load()
{
	float verts[] =
	{
		-1, -1,		0, 0,   // bottom left
		1, -1,		0, 500,   // bottom right
		1,  1,		500, 500,   // top right
		-1, 1,		500, 0    // top left
	};

	GLuint elements[] =
	{
		0, 1, 2, // first triangle
		0, 2, 3  // second triangle
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
