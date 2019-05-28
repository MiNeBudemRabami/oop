#pragma once

#include <string>
#include <map>

class variableClass
{
public:

	variableClass();
	~variableClass();

	bool var(std::string variable);

	void let2(std::string variable1, double variable2);

	bool let1(std::string variable1, std::string variable2);

	void printvars()const;

	bool find(std::string variable);

	void print(std::string variable);

private:

	std::map <std::string, double> setVariables;
};

