#include "Mesh.h"

Mesh::Mesh()
{
	meshVAO.Bind();
	updateBufferObjects();
}

Mesh::Mesh(const char* filename)
{
	loadOBJData(filename);
}

void Mesh::loadOBJData(const char* filename)
{
	std::fstream objFile(filename);

	if (!objFile.is_open())
	{
		printf("could not open mesh file: %s", filename);
		return;
	}

	std::string line = "";
	while (std::getline(objFile, line))
	{
		std::string content;
		std::stringstream stream(line);
		std::vector <std::string> data;

		std::getline(stream, content, ' ');

		/*
			checks if the first token of the line
			matches the target type designated

			- if so, create a vector using the
			split string tokens to extract numerical data

			- if not, skip to the next line
		*/
		if (content != "v")
			continue;

		//calling get line after checking the first token 
		//automatically removes the first token, leaving only the numerical data
		//quite convienient!

		while (std::getline(stream, content, ' '))
		{
			data.push_back(content);
		}

		//TO DO: convert strings to floats,
		//		 take numerical data and make new Vertex Objects
		//		 make automatic index function
		// successfully draw a cube, just the front face
	}
	objFile.close();
}

void Mesh::addRect(Rect2D rect)
{
	for (int i = 0; i < 4; i++)
	{
		vertices.push_back(rect.points.at(i));
	}
	updateIndices();
	numRects++;

	//reinitializes the VBO and EBO, doesn't touch the VAO ever
	updateBufferObjects();
}

void Mesh::updateIndices()
{
	//each rect has 2 triangles, so 6 indices per rect2D. 
	indices.push_back(numRects * 4);
	indices.push_back(numRects * 4 + 1);
	indices.push_back(numRects * 4 + 2);
	indices.push_back(numRects * 4 + 1);
	indices.push_back(numRects * 4 + 2);
	indices.push_back(numRects * 4 + 3);

	//for (GLuint i : indices)
	//	std::cout << i << " ";
	//std::cout << "\n";
}

void Mesh::updateBufferObjects()
{
	VBO meshVBO(vertices);
	EBO meshEBO(indices);

	//connect vbo, # layout in shader?, how many components in each attribute?
	//how far in bytes till next data, how far in bytes to jump from start to get to attribute?

	//position
	meshVAO.LinkAttrib(meshVBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//color
	meshVAO.LinkAttrib(meshVBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

	meshVAO.Unbind();
	meshVBO.Unbind();
	meshEBO.Unbind();
}

void Mesh::Draw(Shader& shader)
{
	shader.Activate();
	meshVAO.Bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}