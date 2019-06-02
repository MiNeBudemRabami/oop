#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\4_1_2\CircleClass.h"

TEST_CASE("1", "[single-file]")
{
	PointClass center;
	center.x = 10;
	center.y = 5;
	CircleClass c(center, 10, 111111, 111111);
	REQUIRE(c.getArea() == Approx(314.159));
	
}
