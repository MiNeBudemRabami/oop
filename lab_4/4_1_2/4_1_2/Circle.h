#pragma once
#include "SolidShape.h"
#include "Point.h"
#include <string>

class Circle : public SolidShape
{
public:
	Circle(Point center, double radius, uint32_t outlineColor, uint32_t fillColor);

	double GetArea()const;

	double GetPerimetr()const;

	std::string ToString()const;

	uint32_t GetOutlineColor()const;

	uint32_t GetFillColor()const;

	Point GetCenter()const;

	double GetRadius()const;

private:

	Point m_center;

	double m_radius;

	uint32_t m_fillColor;

	uint32_t m_outlineColor;
};

