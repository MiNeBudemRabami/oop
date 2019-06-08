#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_2_2\Variables.h"
#include "..\3_2_2\Functions.h"

TEST_CASE("var", "[single-file]")
{
	Variables varib;
	Functions func;
	REQUIRE(varib.var("a", func) == true);
}

TEST_CASE("let before var with same variable", "[single-file]")
{
	Variables varib;
	Functions func;
	varib.Let("a", 2, func);
	REQUIRE(varib.var("a", func) == false);
}

TEST_CASE("let variable get value from anotrher variable, first is undeclared", "[single-file]")
{
	Variables varib;
	Functions func;
	varib.Let("b", 1, func);
	REQUIRE(varib.Let("a", "b", func) == true);
}

TEST_CASE("let variable get value from anotrher variable, bots are undeclared", "[single-file]")
{
	Variables varib;
	Functions func;
	REQUIRE(varib.Let("a", "b", func) == false);
}

TEST_CASE("fib", "[single-file]")
{
	Variables varib;
	Functions func;
	REQUIRE(varib.Let("v0", 0, func));
	REQUIRE(varib.Let("v1", 1, func));
	REQUIRE(func.Fn("fib0", "v0"));
	REQUIRE(func.Fn("fib1", "v1"));
	REQUIRE(func.Fn("fib2", "fib1", "fib0", "+"));
	REQUIRE(func.Fn("fib3", "fib2", "fib1", "+"));
	REQUIRE(func.Fn("fib4", "fib3", "fib2", "+"));
	REQUIRE(func.Fn("fib5", "fib4", "fib3", "+"));
	REQUIRE(func.Fn("fib6", "fib5", "fib4", "+"));
	REQUIRE(func.get("fib0", varib) == 0);
	REQUIRE(func.get("fib1", varib) == 1);
	REQUIRE(func.get("fib2", varib) == 1);
	REQUIRE(func.get("fib3", varib) == 2);
	REQUIRE(func.get("fib4", varib) == 3);
	REQUIRE(func.get("fib5", varib) == 5);
	REQUIRE(func.get("fib6", varib) == 8);
}
