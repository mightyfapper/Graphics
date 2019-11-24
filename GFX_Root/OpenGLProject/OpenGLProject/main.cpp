#include "Window.h"
#include "Render.h"
#include "Texture.h"
#include "Camera.h"
#include "Cube.h"
#include "Plane.h"

int main()
{
	// ~~~~~~~~~~~
	// Engine Setup
	// ~~~~~~~~~~~
	Window	*window = new Window();
	Render	*render = new Render();
	Camera	*camera = new Camera();

	Plane	*ground = new Plane();
	Cube	*player = new Cube();
	Cube	*wall_1 = new Cube();
	Cube	*wall_2 = new Cube();
	Plane	*edge_L = new Plane();
	Plane	*edge_R = new Plane();

	Texture *groundTex = new Texture();
	Texture *playerTex = new Texture();
	Texture *wallTex = new Texture();

	window->Init(800, 600);

	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	render->Init();
	render->cameraRef = camera;

	groundTex->Bind("textures/grass.png", 0);
	playerTex->Bind("textures/player.png", 1);
	wallTex->Bind("textures/wall.png", 2);

	// ~~~~~~~~~~~
	// GameObject Setup
	// ~~~~~~~~~~~
	ground->SetPosition(glm::vec3(0, 900, -1));
	ground->SetScale(glm::vec3(1000, 1000, 1));
	ground->tex_Slot = 0;

	player->windowRef = window->window;
	player->tex_Slot = 1;

	wall_1->SetPosition(glm::vec3(3, 3, 0));
	wall_1->SetScale(glm::vec3(1, 1, 1));
	wall_1->tex_Slot = 2;

	wall_2->SetPosition(glm::vec3(-3, 3, 0));
	wall_2->SetScale(glm::vec3(1, 1, 1));
	wall_2->tex_Slot = 2;

	// Rotation changes local object coordinates
	// +Z is right
	// +X is down
	edge_L->SetPosition(glm::vec3(-999, 900, -6));
	edge_L->Rotate(90, glm::vec3(0, 1, 0));
	edge_L->SetScale(glm::vec3(1000, 1000, 1));
	edge_L->tex_Slot = 2;

	edge_R->SetPosition(glm::vec3(-999, 900, 6));
	edge_R->Rotate(90, glm::vec3(0, 1, 0));
	edge_R->SetScale(glm::vec3(1000, 1000, 1));
	edge_R->tex_Slot = 2;
	
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	// ~~~~~~~~~~~
	// Engine loop
	// ~~~~~~~~~~~
	while (glfwGetKey(window->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window->window) == 0)
	{
		// ~~~~~~~~~~~
		// Game loop
		// ~~~~~~~~~~~
		camera->SetView(glm::vec3(
			player->position[0], 
			player->position[1]-6, 2),
			player->position,
			glm::vec3(0, 0, 1)
		);
		
		player->CheckInput(0.1f);

		player->CheckCollision(wall_1);
		player->CheckCollision(wall_2);

		// ~~~~~~~~~~~
		// Render loop
		// ~~~~~~~~~~~
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw planes
		ground->Load();
		render->Draw(ground);
		render->Draw(edge_L);
		render->Draw(edge_R);

		// Draw cubes
		player->Load();
		render->Draw(player);
		render->Draw(wall_1);
		render->Draw(wall_2);

		glfwSwapBuffers(window->window);
		glfwPollEvents();
	}

	// Exit
	glfwTerminate();

	// Calls Render deconstrutor
	delete render;

	return 0;
}
