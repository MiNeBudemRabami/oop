#pragma once
#include "IShape.h"
#include "Point.h"
#include <string>

class LineSegment : public IShape
{
public:
	LineSegment(Point startPoint, Point endPoint, uint32_t outlineColor);

	double GetArea()const;

	double GetLength()const;

	double GetPerimetr()const;

	std::string ToString()const;

	uint32_t GetOutlineColor()const;
	
	Point GetStartPoint()const;

	Point GetEndPoint()const;

private:

	uint32_t m_outlineColor;

	Point m_startPoint;

	Point m_endPoint;
};

