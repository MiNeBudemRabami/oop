#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_2_2\variableClass.h"
#include "..\3_2_2\functionClass.h"

TEST_CASE("var", "[single-file]")
{
	variableClass varib;
	functionClass func;
	REQUIRE(varib.var("a", func) == true);
}

TEST_CASE("let before var with same variable", "[single-file]")
{
	variableClass varib;
	functionClass func;
	varib.let1("a", 2, func);
	REQUIRE(varib.var("a", func) == false);
}

TEST_CASE("let variable get value from anotrher variable, first is undeclared", "[single-file]")
{
	variableClass varib;
	functionClass func;
	varib.let1("b", 1, func);
	REQUIRE(varib.let2("a", "b", func) == true);
}

TEST_CASE("let variable get value from anotrher variable, bots are undeclared", "[single-file]")
{
	variableClass varib;
	functionClass func;
	REQUIRE(varib.let2("a", "b", func) == false);
}

TEST_CASE("fib", "[single-file]")
{
	variableClass varib;
	functionClass func;
	REQUIRE(varib.let1("v0", 0, func));
	REQUIRE(varib.let1("v1", 1, func));
	REQUIRE(func.fn2("fib0", "v0"));
	REQUIRE(func.fn2("fib1", "v1"));
	REQUIRE(func.fn3("fib2", "fib1", "fib0", "+"));
	REQUIRE(func.fn3("fib3", "fib2", "fib1", "+"));
	REQUIRE(func.fn3("fib4", "fib3", "fib2", "+"));
	REQUIRE(func.fn3("fib5", "fib4", "fib3", "+"));
	REQUIRE(func.fn3("fib6", "fib5", "fib4", "+"));
	REQUIRE(func.get("fib0", varib) == 0);
	REQUIRE(func.get("fib1", varib) == 1);
	REQUIRE(func.get("fib2", varib) == 1);
	REQUIRE(func.get("fib3", varib) == 2);
	REQUIRE(func.get("fib4", varib) == 3);
	REQUIRE(func.get("fib5", varib) == 5);
	REQUIRE(func.get("fib6", varib) == 8);
}
