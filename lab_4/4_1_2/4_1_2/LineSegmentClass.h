#pragma once
#include "ShapeInterface.h"
#include "PointClass.h"
#include <string>

class LineSegmentClass
{
public:
	LineSegmentClass();
	~LineSegmentClass();

	double getArea();

	double getPerimetr();

	std::string toString();

	uint32_t getOutlineColor();
	
	PointClass getStatPoint();

	PointClass getEndPoint();


};

