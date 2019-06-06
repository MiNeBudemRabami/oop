#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

#include "..\4_1_2\Circle.h"
#include "..\4_1_2\LineSegment.h"
#include "..\4_1_2\Rectangle.h"
#include "..\4_1_2\Triangle.h"


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
	REQUIRE(rectangle.GetRightBottom().y == -5);

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
}
