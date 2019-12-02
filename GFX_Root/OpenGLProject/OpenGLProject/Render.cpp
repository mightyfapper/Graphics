#include "Render.h"

Render::Render()
{
	VA_ID = 0;
	VB_ID = 0;
	EB_ID = 0;
	program_ID = 0;
	vertexPosition_ID = 0;
	texCoord_ID = 0;
	texture_ID = 0;
	MVP_ID = 0;

	MVP_MAT = glm::mat4();

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
	
	// Load program
	program_ID = LoadShaders("core.vs", "core.frag");
	glUseProgram(program_ID);

	// Get vars from program
	vertexPosition_ID = glGetAttribLocation(program_ID, "a_vertexPosition");
	texCoord_ID = glGetAttribLocation(program_ID, "a_texCoord");
	texture_ID = glGetUniformLocation(program_ID, "u_texture");
	MVP_ID = glGetUniformLocation(program_ID, "u_MVP");

	// Generate vertex array, vert buffer, element buffer
	glGenVertexArrays(1, &VA_ID);
	glGenBuffers(1, &VB_ID);
	glGenBuffers(1, &EB_ID);

	// Bind them
	glBindVertexArray(VA_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VB_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EB_ID);
}

void Render::Draw(GameObject *GO)
{
	// Calculate MVP matrix
	MVP_MAT = cameraRef->Projection_MAT * cameraRef->View_MAT * GO->Model_MAT;

	// Set MVP in vertex shader
	glUniformMatrix4fv(MVP_ID, 1, GL_FALSE, &MVP_MAT[0][0]);

	// Get GO parameters
	int slot = GO->tex_Slot;
	int type = GO->obj_Type;
	int stride = GO->buf_Stride;
	int number = GO->ele_Number;

	// Select which texture slot
	glUniform1i(texture_ID, slot);

	// Set vertexPosition in vertex shader
	glEnableVertexAttribArray(vertexPosition_ID);
	glVertexAttribPointer(vertexPosition_ID, type, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)0);

	// Set texCoord in vertex shader
	glEnableVertexAttribArray(texCoord_ID);
	glVertexAttribPointer(texCoord_ID, 2, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(type * sizeof(float)));

	// Draw call
	glDrawElements(GL_TRIANGLES, number, GL_UNSIGNED_INT, 0);
}

void Render::Cleanup()
{
	glDeleteVertexArrays(1, &VA_ID);
	glDeleteBuffers(1, &VB_ID);
	glDeleteBuffers(1, &EB_ID);
	glDeleteProgram(program_ID);
}
