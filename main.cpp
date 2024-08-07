#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stb/stb_image.h>
#include <format>

#include "Mesh.h"
#include "Rect2D.h"
#include "Simulator.h"

const double FPS_LIMIT = 60.0;

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
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	//loadAssets();

	GLFWwindow* window = glfwCreateWindow(800, 800, "Truss Simulator 2D (by karl villapacibe)", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create window." << "\n";
		glfwTerminate();
		return -1;
	}

	glfwSetCursorPosCallback(window, cursor_position_callback);

	//keep this in this exact order for initializing windows.
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

	Simulator sim = Simulator();

	double lastTime = 0.0;
	while (!glfwWindowShouldClose(window))
	{
		double time = glfwGetTime();
		double delta = time - lastTime;

		if (delta >= 1 / FPS_LIMIT)
		{
			lastTime = time;

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.18f, 0.38f, 0.47f, 1.0f);

			sim.render(shaderProgram);
			glfwSwapBuffers(window);
		}

		sim.update(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;


}

