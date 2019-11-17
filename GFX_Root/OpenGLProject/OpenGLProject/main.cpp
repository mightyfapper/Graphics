#include "Window.h"
#include "Render.h"
#include "Cube.h"
#include "Camera.h"

int main()
{
	// Hover over functions to view arguments and comments
	
	Window *window = new Window();
	Render *render = new Render();
	Camera *camera = new Camera();
	Cube *player = new Cube();
	Cube *wall_1 = new Cube();
	
	window->Init(800, 600);

	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	camera->SetView(glm::vec3(0, -3, 3), glm::vec3(), glm::vec3(0, 0, 1));

	render->Init();
	render->cameraRef = camera;

	player->Init();

	player->windowRef = window->window;

	player->SetColor(glm::vec4(0, 0, 1, 1));

	wall_1->SetColor(glm::vec4(1, 0, 0, 1));
	wall_1->SetPosition(glm::vec3(2, 2, 0));
	
	glEnable(GL_DEPTH_TEST);
	
	while (glfwGetKey(window->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window->window) == 0)
	{
		// Gameloop
		player->ActivateMovement(0.01f);

		GLfloat distanceX;
		GLfloat distanceY;

		distanceX = player->position[0] - wall_1->position[0];
		distanceY = player->position[1] - wall_1->position[1];

		if(glm::abs(distanceX) < 1 && glm::abs(distanceY) < 1)
		{
			cout << "collide" << endl;
		}

		// Render
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		render->Draw(player);
		render->Draw(wall_1);

		glfwSwapBuffers(window->window);

		glfwPollEvents();
	}

	glfwTerminate();
	
	// Calls Render deconstrutor
	delete render;

	return 0;
}
