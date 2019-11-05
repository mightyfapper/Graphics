#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

class Window
{
public:
	Window();
	~Window();

	// Window object variable
	GLFWwindow *window;

	// Frame buffer dimensions
	int FB_Width, FB_Height;
	
	// Inits GLFW and GLEW, creates a window with argument dimensions
	void Init(int width, int height);
};