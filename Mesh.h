#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Shader.h"
#include <vector>

class Mesh
{
	public:
		std::vector <Vertex> vertices;
		std::vector <GLuint> indices;

		//every single mesh has its own VAO
		VAO VAO;

		Mesh(std::vector <Vertex>& vertices, std::vector <GLuint> indices);
		Mesh(const char* filename);

		void Draw(Shader& shader);

	private:
		void initPositionalData(const char* filename);
};

#endif // !MESH_CLASS_H

