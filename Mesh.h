#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "Shader.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

#include <iostream>
#include <fstream>

class Mesh
{
	public:
		VAO meshVAO;
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;

		Mesh();
		Mesh(const char* filename); //for obj files

		void Draw(Shader& shader);
	
	private:
		void loadOBJData(const char* filename);
};

#endif // !MESH_CLASS_H

