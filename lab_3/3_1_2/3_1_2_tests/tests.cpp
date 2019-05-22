#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_1_2\carClass.h"

TEST_CASE("can turn on", "[single-file]")
{
	carClass c;
	REQUIRE(c.turnOnEngine() == carClass::success);
}

TEST_CASE("cant turn on twice", "[single-file]")
{
	carClass c;
	REQUIRE(c.turnOnEngine() == carClass::success);
	REQUIRE(c.turnOnEngine() == carClass::error);
}

TEST_CASE("can set speed", "[single-file]")
{
	carClass c;
	REQUIRE(c.turnOnEngine() == carClass::success);
	REQUIRE(c.SetGear(1) == carClass::success);
	REQUIRE(c.SetSpeed(20) == carClass::success);
}

TEST_CASE("cant set speed", "[single-file]")
{
	carClass c;
	REQUIRE(c.turnOnEngine() == carClass::success);
	REQUIRE(c.SetGear(1) == carClass::success);
	REQUIRE(c.SetSpeed(100) == carClass::error);
}
