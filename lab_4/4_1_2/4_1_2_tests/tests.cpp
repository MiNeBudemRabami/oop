#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

#include "..\4_1_2\Circle.h"
#include "..\4_1_2\LineSegment.h"
#include "..\4_1_2\Rectangle.h"
#include "..\4_1_2\Triangle.h"

class Canvas : public ICanvas
{
public:
	enum class Type
	{
		LINE, POLYGON, CIRCLE_DRAW, CIRCLE_FILL
	};

	struct Element
	{
		Element(Point from, Point to, uint32_t lineColor)
			: type(Type::LINE)
			, from(from)
			, to(to)
			, outlineColor(lineColor)
		{
		}

		Element(Point center, double radius, uint32_t color, bool fill)
			: type(fill ? Type::CIRCLE_FILL : Type::CIRCLE_DRAW)
			, center(center)
			, radius(radius)
			, outlineColor(color)
			, fillColor(color)
		{
		}

		Element(std::vector<Point> const& points, uint32_t fillColor)
			: type(Type::POLYGON)
			, points(points)
			, fillColor(fillColor)
		{
		}

		Type type;
		Point from;
		Point to;
		Point center;
		uint32_t outlineColor;
		uint32_t fillColor;
		double radius;
		std::vector<Point> points;

		bool operator==(Element const& e) const
		{
			return type == e.type &&
				from == e.from &&
				to == e.to &&
				center == e.center &&
				outlineColor == e.outlineColor &&
				fillColor == e.fillColor &&
				radius == e.radius &&
				points == e.points;
		}
	};

	void DrawLine(Point from, Point to, uint32_t lineColor)
	{
		m_data.push_back(Element(from, to, lineColor));
	}

	void FillPolygon(std::vector<Point> const& points, uint32_t fillColor)
	{
		m_data.push_back(Element(points, fillColor));
	}

	void DrawCircle(Point center, double radius, uint32_t lineColor)
	{
		m_data.push_back(Element(center, radius, lineColor, false));
	}

	void FillCircle(Point center, double radius, uint32_t fillColor)
	{
		m_data.push_back(Element(center, radius, fillColor, true));
	}

	std::vector<Element> const& GetData() const
	{
		return m_data;
	}

private:
	std::vector<Element> m_data;
};

TEST_CASE("circle processing", "[single-file]")
{
	Point center;
	center.x = 10;
	center.y = 5;
	Circle circle(center, 10, 111111, 222222);
	REQUIRE(circle.GetArea() == Approx(314.159));
	REQUIRE(circle.GetPerimetr() == Approx(62.8318));
	REQUIRE(circle.GetOutlineColor() == 111111);
	REQUIRE(circle.GetFillColor() == 222222);
	REQUIRE(circle.GetCenter().x == 10);
	REQUIRE(circle.GetCenter().y == 5);
	REQUIRE(circle.GetRadius() == 10);
	REQUIRE(circle.ToString() == "Circle has radius 10.000000 center.x 10.000000 center.y 5.000000 outlineColor 111111 fillColor 222222");
}

TEST_CASE("line processing", "[single-file]")
{
	Point startPoint;
	startPoint.x = 10;
	startPoint.y = 5;

	Point endPoint;
	endPoint.x = 100;
	endPoint.y = 50;
	LineSegment LineSegment(startPoint, endPoint, 111111);
	REQUIRE(LineSegment.GetArea() == 0);
	REQUIRE(LineSegment.GetPerimetr() == Approx(100.623));
	REQUIRE(LineSegment.GetOutlineColor() == 111111);
	REQUIRE(LineSegment.GetStartPoint().x == 10);
	REQUIRE(LineSegment.GetStartPoint().y == 5);
	REQUIRE(LineSegment.GetEndPoint().x == 100);
	REQUIRE(LineSegment.GetEndPoint().y == 50);
	REQUIRE(LineSegment.ToString() == "Line has startPoint in 10.000000 5.000000 endPoint in 100.000000 50.000000 outlineCollor is 111111");
}

