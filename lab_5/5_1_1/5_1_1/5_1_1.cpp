#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>

#include "ComplexClass.h"

TEST_CASE("mag", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a.GetMagnitude() == Approx(2.23606));
}

TEST_CASE("arg", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a.GetArgument() == Approx(1.10714));
}

TEST_CASE("c+c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	REQUIRE(a + b == ComplexClass(6, 10));
}

TEST_CASE("c+r", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a + 4 == ComplexClass(5, 2));
}

TEST_CASE("c-c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	REQUIRE(a - b == ComplexClass(-4, -6));
}

TEST_CASE("c-r", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a - 4 == ComplexClass(-3, 2));
}

TEST_CASE("c*c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	REQUIRE(a * b == ComplexClass(-11, 18));
}

TEST_CASE("c*r", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a * 5 == ComplexClass(5, 10));
}

TEST_CASE("c/c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	REQUIRE(a / b == ComplexClass(0.23595505617977527, 0.02247191011235955));
}

TEST_CASE("c/r", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(a / 5 == ComplexClass(0.2, 0.4));
}
