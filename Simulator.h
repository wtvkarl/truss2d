#ifndef SIMULATOR_CLASS_H
#define SIMULATOR_CLASS_H

#include <vector>
#include <glm/glm.hpp>

#include "Mesh.h"
#include "VBO.h"

enum MODE {NORMAL, PLACE, CONNECT};

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
		std::vector <Vertex> joints;
		std::vector <Member> members;

		Simulator();

		// -- inputs and cursor -- //
		void updateInputs(GLFWwindow* window);
		void updateCursor(GLFWwindow* window);
			
};

#endif // !SIMULATOR_CLASS_H
