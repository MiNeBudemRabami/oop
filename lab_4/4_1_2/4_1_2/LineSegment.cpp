#include "pch.h"
#include "LineSegment.h"


LineSegment::LineSegment(Point startPoint, Point endPoint, uint32_t outlineColor)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->outlineColor = outlineColor;
}


LineSegment::~LineSegment()
{
}

double LineSegment::GetArea() const
{
	return 0;
}

double LineSegment::GetLength() const
{
	Point startPoint = GetStartPoint();
	Point endPoint = GetEndPoint();
	return sqrt((startPoint.x - endPoint.x)*(startPoint.x - endPoint.x) + (startPoint.y - endPoint.y)*(startPoint.y - endPoint.y));
}

double LineSegment::GetPerimetr() const
{
	return GetLength();
}

std::string LineSegment::ToString() const
{
	return "Line has startPoint in " + std::to_string(startPoint.x) + " " + std::to_string(startPoint.y) + " endPoint in " + std::to_string(endPoint.x) + " " + std::to_string(endPoint.y) + " outlineCollor is " + std::to_string(outlineColor);
}

uint32_t LineSegment::GetOutlineColor() const
{
	return outlineColor;
}

Point LineSegment::GetStartPoint() const
{
	return startPoint;
}

Point LineSegment::GetEndPoint() const
{
	return endPoint;
}