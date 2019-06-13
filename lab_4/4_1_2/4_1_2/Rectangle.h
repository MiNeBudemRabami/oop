#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <string>

class RectangleC : public SolidShape
{
public:
	RectangleC(Point topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor);

	double GetArea()const;

	double GetPerimetr()const;

	std::string ToString()const;

	uint32_t GetOutlineColor()const;

	uint32_t GetFillColor()const;

	Point GetLeftTop()const;

	Point GetRightBottom()const;

	double GetWidth()const;

	double GetHeight()const;

private:

	Point m_topLeft;

	double m_hight;

	double m_width;

	uint32_t m_fillColor;

	uint32_t m_outlineColor;
};

