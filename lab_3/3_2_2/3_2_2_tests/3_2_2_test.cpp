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
