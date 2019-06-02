#include "pch.h"
#include "LineSegmentClass.h"


LineSegmentClass::LineSegmentClass()
{
}


LineSegmentClass::~LineSegmentClass()
{
}

double LineSegmentClass::getArea()
{
	return 1;
}

double LineSegmentClass::getPerimetr()
{
	return 1;
}

std::string LineSegmentClass::toString()
{
	return "";
}

uint32_t LineSegmentClass::getOutlineColor()
{
	return 1;
}

PointClass LineSegmentClass::getStatPoint()
{
	return PointClass();
}

PointClass LineSegmentClass::getEndPoint()
{
	return PointClass();
}