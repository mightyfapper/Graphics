#include "Window.h"
#include "Render.h"
#include "Cube.h"
#include "Camera.h"

int main()
{
	// Hover over functions to view arguments and comments
	
	Window *window = new Window();
	Render *render = new Render();
	Cube *cube0 = new Cube();
	Cube *cube1 = new Cube();
	Cube *cube2 = new Cube();
	Camera* camera = new Camera();
	
	// Create window
	window->Init(800, 600);

	// Setup camera
	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	camera->SetView(glm::vec3(4, 3, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	render->Init(camera);

	// Setup GameObjects
	cube0->Init();
	cube0->SetModel(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), 0, glm::vec3(1.f, 1.f, 1.f));
	
	cube1->SetModel(glm::vec3(3, 0, 0), glm::vec3(0, 0, 1), 0, glm::vec3(1.f, 1.f, 1.f));

	cube2->SetModel(glm::vec3(-3, 0, 0), glm::vec3(0, 0, 1), 0, glm::vec3(1.f, 1.f, 1.f));

	cube0->color = glm::vec4(1, 0, 0, 1);
	cube1->color = glm::vec4(0, 1, 0, 1);
	cube2->color = glm::vec4(0, 0, 1, 1);

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);

		render->Draw(cube0);

		render->Draw(cube1);

		render->Draw(cube2);

		glfwSwapBuffers(window->window);

		glfwPollEvents();
	}
	while (glfwGetKey(window->window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window->window) == 0);

	glfwTerminate();
	
	// Calls Render deconstrutor
	delete render;

	return 0;
}
