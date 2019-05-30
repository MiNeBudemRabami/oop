#pragma once

#include <string>
#include <map>

class functionClass;

class variableClass
{
public:

	variableClass();
	~variableClass();

	bool var(std::string variable, functionClass &fn);

	bool let1(std::string variable1, double variable2, functionClass &fn);

	bool let2(std::string variable1, std::string variable2, functionClass &fn);

	bool printvars()const;

	bool find(std::string variable);

	double get(std::string variable);

	bool print(std::string variable);

private:

	std::map <std::string, double> setVariables;
};

