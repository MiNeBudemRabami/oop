#include "pch.h"
#include "Point.h"

bool Point::operator==(Point const& p) const
{
	return x == p.x && y == p.y;
}
