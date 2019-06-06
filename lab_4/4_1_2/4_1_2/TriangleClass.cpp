#include "pch.h"
#include "TriangleClass.h"
#include <string>


TriangleClass::TriangleClass(PointClass vertex1, PointClass vertex2, PointClass vertex3, uint32_t outlineColor, uint32_t fillColor)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->vertex3 = vertex3;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


TriangleClass::~TriangleClass()
{
}

double TriangleClass::getArea() const
{
	return abs((vertex2.x - vertex1.x)*(vertex3.y - vertex1.y) - (vertex3.x - vertex1.x)*(vertex2.y - vertex1.y)/2);
}

double TriangleClass::getPerimetr() const
{
	double side1 = sqrt((vertex2.x - vertex1.x)*(vertex2.x - vertex1.x) + (vertex2.y - vertex1.y)*(vertex2.y - vertex1.y));
	double side2 = sqrt((vertex3.x - vertex2.x)*(vertex3.x - vertex2.x) + (vertex3.y - vertex2.y)*(vertex3.y - vertex2.y));
	double side3 = sqrt((vertex3.x - vertex1.x)*(vertex3.x - vertex1.x) + (vertex3.y - vertex1.y)*(vertex3.y - vertex1.y));
	return side1 + side2 + side3;
}

std::string TriangleClass::toString() const
{
	return "triangle has vertex1 in " + std::to_string(vertex1.x) + " " + std::to_string(vertex1.y) + " vertex2 in " + std::to_string(vertex2.x) + " " + std::to_string(vertex2.y) + " vertex3 in " + std::to_string(vertex3.x) + " " + std::to_string(vertex3.y) + " outlineColor " + std::to_string(outlineColor) + " fillColor " + std::to_string(fillColor);
}

uint32_t TriangleClass::getOutlineColor() const
{
	return outlineColor;
}

uint32_t TriangleClass::getFillColor() const
{
	return fillColor;
}

PointClass TriangleClass::getVertex1() const
{
	return vertex1;
}

PointClass TriangleClass::getVertex2() const
{
	return vertex2;
}

PointClass TriangleClass::getVertex3() const
{
	return vertex3;
}