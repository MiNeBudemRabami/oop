#pragma once

#include <string>
#include <map>

class Functions;
class Calculator;

class Variables
{
public:

	Variables();
	~Variables();

	bool Var(std::string const& variable, Functions &fn);

	bool Let(std::string const& variable1, double variable2, Functions &fn);

	bool Let(std::string const& variable1, std::string const& variable2, Functions &fn, Calculator &calc);

	bool Find(std::string const& variable) const;

	double Get(std::string const& variable) const;

	std::map <std::string, double> const& GetAllData() const;

private:

	std::map <std::string, double> m_setVariables;
};

