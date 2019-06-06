#pragma once
#include "ShapeInterface.h"
#include "PointClass.h"
#include <string>

class LineSegmentClass : public ShapeInterface
{
public:
	LineSegmentClass(PointClass startPoint, PointClass endPoint, uint32_t outlineColor);

	~LineSegmentClass();

	double getArea()const;

	double getPerimetr()const;

	std::string toString()const;

	uint32_t getOutlineColor()const;
	
	PointClass getStartPoint()const;

	PointClass getEndPoint()const;

private:

	double const area = 0;

	double const perimetr = 0;

	uint32_t outlineColor;

	PointClass startPoint;

	PointClass endPoint;
};

