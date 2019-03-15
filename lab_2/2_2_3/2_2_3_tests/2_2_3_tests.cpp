// 2_2_3_tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "../2_2_3/2_2_3.h"
#include <sstream>

using namespace std;

bool check(string SearchString, string ReplaceString, string in, string out)
{
	istringstream is(in);
	ostringstream os;
	replace(SearchString, ReplaceString, is, os);
	return os.str() == out;
}

TEST_CASE("", "[single-file]") {
	REQUIRE(check("def", "ghi", "abcdefghidef", "abcghighighi"));
	REQUIRE(check("x", "y", "abcdefghidef", "abcdefghidef"));
	REQUIRE(check("x", "y", "", ""));
	REQUIRE(check("aaa", "bbb", "aaa", "bbb"));
}
