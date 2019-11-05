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

bool Engine::Window(int width, int height)
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
	
	glViewport(0, 0, FB_Width, FB_Height);

	// Init GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
		return false;
	}

	//glEnable(GL_DEPTH_TEST);
	return true;
}

void Engine::Shader()
{
	GLfloat verts[]
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
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
	glfwPollEvents();
}

void Engine::Render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
}
