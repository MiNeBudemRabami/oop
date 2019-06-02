#pragma once
#include "SolidShapeInterface.h"
#include "PointClass.h"
#include <string>



class CircleClass : public SolidShapeInterface
{
public:

	CircleClass(PointClass center, double radius, uint32_t outlineColor, uint32_t fillColor);

	~CircleClass();

	double getArea()const;

	double getPerimetr()const;

	std::string toString()const;

	uint32_t getOutlineColor()const;

	uint32_t getFillColor()const;

	PointClass getCenter()const;

	double getRadius()const;

private:

	PointClass center;

	double radius;

	uint32_t fillColor;

	uint32_t outlineColor;
};

