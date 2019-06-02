#pragma once
#include "shapeInterface.h"

class SolidShapeInterface : public ShapeInterface
{
public:

	virtual uint32_t getFillColor() const = 0;

};