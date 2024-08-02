#include "Mesh.h"

Mesh::Mesh(bool f)
{
	//WOOO HOOO FINALLY GOT IT TO WORK 
	Vertex one(glm::vec3(0.5, -0.5, 0), glm::vec3(0.3, 0.5, 0.5));
	Vertex two(glm::vec3(-0.5, -0.5, 0));
	Vertex three(glm::vec3(0, 0, 0));

	vertices.push_back(one);
	vertices.push_back(two);
	vertices.push_back(three);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	meshVAO.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO meshVBO(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO meshEBO(indices);

	// Links VBO attributes such as coordinates and colors to VAO
	meshVAO.LinkAttrib(meshVBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	meshVAO.LinkAttrib(meshVBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
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