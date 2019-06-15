#include "pch.h"
#include "Circle.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include <string>

Circle::Circle(Point center, double radius, uint32_t outlineColor, uint32_t fillColor)
{
	this->m_center = center;
	this->m_radius = radius;
	this->m_outlineColor = outlineColor;
	this->m_fillColor = fillColor;
}

double Circle::GetArea() const
{
	return M_PI* m_radius*m_radius;
}

double Circle::GetPerimetr() const
{
	return 2*M_PI*m_radius;
}

std::string Circle::ToString() const
{
	return "Circle has radius " + std::to_string(m_radius) + " center.x " + std::to_string(m_center.x) + " center.y " + std::to_string(m_center.y) + " " + SolidShape::ToString();
}

uint32_t Circle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t Circle::GetFillColor() const
{
	return m_fillColor;
}

Point Circle::GetCenter() const
{
	return m_center;
}

double Circle::GetRadius() const
{
	return m_radius;
}

void Circle::Draw(ICanvas &canvas) const
{
	canvas.FillCircle(m_center, m_radius, m_fillColor);
	canvas.DrawCircle(m_center, m_radius, m_outlineColor);
}
