# Graphics
Steps:

Download https://desktop.github.com/

Login

Clone "Graphics" repo in a folder on your computer - this will download the project

Then open GFX_Root/OpenGLProject/OpenGLProject.sln with visual studio

Before building make sure that next to Local Windows Debugger that visual studio is in Debug x86 mode

Profit

## Manual Setup

1. Download GLFW, GLEW & Visual Studio
   - a. GLFW: https://www.glfw.org/ (Download --> 64/32 bit windows binaries)
   - b. GLEW: http://glew.sourceforge.net/index.html (Binaries!)
   - c. VS19: https://visualstudio.microsoft.com/free-developer-offers/ (Visual Studio Community)
2. Extract Downloaded Files
3. Create a new folder (This is you project folder, name it OpenGLRoot for example.)
4. Create two new subfolders inside your project (OpenGLRoot) folder and name them (External Resources & OpenGLVS)
5. Copy extracted zip files to your newly created folder (External Resources) and rename them GLFW & GLEW correspondingly.
6. Open VS and create a new empty project.
7. From the solution Explorer Right-click your project and click add --> New item and add a new .cpp file (main.cpp)
8. Right-click your project in the solution Explorer and head over properties.
9. If your Machine is x86, follow these steps:   otherwise head over to step 10
   - a. Platform --> Active (x32)
   - b. c/c++    --> General: Additional include Directories: 
     - a. $(SolutionDir)/../External Resources/GLFW/include
     - b. $(SolutionDir)/../External Resources/GLFW/include
   - c. Linker   --> General: Additional library Directories: 
     - a. $(SolutionDir)/../External Resources/GLEW/lib/Release/Win32
     - b. $(SolutionDir)/../External Resources/GLFW/lib-vc2019
   - d. Linker   --> input: Additional Dependencies:         
     - a. opengl32.lib
     - b. glew32s.lib
     - c. glfw3.lib
10. If your Machine is x64, follow these steps:                                                           
    -  a. Platform --> Active (x64)
    -  b. c/c++    --> General: Additional include Directories:  
       - a. $(SolutionDir)/../External Resources/GLFW/include
       - b. $(SolutionDir)/../External Resources/GLFW/include
    -  c. Linker   --> General: Additional library Directories: 
       - a. $(SolutionDir)/../External Resources/GLEW/lib/Release/x64
       - b. $(SolutionDir)/../External Resources/GLFW/lib-vc2019
    -  d. Linker   --> input: Additional Dependencies:         
       - a. opengl32.lib
       - b. glew32s.lib
       - c. glfw3.lib
11. Create tow new subfolders in OpenGLVS folder aand name then Debug and Release,
12. Go to OpenGLRoot/GLEW/bin/Release/Win32 (If your machine is x86) OR x64 (If your machine is x64) and copy the glew32.dll file.
13. Paste the .dll file in the Debug and Release Folders that you created.
14. Paste the .dll file in the PATH: "OpenGLRoot/OpenGLVS/OpenGLVS"
15. Click Apply and close the properties tab.
16. In main.cpp copy & paste the following code:

```ruby

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);


	// Build and compile our shader program
	// Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// Check for compile time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Link shaders
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f, // Left
		0.5f, -0.5f, 0.0f, // Right
		0.0f,  0.5f, 0.0f  // Top
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw our first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();

	return EXIT_SUCCESS;
}
'''
