#include "pch.h"
#include "CircleClass.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <string>

CircleClass::CircleClass(PointClass center, double radius, uint32_t outlineColor, uint32_t fillColor)
{
	this->center = center;
	this->radius = radius;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


CircleClass::~CircleClass()
{
}


double CircleClass::getArea() const
{
	return M_PI*radius*radius;
}

double CircleClass::getPerimetr() const
{
	return 2*M_PI*radius;
}

std::string CircleClass::toString() const
{
	return "Circle has radius " + std::to_string(radius) + " center.x " + std::to_string(center.x) + " center.y " + std::to_string(center.y) + " outlineColor " + std::to_string(outlineColor) + " fillColor " + std::to_string(fillColor);
}

uint32_t CircleClass::getOutlineColor() const
{
	return outlineColor;
}

uint32_t CircleClass::getFillColor() const
{
	return fillColor;
}

PointClass CircleClass::getCenter() const
{
	return center;
}

double CircleClass::getRadius() const
{
	return radius;
}