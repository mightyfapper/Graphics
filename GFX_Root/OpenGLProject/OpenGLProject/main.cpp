#include "Window.h"
#include "Render.h"
#include "Cube.h"
#include "Camera.h"

int main()
{
	// Hover over functions to view arguments and comments
	
	Window *window = new Window();
	Render *render = new Render();
	Camera* camera = new Camera();
	
	// Calls GameObject constructor
	Cube *cube0 = new Cube();
	
	window->Init(800, 600);

	camera->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	camera->SetView(glm::vec3(0, -3, 3), glm::vec3(), glm::vec3(0, 0, 1));

	render->Init(camera);

	cube0->Init();

	cube0->SetColor(glm::vec4(1, 0, 0, 1));

	do
	{
		cube0->ActivateMovement(window, 0.01f);

		glClear(GL_COLOR_BUFFER_BIT);

		render->Draw(cube0);

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
