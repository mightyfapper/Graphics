#include "Render.h"

Render::Render()
{
	vertexBufferID = 0;
	PID = 0;
	vertexPosition_ID = 0;
	MVP_ID = 0;
	colorID = 0;
	MVP_MAT = glm::mat4();
	renderColor = glm::vec4();
	mainCamera = NULL;
}

Render::~Render()
{
	Cleanup();
}

void Render::Init(Camera *cam)
{
	// Background color
	glClearColor(0.0f, 0.0f, 0.25f, 1.0f);

	glGenBuffers(1, &vertexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	PID = LoadShaders("core.vs", "core.frag");

	vertexPosition_ID = glGetAttribLocation(PID, "a_vertexPosition");

	MVP_ID = glGetUniformLocation(PID, "u_MVP");

	colorID = glGetUniformLocation(PID, "u_Color");

	glUseProgram(PID);

	mainCamera = cam;
}

void Render::Draw(GameObject *GO)
{
	// Set color from GO to fragment shader
	glUniform4f(colorID, GO->color[0] , GO->color[1], GO->color[2], GO->color[3]);

	MVP_MAT = mainCamera->Projection_MAT * mainCamera->View_MAT * GO->Model_MAT;

	glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP_MAT[0][0]);

	glEnableVertexAttribArray(vertexPosition_ID);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(vertexPosition_ID);
}

void Render::Cleanup()
{
	glDeleteBuffers(1, &vertexBufferID);
	glDeleteProgram(PID);
}
