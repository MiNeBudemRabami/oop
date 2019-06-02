#pragma once
#include "SolidShapeInterface.h"
#include "PointClass.h"
#include <string>

class TriangleClass
{
public:
	TriangleClass();
	~TriangleClass();

	double getArea();

	double getPerimetr();

	std::string toString();

	uint32_t getOutlineColor();

	uint32_t getFillColor();

	PointClass getVertex1();

	PointClass getVertex2();

	PointClass getVertex3();
};

