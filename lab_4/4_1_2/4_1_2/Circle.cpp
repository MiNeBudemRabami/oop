#include "pch.h"
#include "Circle.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <string>

Circle::Circle(Point center, double radius, uint32_t outlineColor, uint32_t fillColor)
{
	this->center = center;
	this->radius = radius;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


Circle::~Circle()
{
}


double Circle::GetArea() const
{
	return M_PI*radius*radius;
}

double Circle::GetPerimetr() const
{
	return 2*M_PI*radius;
}

std::string Circle::ToString() const
{
	return "Circle has radius " + std::to_string(radius) + " center.x " + std::to_string(center.x) + " center.y " + std::to_string(center.y) + " outlineColor " + std::to_string(outlineColor) + " fillColor " + std::to_string(fillColor);
}

uint32_t Circle::GetOutlineColor() const
{
	return outlineColor;
}

uint32_t Circle::GetFillColor() const
{
	return fillColor;
}

Point Circle::GetCenter() const
{
	return center;
}

double Circle::GetRadius() const
{
	return radius;
}