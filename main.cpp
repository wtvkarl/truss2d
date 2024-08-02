#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "inputs.h"
#include "Shader.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

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

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	vertices.push_back(0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	vertices.push_back(-0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices);

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.4f, 0.2f, 0.5f, 1.0f);

		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;


}

