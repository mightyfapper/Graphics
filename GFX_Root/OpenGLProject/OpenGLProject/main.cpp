#include "Window.h"
#include "Render.h"
#include "Cube.h"
#include "Camera.h"

int main()
{
	// TIP: Hover over functions to view arguments and comments
	
	Window *window = new Window();
	Render *render = new Render();
	Cube *cube0 = new Cube();
	Camera* cam = new Camera();

	window->Init(800, 600);

	render->Init();

	cube0->Init();
	cube0->SetModel(glm::vec3(0,0,0), glm::vec3(0, 0, 1), 0, glm::vec3(1.f, 1.f, 1.f));
	
	cam->SetProjection(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	cam->SetView(glm::vec3(4, 3, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	render->MVP_MAT = cam->Projection_MAT * cam->View_MAT * cube0->Model_MAT;

	do
	{
		render->Draw();

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
