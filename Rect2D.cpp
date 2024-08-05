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
	normalizePosition(pos);
	normalizeDimensions(dim);

	printCoordinates();
	printDimensions();	
}

void Rect2D::normalizePosition(glm::vec2 pos)
{
	GLfloat norm_x = (pos.x - 400) / 400;
	GLfloat norm_y = (pos.y - 400) / -400;

	position = glm::vec2(norm_x, norm_y);
}

void Rect2D::normalizeDimensions(glm::vec2 dim)
{
	width = dim.x / 400;
	height = dim.y / 400;

	dimensions = glm::vec2(width, height);
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

void Rect2D::setColor(glm::vec3 newCol)
{
	//for some reason enhanced for-loops don't work aas expected
	for (int i = 0; i < 4; i++)
		points.at(i).setColor(newCol);
}

void Rect2D::setPosition(glm::vec2 newPos)
{
	normalizePosition(newPos);
	
	//after normalizing position vec2, we can use it regularly to 
	//to reset the positions of each vertex.

	//top left
	points.at(0).setPosition(position);
	//top right
	points.at(1).setPosition(glm::vec2(position.x + width, position.y));
	//bottom left
	points.at(2).setPosition(glm::vec2(position.x, position.y - height));
	//bottom right
	points.at(3).setPosition(glm::vec2(position.x + width, position.y - height));
}

void Rect2D::printCoordinates()
{
	printf("Normalized Coordinates: [%.2f, %.2f]\n", position.x, position.y);
}

void Rect2D::printDimensions()
{
	printf("Normalized Dimensions: [%.2f, %.2f]\n", dimensions.x, dimensions.y);
}