#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_2_2\Calculator.h"

TEST_CASE("var", "[single-file]")
{
	Calculator calc;
	REQUIRE(calc.Var("a") == true);
}

TEST_CASE("let before var with same variable", "[single-file]")
{
	Calculator calc;
	calc.Let("a", 2);
	REQUIRE(calc.Var("a") == false);
}

TEST_CASE("let variable Get value from anotrher variable, first is undeclared", "[single-file]")
{
	Calculator calc;
	calc.Let("b", 1);
	REQUIRE(calc.Let("a", "b") == true);
}

TEST_CASE("let variable Get value from anotrher variable, bots are undeclared", "[single-file]")
{
	Calculator calc;
	REQUIRE(calc.Let("a", "b") == false);
}

TEST_CASE("fib", "[single-file]")
{
	Calculator calc;
	REQUIRE(calc.Let("v0", 0));
	REQUIRE(calc.Let("v1", 1));
	REQUIRE(calc.Fn("fib0", "v0"));
	REQUIRE(calc.Fn("fib1", "v1"));
	REQUIRE(calc.Fn("fib2", "fib1", "fib0", "+"));
	REQUIRE(calc.Fn("fib3", "fib2", "fib1", "+"));
	REQUIRE(calc.Fn("fib4", "fib3", "fib2", "+"));
	REQUIRE(calc.Fn("fib5", "fib4", "fib3", "+"));
	REQUIRE(calc.Fn("fib6", "fib5", "fib4", "+"));
	REQUIRE(calc.Get("fib0") == 0);
	REQUIRE(calc.Get("fib1") == 1);
	REQUIRE(calc.Get("fib2") == 1);
	REQUIRE(calc.Get("fib3") == 2);
	REQUIRE(calc.Get("fib4") == 3);
	REQUIRE(calc.Get("fib5") == 5);
	REQUIRE(calc.Get("fib6") == 8);
}
