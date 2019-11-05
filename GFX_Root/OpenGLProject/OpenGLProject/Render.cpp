#include "Render.h"

Render::Render()
{
	vertexBufferID = 0;
	PID = 0;
	vertexPosition_modelspaceID = 0;
	MVP_ID = 0;
	MVP_MAT = glm::mat4();
}

Render::~Render()
{
	Cleanup();
}

void Render::Init()
{
	// Background color
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);

	glGenBuffers(1, &vertexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	PID = LoadShaders("core.vs", "core.frag");

	vertexPosition_modelspaceID = glGetAttribLocation(PID, "vertexPosition_modelspace");
	
	MVP_ID = glGetUniformLocation(PID, "MVP");

	glUseProgram(PID);
}

void Render::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP_MAT[0][0]);

	glEnableVertexAttribArray(vertexPosition_modelspaceID);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(vertexPosition_modelspaceID);
}

void Render::Cleanup()
{
	glDeleteBuffers(1, &vertexBufferID);
	glDeleteProgram(PID);
}
