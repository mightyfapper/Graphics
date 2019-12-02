#include "Cube.h"

Cube::Cube()
{
	obj_Type = 3;
	buf_Stride = 5;
	ele_Number = 36;
	tex_Slot = 0;
}

Cube::~Cube()
{

}

void Cube::Load()
{
	float verts[] =
	{
		-1,-1,1,	0, 0,	// 0
		1,-1,1,		0, 1,	// 1
		1,1,1,		1, 1,	// 2
		-1,1,1,		1, 0,	// 3
		
		-1,-1,-1,	0, 0,	// 4
		1,-1,-1,	0, 1,	// 5
		1,1,-1,		1, 1,	// 6
		-1,1,-1,	1, 0	// 7
	};

	GLuint elements[] =
	{
		0,2,1,
		0,2,3,	// Front

		1,6,5,
		1,6,2,	// Right

		5,7,4,
		5,7,6,	// Behind

		4,3,0,
		4,3,7,	// Left

		0,5,1,
		0,5,4,	// Bottom

		3,6,2,
		3,6,7	// Top
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}
