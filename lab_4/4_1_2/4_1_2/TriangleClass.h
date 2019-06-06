#pragma once
#include "SolidShapeInterface.h"
#include "PointClass.h"
#include <string>

class TriangleClass : public SolidShapeInterface
{
public:
	TriangleClass(PointClass vertex1, PointClass vertex2, PointClass vertex3, uint32_t outlineColor, uint32_t fillColor);

	~TriangleClass();

	double getArea()const;

	double getPerimetr()const;

	std::string toString()const;

	uint32_t getOutlineColor()const;

	uint32_t getFillColor()const;

	PointClass getVertex1()const;

	PointClass getVertex2()const;

	PointClass getVertex3()const;

private:

	PointClass vertex1;
	
	PointClass vertex2;

	PointClass vertex3;
	
	uint32_t fillColor;

	uint32_t outlineColor;
};

