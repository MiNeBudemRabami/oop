#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_2_2\variableClass.h"
#include "..\3_2_2\functionClass.h"

TEST_CASE("var", "[single-file]")
{
	variableClass test;
	REQUIRE(test.var("a") == true);
}

TEST_CASE("let before var with same variable", "[single-file]")
{
	variableClass test;
	test.let2("a", 2);
	REQUIRE(test.var("a") == false);
}

TEST_CASE("let variable get value from anotrher variable, first is undeclared", "[single-file]")
{
	variableClass test;
	test.let2("b", 1);
	REQUIRE(test.let1("a", "b") == true);
}

TEST_CASE("let variable get value from anotrher variable, bots are undeclared", "[single-file]")
{
	variableClass test;
	REQUIRE(test.let1("a", "b") == false);
}