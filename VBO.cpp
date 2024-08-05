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

// -- VERTEX STRUCT FUNCTIONS //

Vertex::Vertex(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
}

Vertex::Vertex(glm::vec3 pos)
{
	position = pos;
	color = defaultColor;
}

Vertex::Vertex(glm::vec2 pos)
{
	position = glm::vec3(pos, 0);
	color = defaultColor;
}

Vertex::Vertex(glm::vec2 pos, glm::vec3 col)
{
	position = glm::vec3(pos, 0);
	color = col;
}

Vertex::Vertex(GLfloat x, GLfloat y)
{
	position = glm::vec3(x, y, 0);
	color = defaultColor;
}

Vertex::Vertex(GLfloat x, GLfloat y, glm::vec3 col)
{
	position = glm::vec3(x, y, 0);
	color = col;
}

void Vertex::setColor(glm::vec3 newCol)
{
	color = newCol;
}

void Vertex::setPosition(glm::vec2 newPos)
{
	position = glm::vec3(newPos, 0);
}