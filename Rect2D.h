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
		glm::vec2 normalizedPosition;
		glm::vec2 screenSpacePosition;
		glm::vec2 dimensions;
		GLfloat width;
		GLfloat height;

		Rect2D(glm::vec2 pos, glm::vec2 dim);

		void setColor(glm::vec3 newCol);
		void setColorRGB(glm::vec3 newColRGB);
		void setPosition(glm::vec2 newPos);
		void printCoordinates();
		void printDimensions();

	private:
		void normalizePosition(glm::vec2 pos);
		void normalizeDimensions(glm::vec2 dim);
		void initVertices();
};



#endif // !RECT_2D_CLASS_H