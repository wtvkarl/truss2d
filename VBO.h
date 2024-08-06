#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <vector>

// defined in VBO.h and implemented in VBO.cpp
struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	
    glm::vec3 defaultColor = glm::vec3(0.35f, 0.4f, 0.5f);

	//3D constructors
	Vertex(glm::vec3 pos, glm::vec3 col);
	Vertex(glm::vec3 pos);
	
	//2D constructors
	Vertex();
	Vertex(glm::vec2 pos);
	Vertex(GLfloat x, GLfloat y);
	Vertex(GLfloat x, GLfloat y, glm::vec3 col);
	Vertex(glm::vec2 pos, glm::vec3 col);

	void setColor(glm::vec3 newCol);
	void setPosition(glm::vec2 newPos);
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
