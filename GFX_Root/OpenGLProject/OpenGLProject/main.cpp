#include "Window.h"
#include "Render.h"
#include "Texture.h"
#include "Camera.h"
#include "Cube.h"
#include "Plane.h"

int main()
{
	Window	*window = new Window();
	Render	*render = new Render();
	Camera	*camera = new Camera();
	Plane	*ground = new Plane();
	Cube	*player = new Cube();
	Texture *grass = new Texture();
	Texture *wall = new Texture();

	window->Init(800, 600);

	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	camera->SetView(glm::vec3(0, -3, 3), glm::vec3(), glm::vec3(0, 0, 1));

	render->Init();

	// Renderer needs camera's View and Projection MAT to draw
	render->cameraRef = camera;

	// Player needs window reference to get input events
	player->windowRef = window->window;

	// Load and bind textures
	grass->Bind("textures/grass.png", 0);
	wall->Bind("textures/wall.png", 1);

	// Set ground attribs
	ground->SetPosition(glm::vec3(0, 0, -1));
	ground->SetScale(glm::vec3(5, 25, 1));

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	// Engine loop
	while (glfwGetKey(window->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window->window) == 0)
	{
		// Game loop
		player->CheckInput(0.01f);

		// Render loop
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		player->Load();
		render->Draw(player);

		ground->Load();
		render->Draw(ground);

		glfwSwapBuffers(window->window);
		glfwPollEvents();
	}

	// Exit
	glfwTerminate();

	// Calls Render deconstrutor
	delete render;

	return 0;
}
