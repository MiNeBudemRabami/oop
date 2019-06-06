#include "pch.h"
#include "LineSegmentClass.h"


LineSegmentClass::LineSegmentClass(PointClass startPoint, PointClass endPoint, uint32_t outlineColor)
{
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->outlineColor = outlineColor;
}


LineSegmentClass::~LineSegmentClass()
{
}

double LineSegmentClass::getArea() const
{
	return area;
}

double LineSegmentClass::getPerimetr() const
{
	return perimetr;
}

std::string LineSegmentClass::toString() const
{
	return "Line has startPoint in " + std::to_string(startPoint.x) + " " + std::to_string(startPoint.y) + " endPoint in " + std::to_string(endPoint.x) + " " + std::to_string(endPoint.y) + " outlineCollor is " + std::to_string(outlineColor);
}

uint32_t LineSegmentClass::getOutlineColor() const
{
	return outlineColor;
}

PointClass LineSegmentClass::getStartPoint() const
{
	return startPoint;
}

PointClass LineSegmentClass::getEndPoint() const
{
	return endPoint;
}