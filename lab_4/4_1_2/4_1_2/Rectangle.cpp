#include "pch.h"
#include "Rectangle.h"
#include <string>


RectangleC::RectangleC(Point topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor) 
{
	this->topLeft = topLeft;
	this->width = width;
	this->hight = hight;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


RectangleC::~RectangleC()
{
}

double RectangleC::GetArea() const
{
	return width*hight;
}

double RectangleC::GetPerimetr() const
{
	return width*2 + hight*2;
}

std::string RectangleC::ToString() const
{
	return "rectangle has topLeftPoint in "+std::to_string(topLeft.x)+ std::to_string(topLeft.y) +" hight "+std::to_string(hight)+" weigth "+std::to_string(width)+" outlineColor " + std::to_string(outlineColor) + " fillColor " + std::to_string(fillColor);
}

uint32_t RectangleC::GetOutlineColor() const
{
	return outlineColor;
}

uint32_t RectangleC::GetFillColor() const
{
	return fillColor;
}

Point RectangleC::GetLeftTop() const
{
	return topLeft;
}

Point RectangleC::GetRightBottom() const
{
	Point rightBottom;
	rightBottom.x = topLeft.x + width;
	rightBottom.y = topLeft.y - hight;
	return rightBottom;
}

double RectangleC::GetWidth() const
{
	return width;
}

double RectangleC::GetHeight() const
{
	return hight;
}