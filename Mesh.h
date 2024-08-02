#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "Shader.h"

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

class Mesh
{
	public:
		VAO meshVAO;
		std::vector<GLfloat> vertices;
		std::vector<GLuint> indices;

		Mesh(bool f);

		void Draw(Shader& shader);
};

#endif // !MESH_CLASS_H

