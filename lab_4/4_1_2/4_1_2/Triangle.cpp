#include "pch.h"
#include "Triangle.h"
#include <string>


Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3, uint32_t outlineColor, uint32_t fillColor)
{
	this->m_vertex1 = vertex1;
	this->m_vertex2 = vertex2;
	this->m_vertex3 = vertex3;
	this->m_outlineColor = outlineColor;
	this->m_fillColor = fillColor;
}

double Triangle::GetArea() const
{
	return abs((m_vertex2.x - m_vertex1.x)*(m_vertex3.y - m_vertex1.y) - (m_vertex3.x - m_vertex1.x)*(m_vertex2.y - m_vertex1.y)/2);
}

double Triangle::GetPerimetr() const
{
	return GetLength(m_vertex1, m_vertex2) + GetLength(m_vertex2, m_vertex3) + GetLength(m_vertex1, m_vertex3);
}

std::string Triangle::ToString() const
{
	return "triangle has vertex1 in " + std::to_string(m_vertex1.x) + " " + std::to_string(m_vertex1.y) + " vertex2 in " + std::to_string(m_vertex2.x) + " " + std::to_string(m_vertex2.y) + " vertex3 in " + std::to_string(m_vertex3.x) + " " + std::to_string(m_vertex3.y) + " " + SolidShape::ToString();
}

uint32_t Triangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t Triangle::GetFillColor() const
{
	return m_fillColor;
}

Point Triangle::GetVertex1() const
{
	return m_vertex1;
}

Point Triangle::GetVertex2() const
{
	return m_vertex2;
}

Point Triangle::GetVertex3() const
{
	return m_vertex3;
}

double Triangle::GetLength(Point v1, Point v2) const
{
	return sqrt((v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y));
}
