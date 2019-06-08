#pragma once

#include "Variables.h"
#include "Functions.h"

class Calculator
{
public:
	Calculator();

	bool Var(std::string const& variable);
	bool Let(std::string const& variable1, double variable2);
	bool Let(std::string const& variable1, std::string const& variable2);
	bool Find(std::string const& anyName) const;
	double Get(std::string const& anyName) const;
	bool Fn(std::string const& function, std::string const& variable1);
	bool Fn(std::string const& function, std::string const& variable1, std::string const& variable2, std::string const& operation);
	std::map <std::string, double> const& GetAllVariables() const;
	std::map <std::string, double> GetAllFunctions() const;

private:
	Variables m_variables;
	Functions m_functions;
};
