#include "pch.h"
#include "SolidShape.h"

std::string SolidShape::ToString() const
{
	return "outlineColor " + std::to_string(GetOutlineColor()) + " fillColor " + std::to_string(GetFillColor());
}
