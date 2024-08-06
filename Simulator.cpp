#include "Simulator.h"
#include <stb/stb_image.h>

// -- KEY BINDS -- // 
int NORMAL_MODE_BIND = GLFW_KEY_W;
int PLACE_MODE_BIND = GLFW_KEY_Q;
int CONNECT_MODE_BIND = GLFW_KEY_E;

// -- SIMULATOR FUNCTIONS -- //

Simulator::Simulator()
{
	joints = {};
	members = {};
	mode = NORMAL;
	
	std::cout << "SIMULATOR INITIALIZED -> MODE: NORMAL" << "\n";
}

void Simulator::updateInputs(GLFWwindow* window)
{
	// -- check and change mode -- //
	if (glfwGetKey(window, NORMAL_MODE_BIND))
	{
		std::cout << "SELECTED MODE: NORMAL" << "\n";
		mode = NORMAL;
		updateCursor(window);
	}
	else if (glfwGetKey(window, PLACE_MODE_BIND))
	{
		std::cout << "SELECTED MODE: PLACE" << "\n";
		mode = PLACE;
		updateCursor(window);
	}
	else if (glfwGetKey(window, CONNECT_MODE_BIND))
	{
		std::cout << "SELECTED MODE: CONNECT" << "\n";
		mode = CONNECT;
		updateCursor(window);
	}
}

void Simulator::updateCursor(GLFWwindow* window)
{
	//better to use regular if statements rather than switch statement here

	int width, height, channels;
	unsigned char* pixels;
	GLFWimage image;

	GLFWcursor* cursor = NULL;

	if(mode == NORMAL) {
		glfwSetCursor(window, NULL);
		return;
	}
	else if(mode == PLACE) {
		pixels = stbi_load("res/imgs/place_cursor.png", &width, &height, &channels, 4);
		image.width = width;
		image.height = height;
		image.pixels = pixels;
		cursor = glfwCreateCursor(&image, 0, 0);
	}
	else if(mode ==  CONNECT) {
		pixels = stbi_load("res/imgs/connect_cursor.png", &width, &height, &channels, 4);
		image.width = width;
		image.height = height;
		image.pixels = pixels;
		cursor = glfwCreateCursor(&image, 0, 0);
	}
	
	glfwSetCursor(window, cursor);
		
}


// -- MEMBER FUNCTIONS -- //

Member::Member(Vertex a, Vertex b)
{
	jointA = a;
	jointB = b;
}

GLfloat Member::getLength()
{
	GLfloat y1 = jointA.position.y;
	GLfloat y2 = jointB.position.y;
	GLfloat x1 = jointA.position.x;
	GLfloat x2 = jointB.position.x;

	return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
