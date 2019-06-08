#pragma once

#include <string>
#include <map>

class Functions;

class Variables
{
public:

	Variables();
	~Variables();

	bool var(std::string const& variable, Functions &fn);

	bool Let(std::string const& variable1, double variable2, Functions &fn);

	bool Let(std::string const& variable1, std::string const& variable2, Functions &fn);

	bool find(std::string const& variable) const;

	double get(std::string const& variable) const;

	std::map <std::string, double> const& GetAllData() const;

private:

	std::map <std::string, double> setVariables;
};

