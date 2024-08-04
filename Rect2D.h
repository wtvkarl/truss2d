#ifndef RECT_2D_CLASS_H
#define RECT_2D_CLASS_H

#include "VBO.h"
#include "Shader.h"
#include <vector>

class Rect2D
{
	public:
		std::vector <Vertex> points = {};

		//these are all normalized first
		glm::vec2 position;
		glm::vec2 dimensions;
		GLfloat width;
		GLfloat height;

		Rect2D(glm::vec2 pos, glm::vec2 dim);

		void setColor(GLfloat r, GLfloat g, GLfloat b);
		void setPosition(glm::vec2 newPos);
		void printCoordinates();
		void printDimensions();

	private:
		void normalize(glm::vec2 pos, glm::vec2 dim);
		void initVertices();
};



#endif // !RECT_2D_CLASS_H