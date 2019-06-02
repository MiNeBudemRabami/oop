#include "pch.h"
#include "RectangleClass.h"
#include <string>


RectangleClass::RectangleClass(PointClass topLeft, double width, double hight, uint32_t outlineColor, uint32_t fillColor) 
{
	this->topLeft = topLeft;
	this->width = width;
	this->hight = hight;
	this->outlineColor = outlineColor;
	this->fillColor = fillColor;
}


RectangleClass::~RectangleClass()
{
}

double RectangleClass::getArea() const
{
	return width*hight;
}

double RectangleClass::getPerimetr() const
{
	return width*2 + hight*2;
}

std::string RectangleClass::toString() const
{
	return "rectangle has topLeftPoint in "+std::to_string(topLeft.x)+ std::to_string(topLeft.y) +" hight "+std::to_string(hight)+" weigth "+std::to_string(width)+" outlineColor " + std::to_string(outlineColor) + " fillColor " + std::to_string(fillColor);
}

uint32_t RectangleClass::getOutlineColor() const
{
	return outlineColor;
}

uint32_t RectangleClass::getFillColor() const
{
	return fillColor;
}

PointClass RectangleClass::getLeftTop() const
{
	return topLeft;
}

PointClass RectangleClass::getRightBottom() const
{
	PointClass rightBottom;
	rightBottom.x = topLeft.x + width;
	rightBottom.y = topLeft.y - hight;
	return rightBottom;
}

double RectangleClass::getWidth() const
{
	return 1;
}

double RectangleClass::getHeight() const
{
	return 1;
}