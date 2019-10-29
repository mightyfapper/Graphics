#pragma once
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

class Engine {
public:
	// Constructor
	 Engine();
	 ~Engine();

	// Funcs
	bool Init(int width, int height);
	
	void Start();
	void Update();
	void Render();

private:
	GLFWwindow* window;
	int FB_Width, FB_Height;
};