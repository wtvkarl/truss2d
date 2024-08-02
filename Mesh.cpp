#include "Mesh.h"

Mesh::Mesh()
{
	//WOOO HOOO FINALLY GOT IT TO WORK (8/2/2024)
	Vertex one(glm::vec3(0.5, -0.5, 0), glm::vec3(0.3, 0.5, 0.9));
	Vertex two(glm::vec3(-0.5, -0.5, 0));
	Vertex three(glm::vec3(0, 0, 0));

	vertices.push_back(one);
	vertices.push_back(two);
	vertices.push_back(three);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	meshVAO.Bind();

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

void Mesh::Draw(Shader& shader)
{
	shader.Activate();
	meshVAO.Bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
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