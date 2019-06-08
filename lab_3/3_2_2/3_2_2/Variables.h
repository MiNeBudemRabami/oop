#pragma once

#include <string>
#include <map>

class Functions;

class Variables
{
public:

	Variables();
	~Variables();

	bool var(std::string variable, Functions &fn);

	bool let1(std::string variable1, double variable2, Functions &fn);

	bool let2(std::string variable1, std::string variable2, Functions &fn);

	bool printvars()const;

	bool find(std::string variable) const;

	double get(std::string variable) const;

	bool print(std::string variable) const;

private:

	std::map <std::string, double> setVariables;
};

