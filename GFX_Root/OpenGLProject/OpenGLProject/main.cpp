#include "Window.h"
#include "Render.h"
#include "Texture.h"
#include "Camera.h"
#include "Cube.h"
#include "Plane.h"
#include "Player.h"
#include "Wall.h"
#include <cmath>
#include <math.h> 

int main()
{
	Window* window = new Window();
	Render* render = new Render();
	Camera* camera = new Camera();

	Plane* ground = new Plane();
	Plane* edge_L = new Plane();
	Plane* edge_R = new Plane();
	Plane* sky = new Plane();

	Player* player = new Player();
	Wall* wall_1 = new Wall();
	Wall* wall_2 = new Wall();

	Texture* groundTex = new Texture();
	Texture* playerTex = new Texture();
	Texture* wallTex = new Texture();
	Texture* skyTex = new Texture();

	// ~~~~~~~~~~~
	// Engine Setup
	// ~~~~~~~~~~~
	window->Init(800, 600);

	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

	render->Init();
	render->cameraRef = camera;

	groundTex->Bind("textures/grass.png", 0);
	playerTex->Bind("textures/player.png", 1);
	wallTex->Bind("textures/wall.png", 2);
	skyTex->Bind("textures/sky.png", 3);

	// ~~~~~~~~~~~
	// GameObject Setup
	// ~~~~~~~~~~~

	// Static
	ground->SetPosition(glm::vec3(0, 90, -1));
	ground->SetScale(glm::vec3(100, 100, 1));
	ground->tex_Slot = 0;

	// +X is down
	// +Z is right
	edge_L->SetPosition(glm::vec3(-90, 90, -6));
	edge_L->Rotate(90, glm::vec3(0, 1, 0));
	edge_L->SetScale(glm::vec3(100, 100, 1));
	edge_L->tex_Slot = 2;

	edge_R->SetPosition(glm::vec3(-90, 90, 6));
	edge_R->Rotate(90, glm::vec3(0, 1, 0));
	edge_R->SetScale(glm::vec3(100, 100, 1));
	edge_R->tex_Slot = 2;

	// +X is right
	// +Y is up
	sky->Rotate(90, glm::vec3(0, 1, 0));
	sky->Rotate(90, glm::vec3(1, 0, 0));
	sky->SetScale(glm::vec3(10, 10, 1));
	sky->tex_Slot = 3;

	// Dynamic
	player->windowRef = window->window;
	player->tex_Slot = 1;

	wall_1->SetPosition(glm::vec3(3, 15, 0));
	wall_1->SetScale(glm::vec3(1, 1, 1));
	wall_1->tex_Slot = 2;

	wall_2->SetPosition(glm::vec3(-3, 15, 0));
	wall_2->SetScale(glm::vec3(1, 1, 1));
	wall_2->tex_Slot = 2;

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

		// Map loop || Restart
		if (glm::abs(sky->position[2]) >= 190 || glfwGetKey(window->window, GLFW_KEY_R) == GLFW_PRESS)
		{
			// Reset dynamic object positions
			player->SetPosition(glm::vec3(player->position[0], 0, player->position[2]));
			wall_1->SetPosition(glm::vec3(wall_1->position[0], 20, 0));
			wall_2->SetPosition(glm::vec3(wall_2->position[0], 20, 0));
		}

		player->CheckInput(20);

		// Follow
		sky->SetPosition(glm::vec3(0, 6, -1 * (player->position[1] + 50)));
		camera->SetView(glm::vec3(
			player->position[0],
			player->position[1] - 6, 2),
			player->position,
			glm::vec3(0, 0, 1)
		);

		player->CheckCollision(wall_1);
		player->CheckCollision(wall_2);

		// ~~~~~~~~~~~
		// Render loop
		// ~~~~~~~~~~~
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw planes
		ground->Load(50);
		render->Draw(ground);
		render->Draw(edge_L);
		render->Draw(edge_R);
		sky->Load(1);
		render->Draw(sky);

		// Draw cubes
		player->Load();
		render->Draw(player);
		render->Draw(wall_1);
		render->Draw(wall_2);

		glfwSwapBuffers(window->window);
		glfwPollEvents();
	}

	glfwTerminate();
	delete render;
	return 0;
}
