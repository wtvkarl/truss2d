#ifndef SIMULATOR_CLASS_H
#define SIMULATOR_CLASS_H

#include <vector>
#include <glm/glm.hpp>

#include "Mesh.h"
#include "VBO.h"

enum MODE {NORMAL, PLACE, CONNECT};

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
static GLfloat mouseX, mouseY;

struct Member
{
	Vertex jointA, jointB;

	Member(Vertex a, Vertex b);

	GLfloat getLength();
};

class Simulator
{
	public:
		MODE mode; 
		bool placed;

		Mesh mesh;
		std::vector <Vertex> joints;
		std::vector <Member> members;

		Simulator();

		// -- inputs and cursor -- //
		void update(GLFWwindow* window);
		void updateKeyInputs(GLFWwindow* window);
		void updateMouseInputs(GLFWwindow* window);
		void updateCursor(GLFWwindow* window);

		void render(Shader shader);
			
};

#endif // !SIMULATOR_CLASS_H
