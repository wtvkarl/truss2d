#include "Mesh.h"

Mesh::Mesh(bool f)
{
	vertices.push_back(0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	vertices.push_back(-0.5);
	vertices.push_back(-0.5);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0);
	vertices.push_back(0.3);
	vertices.push_back(0.5);
	vertices.push_back(0.5);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	meshVAO.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO meshVBO(vertices);
	// Generates Element Buffer Object and links it to indices
	EBO meshEBO(indices);

	// Links VBO attributes such as coordinates and colors to VAO
	meshVAO.LinkAttrib(meshVBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	meshVAO.LinkAttrib(meshVBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
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