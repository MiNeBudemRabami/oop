#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\4_1_2\CircleClass.h"
#include "..\4_1_2\LineSegmentClass.h"
#include "..\4_1_2\RectangleClass.h"
#include "..\4_1_2\TriangleClass.h"


TEST_CASE("circle processing", "[single-file]")
{
	PointClass center;
	center.x = 10;
	center.y = 5;
	CircleClass circle(center, 10, 111111, 222222);
	REQUIRE(circle.getArea() == Approx(314.159));
	REQUIRE(circle.getPerimetr() == Approx(62.8318));
	REQUIRE(circle.getOutlineColor() == 111111);
	REQUIRE(circle.getFillColor() == 222222);
	REQUIRE(circle.getCenter().x == 10);
	REQUIRE(circle.getCenter().y == 5);
	REQUIRE(circle.getRadius() == 10);
}

TEST_CASE("line processing", "[single-file]")
{
	PointClass startPoint;
	startPoint.x = 10;
	startPoint.y = 5;

	PointClass endPoint;
	endPoint.x = 100;
	endPoint.y = 50;
	LineSegmentClass lineSegment(startPoint, endPoint, 111111);
	REQUIRE(lineSegment.getArea() == 0);
	REQUIRE(lineSegment.getPerimetr() == 0);
	REQUIRE(lineSegment.getOutlineColor() == 111111);
	REQUIRE(lineSegment.getStartPoint().x == 10);
	REQUIRE(lineSegment.getStartPoint().y == 5);
	REQUIRE(lineSegment.getEndPoint().x == 100);
	REQUIRE(lineSegment.getEndPoint().y == 50);
}

TEST_CASE("rectangle processing", "[single-file]")
{
	PointClass topLeft;
	topLeft.x = 10;
	topLeft.y = 5;
	RectangleClass rectangle(topLeft, 10 , 10, 111111, 222222);
	REQUIRE(rectangle.getArea() == 100);
	REQUIRE(rectangle.getPerimetr() == 40);
	REQUIRE(rectangle.getOutlineColor() == 111111);
	REQUIRE(rectangle.getFillColor() == 222222);
	REQUIRE(rectangle.getLeftTop().x == 10);
	REQUIRE(rectangle.getLeftTop().y == 5);
	REQUIRE(rectangle.getRightBottom().x == 20);
	REQUIRE(rectangle.getRightBottom().y == -5);

}

TEST_CASE("triangle processing", "[single-file]")
{
	PointClass vertex1;
	vertex1.x = 0;
	vertex1.y = 0;

	PointClass vertex2;
	vertex2.x = 0;
	vertex2.y = 10;

	PointClass vertex3;
	vertex3.x = 10;
	vertex3.y = 0;
	TriangleClass triangle(vertex1, vertex2, vertex3, 111111, 222222);
	REQUIRE(triangle.getArea() == 50);
	REQUIRE(triangle.getPerimetr() == Approx(34.1421));
	REQUIRE(triangle.getOutlineColor() == 111111);
	REQUIRE(triangle.getFillColor() == 222222);

	REQUIRE(triangle.getVertex1().x == 0);
	REQUIRE(triangle.getVertex1().y == 0);

	REQUIRE(triangle.getVertex2().x == 0);
	REQUIRE(triangle.getVertex2().y == 10);

	REQUIRE(triangle.getVertex3().x == 10);
	REQUIRE(triangle.getVertex3().y == 0);
}
