#include "pch.h"
#include "Rectangle.h"
#include <string>


RectangleC::RectangleC(Point topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor) 
{
	this->m_topLeft = topLeft;
	this->m_width = width;
	this->m_hight = hight;
	this->m_outlineColor = outlineColor;
	this->m_fillColor = fillColor;
}

double RectangleC::GetArea() const
{
	return m_width* m_hight;
}

double RectangleC::GetPerimetr() const
{
	return m_width*2 + m_hight*2;
}

std::string RectangleC::ToString() const
{
	return "rectangle has topLeftPoint in "+std::to_string(m_topLeft.x)+ std::to_string(m_topLeft.y) +" hight "+std::to_string(m_hight)+" weigth "+std::to_string(m_width) + " " + SolidShape::ToString();
}

uint32_t RectangleC::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t RectangleC::GetFillColor() const
{
	return m_fillColor;
}

Point RectangleC::GetLeftTop() const
{
	return m_topLeft;
}

Point RectangleC::GetRightBottom() const
{
	Point rightBottom;
	rightBottom.x = m_topLeft.x + m_width;
	rightBottom.y = m_topLeft.y - m_hight;
	return rightBottom;
}

double RectangleC::GetWidth() const
{
	return m_width;
}

double RectangleC::GetHeight() const
{
	return m_hight;
}