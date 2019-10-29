#include "Engine.h"

Engine::Engine()
{
	window = NULL;
	FB_Width = NULL;
	FB_Height = NULL;
}

Engine::~Engine()
{

}

bool Engine::Init(int width, int height)
{
	// Init GLFW
	if(!glfwInit())
	{
		cout << "Error initialising GLFW" << endl;
		return false;
	}

	window = glfwCreateWindow(width, height, "Game", NULL, NULL);
	if(window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();

		return false;
	}

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &FB_Width, &FB_Height);
	
	// Define the viewport dimensions
	glViewport(0, 0, FB_Width, FB_Height);

	// Init GLEW
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		cout << "Failed to initialize GLEW" << endl;
		return EXIT_FAILURE;
	}

	return true;
}

void Engine::Start()
{
	while (!glfwWindowShouldClose(window))
	{
		Update();
		Render();
	}
	glfwTerminate();
}

void Engine::Update()
{
	// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
	glfwPollEvents();
}

void Engine::Render()
{
	// Clear the colorbuffer
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap the screen buffers
	glfwSwapBuffers(window);
}
