#include "pch.h"
#include "LineSegment.h"


LineSegment::LineSegment(Point startPoint, Point endPoint, uint32_t outlineColor)
{
	this->m_startPoint = startPoint;
	this->m_endPoint = endPoint;
	this->m_outlineColor = outlineColor;
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
	return "Line has startPoint in " + std::to_string(m_startPoint.x) + " " + std::to_string(m_startPoint.y) + " endPoint in " + std::to_string(m_endPoint.x) + " " + std::to_string(m_endPoint.y) + " outlineCollor is " + std::to_string(m_outlineColor);
}

uint32_t LineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

Point LineSegment::GetStartPoint() const
{
	return m_startPoint;
}

Point LineSegment::GetEndPoint() const
{
	return m_endPoint;
}