#include "Mesh.h"

void Mesh::initPositionalData(const char* filename)
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

		std::cout << x << ", " << y << ", " << z << "\n";

	}

	OBJfile.close();
}

Mesh::Mesh(const char* filename)
{
	initPositionalData(filename);
}

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint> indices)
{

}