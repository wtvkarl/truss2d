#include "Rect2D.h"


//position of rectangle is set to the top left corner
//constructor that normalizes position and dimensions
Rect2D::Rect2D(glm::vec2 pos, glm::vec2 dim)
{
	screenSpacePosition = pos;
	//these are screenspace coordinates that need to be normalized
	normalizePosition(pos);
	normalizeDimensions(dim);
	initVertices();
}

void Rect2D::normalizePosition(glm::vec2 pos)
{
	GLfloat norm_x = (pos.x - 400) / 400;
	GLfloat norm_y = (pos.y - 400) / -400;

	normalizedPosition = glm::vec2(norm_x, norm_y);
}

void Rect2D::normalizeDimensions(glm::vec2 dim)
{
	width = dim.x / 400;
	height = dim.y / 400;

	dimensions = glm::vec2(width, height);
}

void Rect2D::initVertices()
{
	Vertex topLeft(normalizedPosition.x, normalizedPosition.y);
	Vertex topRight(normalizedPosition.x + width, normalizedPosition.y);
	Vertex bottomLeft(normalizedPosition.x, normalizedPosition.y - height);
	Vertex bottomRight(normalizedPosition.x + width, normalizedPosition.y - height);

	points.push_back(topLeft);
	points.push_back(topRight);
	points.push_back(bottomLeft);
	points.push_back(bottomRight);
}

void Rect2D::setColor(glm::vec3 newCol)
{
	//for some reason enhanced for-loops don't work as expected
	for (int i = 0; i < 4; i++)
		points.at(i).setColor(newCol);
}

void Rect2D::setColorRGB(glm::vec3 newColRGB)
{
	for (int i = 0; i < 4; i++)
		points.at(i).setColor(newColRGB / 255.0f);
}

void Rect2D::setPosition(glm::vec2 newPos)
{
	normalizePosition(newPos);
	
	//after normalizing position vec2, we can use it regularly to 
	//to reset the positions of each vertex.

	//top left
	points.at(0).setPosition(normalizedPosition);
	//top right
	points.at(1).setPosition(glm::vec2(normalizedPosition.x + width, normalizedPosition.y));
	//bottom left
	points.at(2).setPosition(glm::vec2(normalizedPosition.x, normalizedPosition.y - height));
	//bottom right
	points.at(3).setPosition(glm::vec2(normalizedPosition.x + width, normalizedPosition.y - height));
}

void Rect2D::printCoordinates()
{
	printf("Normalized Coordinates: [%.2f, %.2f]\n", normalizedPosition.x, normalizedPosition.y);
}

void Rect2D::printDimensions()
{
	printf("Normalized Dimensions: [%.2f, %.2f]\n", dimensions.x, dimensions.y);
}
