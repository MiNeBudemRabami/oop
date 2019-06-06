#pragma once
#include "SolidShape.h"
#include "Point.h"
#include <string>

class Triangle : public SolidShape
{
public:
	Triangle(Point vertex1, Point vertex2, Point vertex3, uint32_t outlineColor, uint32_t fillColor);

	~Triangle();

	double GetArea()const;

	double GetPerimetr()const;

	std::string ToString()const;

	uint32_t GetOutlineColor()const;

	uint32_t GetFillColor()const;

	Point GetVertex1()const;

	Point GetVertex2()const;

	Point GetVertex3()const;

private:

	Point vertex1;
	
	Point vertex2;

	Point vertex3;
	
	uint32_t fillColor;

	uint32_t outlineColor;
};

