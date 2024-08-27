#include "Simulator.h"
#include <stb/stb_image.h>

// -- KEY BINDS -- // 
int NORMAL_MODE_BIND = GLFW_KEY_W;
int PLACE_MODE_BIND = GLFW_KEY_Q;
int CONNECT_MODE_BIND = GLFW_KEY_E;

glm::vec2 getScreenCoords(GLfloat x, GLfloat y)
{
	return glm::vec2(
		(x - 400) / 400,
		(y - 400) / -400
	);
}

// -- CURSOR POSITION CALLBACK -- //
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouseX = xpos;
	mouseY = ypos;
}

// -- SIMULATOR FUNCTIONS -- //

Simulator::Simulator()
{
	joints = {};
	members = {};
	mode = NORMAL;
	
	mesh = Mesh();

	std::cout << "SIMULATOR INITIALIZED -> MODE: NORMAL" << "\n";
}

// -- MAIN FUNCTIONS -- //

void Simulator::render(Shader shader)
{
	mesh.Draw(shader);
}

void Simulator::update(GLFWwindow* window)
{
	updateKeyInputs(window);
	updateMouseInputs(window);

	if (mode == CONNECT)
	{
		if (!mesh.rects.empty())
		{
			glm::vec2 closestRect = highlightNearestBox(mesh, mouseX, mouseY);
			printf("Closest Rect Coords: [%.2f, %.2f]\n", closestRect.x, closestRect.y);
			Rect2D testRect(closestRect, glm::vec2(20, 20));
			testRect.setColorRGB(glm::vec3(124, 124, 45));
			mesh.addRect(testRect);
		}
	}
}

// -- INPUT FUNCTIONS -- //

void Simulator::updateKeyInputs(GLFWwindow* window)
{
	// -- check and change mode -- //
	if (glfwGetKey(window, NORMAL_MODE_BIND))
	{
		if (mode == NORMAL)
			return;

		std::cout << "SELECTED MODE: NORMAL" << "\n";
		mode = NORMAL;
		updateCursor(window);
	}
	else if (glfwGetKey(window, PLACE_MODE_BIND))
	{
		if (mode == PLACE)
			return;

		std::cout << "SELECTED MODE: PLACE" << "\n";
		mode = PLACE;
		updateCursor(window);
	}
	else if (glfwGetKey(window, CONNECT_MODE_BIND))
	{
		if (mode == CONNECT)
			return;

		std::cout << "SELECTED MODE: CONNECT" << "\n";
		mode = CONNECT;
		updateCursor(window);
	}
}

void Simulator::updateMouseInputs(GLFWwindow* window)
{
	//these two "if blocks" make sure that the input is only counted once
	//even if the mouse button is held down
	int isPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	if (isPressed && !placed)
	{
		if (mode == PLACE)
		{
			//printf("Mouse Position: [%.2f, %.2f]\n", mouseX, mouseY);

			mesh.addRect(Rect2D(glm::vec2(mouseX, mouseY), glm::vec2(20, 20)));
			placed = true;
		}
	}
	if (!isPressed && placed)
	{
		placed = false;
	}
}

void Simulator::updateCursor(GLFWwindow* window)
{  
	//better to use regular if statements rather than switch statement here

	int width, height, channels;
	unsigned char* pixels;
	GLFWimage image;

	if (mode == NORMAL) {
		glfwSetCursor(window, NULL);
		return;
	}
	else if (mode == PLACE) {
		pixels = stbi_load("res/imgs/place_cursor.png", &width, &height, &channels, 4);
		image.width = width;
		image.height = height;
		image.pixels = pixels;
	}
	else if (mode == CONNECT) {
		pixels = stbi_load("res/imgs/connect_cursor.png", &width, &height, &channels, 4);
		image.width = width;
		image.height = height;
		image.pixels = pixels;
	}

	GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
	glfwSetCursor(window, cursor);

}

glm::vec2 Simulator::highlightNearestBox(Mesh mesh, GLfloat mx, GLfloat my)
{
	GLfloat minDist = 1000000000;
	glm::vec2 coords(0, 0);

	//normalize the mouse cursor position vector
	glm::vec2 mousePos = getScreenCoords(mouseX, mouseY);
	
	for (int i = 0; i < mesh.rects.size(); i++)
	{
		GLfloat dx = std::abs(mesh.rects.at(i).normalizedPosition.x - mousePos.x);
		GLfloat dy = std::abs(mesh.rects.at(i).normalizedPosition.y - mousePos.y);

		GLfloat dist = std::sqrt(dx * dx + dy * dy);
		if (dist < minDist)
		{
			//we return the screen space coords since the rect is initialized next
			minDist = dist;
			coords.x = mesh.rects.at(i).screenSpacePosition.x;
			coords.y = mesh.rects.at(i).screenSpacePosition.y;
		}
	}
	//this returns the distance to the closest rect, just need to ACCESS the rect now. 
	std::cout << minDist << "\n";

	return coords;
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
