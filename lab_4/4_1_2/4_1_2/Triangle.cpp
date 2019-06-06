#include "pch.h"
#include "Triangle.h"
#include <string>


Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, uint32_t outlineColor, uint32_t fillColor)
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->vertex3 = vertex3;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


Triangle::~Triangle()
{
}

double Triangle::GetArea() const
{
	return abs((vertex2.x - vertex1.x)*(vertex3.y - vertex1.y) - (vertex3.x - vertex1.x)*(vertex2.y - vertex1.y)/2);
}

double Triangle::GetPerimetr() const
{
	return GetLength(vertex1, vertex2) + GetLength(vertex2, vertex3) + GetLength(vertex1, vertex3);
}

std::string Triangle::ToString() const
{
	return "triangle has vertex1 in " + std::to_string(vertex1.x) + " " + std::to_string(vertex1.y) + " vertex2 in " + std::to_string(vertex2.x) + " " + std::to_string(vertex2.y) + " vertex3 in " + std::to_string(vertex3.x) + " " + std::to_string(vertex3.y) + " " + SolidShape::ToString();
}

uint32_t Triangle::GetOutlineColor() const
{
	return outlineColor;
}

uint32_t Triangle::GetFillColor() const
{
	return fillColor;
}

Point Triangle::GetVertex1() const
{
	return vertex1;
}

Point Triangle::GetVertex2() const
{
	return vertex2;
}

Point Triangle::GetVertex3() const
{
	return vertex3;
}

double Triangle::GetLength(Point v1, Point v2) const
{
	return sqrt((v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y));
}
