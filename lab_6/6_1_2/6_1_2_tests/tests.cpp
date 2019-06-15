#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"

#include "..\6_1_2\Solver.h"

TEST_CASE("a=0", "[single-file]")
{
	REQUIRE_THROWS_AS(Solve(0, 1, 2), std::invalid_argument);
}

TEST_CASE("no roots", "[single-file]")
{
	REQUIRE_THROWS_AS(Solve(1, 1, 1), std::domain_error);
}

TEST_CASE("1 root", "[single-file]")
{
	auto r = Solve(1, -2, 1);
	REQUIRE(r.numRoots == 1);
	REQUIRE(r.roots[0] == 1);
}

TEST_CASE("2 roots", "[single-file]")
{
	auto r = Solve(1, -5, 2);
	REQUIRE(r.numRoots == 2);
	REQUIRE(r.roots[0] == Approx(4.56155));
	REQUIRE(r.roots[1] == Approx(0.438447));
}

TEST_CASE("2 int roots", "[single-file]")
{
	auto r = Solve(1, -5, 6);
	REQUIRE(r.numRoots == 2);
	REQUIRE(r.roots[0] == Approx(3));
	REQUIRE(r.roots[1] == Approx(2));
}