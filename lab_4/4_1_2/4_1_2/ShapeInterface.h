#pragma once
#include <string>

class ShapeInterface
{
public:

	virtual double getArea() const = 0;

	virtual double getPerimetr() const = 0;

	virtual std::string toString() const = 0;

	virtual uint32_t getOutlineColor() const = 0;
};
