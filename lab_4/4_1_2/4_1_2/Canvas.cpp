#include "pch.h"
#include "Canvas.h"
#include <string>

Canvas::Canvas(std::ostream & out)
	: m_out(out)
{
	out << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>" << std::endl;
	out << "<svg xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
}

Canvas::~Canvas()
{
	m_out << "</svg>" << std::endl;
}

void Canvas::DrawLine(Point from, Point to, uint32_t lineColor)
{
	m_out << "<line x1=\"" << from.x << "\" y1=\"" << from.y << "\" x2=\"" << to.x << "\" y2=\"" << to.y << "\" style=\"stroke:" << ConvertColor(lineColor) << "\" />" << std::endl;
}

void Canvas::FillPolygon(std::vector<Point> const & points, uint32_t fillColor)
{
	m_out << "<polyline points=\"" << ConvertPoints(points) << "\" fill=\"" << ConvertColor(fillColor) << "\" />" << std::endl;
}

void Canvas::DrawCircle(Point center, double radius, uint32_t lineColor)
{
	m_out << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\" fill=\"none\" stroke=\"" << ConvertColor(lineColor) << "\" />" << std::endl;
}

void Canvas::FillCircle(Point center, double radius, uint32_t fillColor)
{
	m_out << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\" fill=\"" << ConvertColor(fillColor) << "\" />" << std::endl;
}

std::string Canvas::ConvertColor(uint32_t color) const
{
	return std::string("rgb(") + std::to_string((color / (256 * 256)) % 256) + "," + std::to_string((color / 256) % 256) + "," + std::to_string(color % 256) + ")";
}

std::string Canvas::ConvertPoints(std::vector<Point> const & points) const
{
	std::string result;

	for (auto point : points)
	{
		if (!result.empty())
		{
			result += " ";
		}

		result += std::to_string(point.x);
		result += ",";
		result += std::to_string(point.y);
	}

	return result;
}
