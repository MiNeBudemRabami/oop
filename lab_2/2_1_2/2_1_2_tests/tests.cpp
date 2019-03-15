#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\2_1_2\2_1_2.h"

TEST_CASE("", "[single-file]") {
	REQUIRE(findMin({ 1,2,3 }) == 1);
	REQUIRE(findMin({ -1,-2,-3 }) == -3);

	REQUIRE(massiveProccessing({2,3,4}) == std::vector<float>({4,6,8}));

	REQUIRE(massiveSort({5,1,4,2,3}) == std::vector<float>({ 1,2,3,4,5 }));
}
