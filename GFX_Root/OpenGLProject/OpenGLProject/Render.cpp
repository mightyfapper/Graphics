#include "Render.h"

Render::Render()
{
	vertexBuffer_ID = 0;
	program_ID = 0;
	vertexPosition_ID = 0;
	MVP_ID = 0;
	color_ID = 0;

	MVP_MAT = glm::mat4();
	renderColor = glm::vec4();

	cameraRef = NULL;
}

Render::~Render()
{
	Cleanup();
}

void Render::Init()
{
	// Background color
	glClearColor(0.0f, 0.0f, 0.25f, 1.0f);

	glGenBuffers(1, &vertexBuffer_ID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer_ID);

	program_ID = LoadShaders("core.vs", "core.frag");

	vertexPosition_ID = glGetAttribLocation(program_ID, "a_vertexPosition");

	MVP_ID = glGetUniformLocation(program_ID, "u_MVP");

	color_ID = glGetUniformLocation(program_ID, "u_Color");

	glUseProgram(program_ID);
}

void Render::Draw(GameObject *GO)
{
	// Set color from GO to fragment shader
	glUniform4f(color_ID, GO->color[0] , GO->color[1], GO->color[2], GO->color[3]);

	MVP_MAT = cameraRef->Projection_MAT * cameraRef->View_MAT * GO->Model_MAT;

	glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP_MAT[0][0]);

	glEnableVertexAttribArray(vertexPosition_ID);

	glVertexAttribPointer(0, GO->type, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(vertexPosition_ID);
}

void Render::Cleanup()
{
	glDeleteBuffers(1, &vertexBuffer_ID);
	glDeleteProgram(program_ID);
}
