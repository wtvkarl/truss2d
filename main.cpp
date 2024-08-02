#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "inputs.h"
#include "Mesh.h"

int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << '\n';
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Truss Simulator 2D (by karl villapacibe)", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create window." << "\n";
		glfwTerminate();
		return -1;
	}

	//all callbacks found in file -> "inputs.h"
	glfwSetKeyCallback(window, key_callback);

	//keep this in this exact order for initializing windows.
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

	Mesh test(false);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.4f, 0.2f, 0.5f, 1.0f);

		test.Draw(shaderProgram);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;


}

