#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "Shader.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Rect2D.h"

#include <iostream>
#include <fstream>

class Mesh
{
	public:
		GLuint numRects = 0;

		VAO meshVAO;
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;

		Mesh();
		Mesh(const char* filename); //for obj files

		void addRect(Rect2D rect);
		void Draw(Shader& shader);
	
	private:
		void loadOBJData(const char* filename);
		void updateIndices();
};

#endif // !MESH_CLASS_H

