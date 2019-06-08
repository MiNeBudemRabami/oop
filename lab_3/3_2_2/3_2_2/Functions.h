#pragma once

#include <string>
#include <map>
#include <vector>

class Calculator;

class Functions
{
public:

	Functions();
	~Functions();

	bool Fn(std::string const& function, std::string const& variable1, std::string const& variable2, std::string const& operation);

	bool Fn(std::string const& function, std::string const& variable1);

	bool Find(std::string const& function) const;

	double Get(std::string const& function, Calculator const& calc) const;

	std::map<std::string, double> GetAllData(Calculator const& calc) const;

private:

	std::map <std::string, std::vector<std::string>> m_setFunctions;
};


