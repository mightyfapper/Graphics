#include "Window.h"

Window::Window()
{
	window = NULL;
	FB_Width = 0;
	FB_Height = 0;
}

Window::~Window()
{

}

void Window::Init(int width, int height)
{
	if (!glfwInit())
	{
		cout << "Error initialising GLFW" << endl;
	}

	// Set window dimentions
	window = glfwCreateWindow(width, height, "Game", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &FB_Width, &FB_Height);

	glViewport(0, 0, FB_Width, FB_Height);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
	}
}
