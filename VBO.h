#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;

	glm::vec3 defaultColor = glm::vec3(0.5f, 0.8f, 0.8f);

	Vertex();
	Vertex(GLfloat x, GLfloat y, GLfloat z);

	void printPositionData();
	void printColorData();
};

class VBO
{
	public:
		GLuint ID;
		VBO(std::vector<Vertex>& vertices);

		void Bind();
		void Unbind();
		void Delete();
};

#endif VBO_CLASS_H
