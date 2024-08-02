#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

// VERTEX IMPLEMENTATION FOUND IN "Mesh.cpp"
struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	
	const glm::vec3 defaultColor = glm::vec3(0.3f, 0.4, 0.5);

	Vertex(glm::vec3 pos, glm::vec3 col);
	Vertex(glm::vec3 pos);
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
