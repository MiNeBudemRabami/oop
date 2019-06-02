#pragma once
#include "PointClass.h"
#include "SolidShapeInterface.h"
#include <string>

class RectangleClass : public SolidShapeInterface
{
public:
	RectangleClass(PointClass topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor);

	~RectangleClass();

	double getArea()const;

	double getPerimetr()const;

	std::string toString()const;

	uint32_t getOutlineColor()const;

	uint32_t getFillColor()const;

	PointClass getLeftTop()const;

	PointClass getRightBottom()const;

	double getWidth()const;

	double getHeight()const;

private:

	PointClass topLeft;

	double hight;

	double width;

	uint32_t fillColor;

	uint32_t outlineColor;
};

