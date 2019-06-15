#define CATCH_CONFIG_MAIN
#include "..\..\..\catch.hpp"
#include <iostream>

#include "Complex.h"

TEST_CASE("mag", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a.GetMagnitude() == Approx(2.23606));
}

TEST_CASE("arg", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a.GetArgument() == Approx(1.10714));
}

TEST_CASE("c+c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	REQUIRE(a + b == Complex(6, 10));
}

TEST_CASE("c+r", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a + 4 == Complex(5, 2));
}

TEST_CASE("r+c", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(4 + a == Complex(5, 2));
}

TEST_CASE("c-c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	REQUIRE(a - b == Complex(-4, -6));
}

TEST_CASE("c-r", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a - 4 == Complex(-3, 2));
}

TEST_CASE("c*c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	REQUIRE(a * b == Complex(-11, 18));
}

TEST_CASE("c*r", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a * 5 == Complex(5, 10));
}

TEST_CASE("c/c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	REQUIRE(a / b == Complex(0.23595505617977527, 0.02247191011235955));
}

TEST_CASE("c/r", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(a / 5 == Complex(0.2, 0.4));
}

TEST_CASE("+c", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(+a == a);
}

TEST_CASE("-c", "[single-file]")
{
	Complex a(1, 2);
	REQUIRE(-a == Complex(-1, -2));
}

TEST_CASE("c+=c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	a += b;
	REQUIRE(a == Complex(6, 10));
}

TEST_CASE("c+=r", "[single-file]")
{
	Complex a(1, 2);
	a += 42;
	REQUIRE(a == Complex(43, 2));
}

TEST_CASE("c-=c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	a -= b;
	REQUIRE(a == Complex(-4, -6));
}

TEST_CASE("c-=r", "[single-file]")
{
	Complex a(1, 2);
	a -= 42;
	REQUIRE(a == Complex(-41, 2));
}

TEST_CASE("c*=c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	a *= b;
	REQUIRE(a == Complex(-11, 18));
}

TEST_CASE("c*=r", "[single-file]")
{
	Complex a(1, 2);
	a *= 42;
	REQUIRE(a == Complex(42, 84));
}

TEST_CASE("c/=c", "[single-file]")
{
	Complex a(1, 2);
	Complex b(5, 8);
	a /= b;
	REQUIRE(a == Complex(0.23595505617977527, 0.02247191011235955));
}

TEST_CASE("c/=r", "[single-file]")
{
	Complex a(1, 2);
	a /= 5;
	REQUIRE(a == Complex(0.2, 0.4));
}

TEST_CASE("c==c", "[single-file]")
{
	Complex a(65, 221);
	Complex b(65, 221);
	REQUIRE(a == b);
}

TEST_CASE("c==r", "[single-file]")
{
	Complex a(123, 0);
	REQUIRE(a == 123);
}

TEST_CASE("c!=c", "[single-file]")
{
	Complex a(65, 221);
	Complex b(88, 221);
	REQUIRE(a != b);
}

TEST_CASE("c!=r", "[single-file]")
{
	Complex a(123, 22);
	REQUIRE(a != 123);
}
