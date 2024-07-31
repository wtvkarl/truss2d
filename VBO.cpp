#include "VBO.h"

// Constructor that generates a Vertex Buffer Object and links it to vertices
VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

// Binds the VBO
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}

// -- VERTEX STRUCT FUNCTIONS -- //

Vertex::Vertex()
{
	position = glm::vec3(0, 0, 0);
	color = defaultColor;
}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z)
{
	position = glm::vec3(x, y, z);
	color = defaultColor;
}

void Vertex::printPositionData()
{
	printf("Vertex Position: [%.2f, %.2f, %.2f]\n", position.x, position.y, position.z);
}

void Vertex::printColorData()
{
	printf("Vertex Color: [%.1f, %.1f, %.1f, 1.0f]\n", color.r, color.g, color.b);
}