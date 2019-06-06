#pragma once
#include "Point.h"
#include "ISolidShape.h"
#include <string>

class RectangleC : public ISolidShape
{
public:
	RectangleC(Point topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor);

	~RectangleC();

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

	Point topLeft;

	double hight;

	double width;

	uint32_t fillColor;

	uint32_t outlineColor;
};

