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

	bool Let(std::string variable1, double variable2, Functions &fn);

	bool Let(std::string variable1, std::string variable2, Functions &fn);

	bool find(std::string variable) const;

	double get(std::string variable) const;

	std::map <std::string, double> const& GetAllData() const;

private:

	std::map <std::string, double> setVariables;
};

