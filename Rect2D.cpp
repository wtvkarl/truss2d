#include "Rect2D.h"


//position of rectangle is set to the top left corner
Rect2D::Rect2D(glm::vec2 pos, glm::vec2 dim)
{
	//these are screenspace coordinates that need to be normalized
	normalize(pos, dim);
	initVertices();
}

void Rect2D::normalize(glm::vec2 pos, glm::vec2 dim)
{

	GLfloat norm_x = (pos.x - 400) / 400;
	GLfloat norm_y = (pos.y - 400) / -400;

	position = glm::vec2(norm_x, norm_y);

	width = dim.x / 400;
	height = dim.y / 400;

	dimensions = glm::vec2(width, height);
		
	printCoordinates();
	printDimensions();
	
}

void Rect2D::initVertices()
{
	Vertex topLeft(position.x, position.y);
	Vertex topRight(position.x + width, position.y);
	Vertex bottomLeft(position.x, position.y - height);
	Vertex bottomRight(position.x + width, position.y - height);

	points.push_back(topLeft);
	points.push_back(topRight);
	points.push_back(bottomLeft);
	points.push_back(bottomRight);
}

void Rect2D::setColor(GLfloat r, GLfloat g, GLfloat b)
{
	for (Vertex v : points)
		v.color = glm::vec3(r, g, b);
}

void Rect2D::setPosition(glm::vec2 newPos)
{
	for (Vertex v : points)
	{
		v.position = glm::vec3(newPos, 0);
	}
}

void Rect2D::printCoordinates()
{
	printf("Normalized Coordinates: [%.2f, %.2f]\n", position.x, position.y);
}

void Rect2D::printDimensions()
{
	printf("Normalized Dimensions: [%.2f, %.2f]\n", dimensions.x, dimensions.y);
}