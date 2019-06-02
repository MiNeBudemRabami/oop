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

TEST_CASE("+c", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(+a == a);
}

TEST_CASE("-c", "[single-file]")
{
	ComplexClass a(1, 2);
	REQUIRE(-a == ComplexClass(-1, -2));
}

TEST_CASE("c+=c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	a += b;
	REQUIRE(a == ComplexClass(6, 10));
}

TEST_CASE("c+=r", "[single-file]")
{
	ComplexClass a(1, 2);
	a += 42;
	REQUIRE(a == ComplexClass(43, 2));
}

TEST_CASE("c-=c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	a -= b;
	REQUIRE(a == ComplexClass(-4, -6));
}

TEST_CASE("c-=r", "[single-file]")
{
	ComplexClass a(1, 2);
	a -= 42;
	REQUIRE(a == ComplexClass(-41, 2));
}

TEST_CASE("c*=c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	a *= b;
	REQUIRE(a == ComplexClass(-11, 18));
}

TEST_CASE("c*=r", "[single-file]")
{
	ComplexClass a(1, 2);
	a *= 42;
	REQUIRE(a == ComplexClass(42, 84));
}

TEST_CASE("c/=c", "[single-file]")
{
	ComplexClass a(1, 2);
	ComplexClass b(5, 8);
	a /= b;
	REQUIRE(a == ComplexClass(0.23595505617977527, 0.02247191011235955));
}

TEST_CASE("c/=r", "[single-file]")
{
	ComplexClass a(1, 2);
	a /= 5;
	REQUIRE(a == ComplexClass(0.2, 0.4));
}

TEST_CASE("c==c", "[single-file]")
{
	ComplexClass a(65, 221);
	ComplexClass b(65, 221);
	REQUIRE(a == b);
}

TEST_CASE("c==r", "[single-file]")
{
	ComplexClass a(123, 0);
	REQUIRE(a == 123);
}

TEST_CASE("c!=c", "[single-file]")
{
	ComplexClass a(65, 221);
	ComplexClass b(88, 221);
	REQUIRE(a != b);
}

TEST_CASE("c!=r", "[single-file]")
{
	ComplexClass a(123, 22);
	REQUIRE(a != 123);
}
