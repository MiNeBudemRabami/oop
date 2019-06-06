#pragma once
class Point
{
public:

	Point() = default;
	Point(double x0, double y0)
		:x(x0), y(y0)
	{}

	double x = 0;
	double y = 0;
};