TEST_CASE("rectangle processing", "[single-file]")
{
	Point topLeft;
	topLeft.x = 10;
	topLeft.y = 5;
	RectangleC rectangle(topLeft, 10 , 10, 111111, 222222);
	REQUIRE(rectangle.GetArea() == 100);
	REQUIRE(rectangle.GetPerimetr() == 40);
	REQUIRE(rectangle.GetOutlineColor() == 111111);
	REQUIRE(rectangle.GetFillColor() == 222222);
	REQUIRE(rectangle.GetLeftTop().x == 10);
	REQUIRE(rectangle.GetLeftTop().y == 5);
	REQUIRE(rectangle.GetRightBottom().x == 20);
	REQUIRE(rectangle.GetRightBottom().y == 15);
	REQUIRE(rectangle.ToString() == "rectangle has topLeftPoint in 10.0000005.000000 hight 10.000000 weigth 10.000000 outlineColor 111111 fillColor 222222");
}

TEST_CASE("triangle processing", "[single-file]")
{
	Point vertex1;
	vertex1.x = 0;
	vertex1.y = 0;

	Point vertex2;
	vertex2.x = 0;
	vertex2.y = 10;

	Point vertex3;
	vertex3.x = 10;
	vertex3.y = 0;
	Triangle triangle(vertex1, vertex2, vertex3, 111111, 222222);
	REQUIRE(triangle.GetArea() == 50);
	REQUIRE(triangle.GetPerimetr() == Approx(34.1421));
	REQUIRE(triangle.GetOutlineColor() == 111111);
	REQUIRE(triangle.GetFillColor() == 222222);

	REQUIRE(triangle.GetVertex1().x == 0);
	REQUIRE(triangle.GetVertex1().y == 0);

	REQUIRE(triangle.GetVertex2().x == 0);
	REQUIRE(triangle.GetVertex2().y == 10);

	REQUIRE(triangle.GetVertex3().x == 10);
	REQUIRE(triangle.GetVertex3().y == 0);

	REQUIRE(triangle.ToString() == "triangle has vertex1 in 0.000000 0.000000 vertex2 in 0.000000 10.000000 vertex3 in 10.000000 0.000000 outlineColor 111111 fillColor 222222");
}

TEST_CASE("draw line", "[single-file]")
{
	uint32_t color = 0x00ff00;
	LineSegment line(Point(10, 20), Point(40, 30), color);
	Canvas canvas;
	line.Draw(canvas);

	auto &d = canvas.GetData();
	REQUIRE(d.size() == 1);
	REQUIRE(d[0] == Canvas::Element(Point(10, 20), Point(40, 30), color));
}

TEST_CASE("draw circle", "[single-file]")
{
	uint32_t fill = 0xff00ff;
	uint32_t out = 0x00ff00;
	Circle circle(Point(10, 10), 7, out, fill);
	Canvas canvas;
	circle.Draw(canvas);

	auto &d = canvas.GetData();
	REQUIRE(d.size() == 2);
	REQUIRE(d[0] == Canvas::Element(Point(10, 10), 7, fill, true));
	REQUIRE(d[1] == Canvas::Element(Point(10, 10), 7, out, false));
}

TEST_CASE("draw rectangle", "[single-file]")
{
	uint32_t fill = 0xff00ff;
	uint32_t out = 0x00ff00;

	Point p1 = Point(10, 10);
	Point p3 = Point(50, 40);
	Point p2(p3.x, p1.y);
	Point p4(p1.x, p3.y);

	RectangleC rect(p1, 40, 30, out, fill);
	Canvas canvas;
	rect.Draw(canvas);

	auto &d = canvas.GetData();
	REQUIRE(d.size() == 5);
	REQUIRE(d[0] == Canvas::Element({ p1, p2, p3, p4 }, fill));
	REQUIRE(d[1] == Canvas::Element(p1, p2, out));
	REQUIRE(d[2] == Canvas::Element(p2, p3, out));
	REQUIRE(d[3] == Canvas::Element(p3, p4, out));
	REQUIRE(d[4] == Canvas::Element(p4, p1, out));
}

TEST_CASE("draw triangle", "[single-file]")
{
	uint32_t fill = 0xff00ff;
	uint32_t out = 0x00ff00;

	Point p1 = Point(10, 10);
	Point p2 = Point(70, 90);
	Point p3 = Point(50, 40);

	Triangle triangle(p1, p2, p3, out, fill);
	Canvas canvas;
	triangle.Draw(canvas);

	auto &d = canvas.GetData();
	REQUIRE(d.size() == 4);
	REQUIRE(d[0] == Canvas::Element({ p1, p2, p3 }, fill));
	REQUIRE(d[1] == Canvas::Element(p1, p2, out));
	REQUIRE(d[2] == Canvas::Element(p2, p3, out));
	REQUIRE(d[3] == Canvas::Element(p3, p1, out));
}
