#pragma once

#include <ostream>
#include "ICanvas.h"

class Canvas : public ICanvas
{
public:
	Canvas(std::ostream &out);
	~Canvas();

	void DrawLine(Point from, Point to, uint32_t lineColor);
	void FillPolygon(std::vector<Point> const& points, uint32_t fillColor);
	void DrawCircle(Point center, double radius, uint32_t lineColor);
	void FillCircle(Point center, double radius, uint32_t fillColor);

private:
	std::string ConvertColor(uint32_t color) const;
	std::string ConvertPoints(std::vector<Point> const& points) const;

	std::ostream &m_out;
};
