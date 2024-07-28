#ifndef INPUTS_H
#define INPUTS_H

#include <GLFW/glfw3.h>
#include <iostream>

static void key_callback(GLFWwindow* window, int key, int code, int action, int mods)
{
	std::cout << key << "\n";
}
#endif // !INPUTS_H
