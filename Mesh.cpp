#include "Mesh.h"

void Mesh::initVertexData(const char* filename)
{
	std::ifstream OBJfile(filename);

	if (!OBJfile.is_open())
	{
		printf("could not open file: %s", filename);
		return;
	}

	std::string line = "";
	while (std::getline(OBJfile, line))
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
		//automatically removes the first token, leaving only the numerical dat
		//quite convienient!

		while (std::getline(stream, content, ' '))
		{
			data.push_back(content);
		}

		GLfloat x = (GLfloat)std::stof(data.at(0).c_str());
		GLfloat y = (GLfloat)std::stof(data.at(1).c_str());
		GLfloat z = (GLfloat)std::stof(data.at(2).c_str());

		Vertex vertex(x,y,z);

		vertices.push_back(vertex);

		std::cout << x << ", " << y << ", " << z << "\n";

	}

	OBJfile.close();
}

Mesh::Mesh(const char* filename)
{
	initVertexData(filename);
	initIndexData();
	initBufferObjects();
}

void Mesh::initIndexData()
{
	//6 faces, 2 triangles each, with 3 vertices each triangle

	//0,1,2, 1,2,3
	//0,2,4, 2,4,6
	//4,5,6, 5,6,7
	//1,3,5, 3,5,7
	//2,3,6, 3,6,7
	//0,1,4, 1,4,5

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(4);

	indices.push_back(2);
	indices.push_back(4);
	indices.push_back(6);

	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(6);

	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);

	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(5);

	indices.push_back(3);
	indices.push_back(5);
	indices.push_back(7);

	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(6);

	indices.push_back(3);
	indices.push_back(6);
	indices.push_back(7);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(4);

	indices.push_back(1);
	indices.push_back(4);
	indices.push_back(5);
}

void Mesh::initBufferObjects()
{
	VAO.Bind();
	VBO VBO(vertices);
	EBO EBO(indices);
	
	//position data
	VAO.LinkAttrib(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	//color data
	VAO.LinkAttrib(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));

	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void Mesh::Draw(Shader shader)
{
	shader.Activate();
	VAO.Bind();

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}